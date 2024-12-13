cmake_minimum_required(VERSION 3.16)

project(eda-mp3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets LinguistTools Multimedia)


## Add the path to the TagLib source code
#set(TAGLIB_DIR "${CMAKE_SOURCE_DIR}/3rdpartyLibs/taglib-2.0.2")
#add_subdirectory(
#        ${TAGLIB_DIR}
#)

set(TS_FILES eda-mp3_en_US.ts)

set(PROJECT_SOURCES
        main.cpp
        ${TS_FILES}

        src/backend/player.cpp
        src/backend/player.h
        src/backend/libraryManager.cpp
        src/backend/libraryManager.h
        src/backend/song.cpp
        src/backend/song.h
        src/backend/queueManager.cpp
        src/backend/queueManager.h
        src/backend/playlistManager.cpp
        src/backend/playlistManager.h
        src/backend/playlist.h

        src/frontend/mainwindow.cpp
        src/frontend/mainwindow.h
        src/frontend/mainwindow.ui
        src/frontend/controls.cpp
        src/frontend/controls.h
        src/frontend/controls.ui
        src/frontend/library.cpp
        src/frontend/library.h
        src/frontend/library.ui
        src/frontend/playlists.cpp
        src/frontend/playlists.h
        src/frontend/playlists.ui
        src/frontend/queue.cpp
        src/frontend/queue.h
        src/frontend/queue.ui
        src/frontend/librarysong.cpp
        src/frontend/librarysong.h
        src/frontend/librarysong.ui
        src/frontend/queuesong.cpp
        src/frontend/queuesong.h
        src/frontend/queuesong.ui
        src/frontend/createplaylistdialog.cpp
        src/frontend/createplaylistdialog.h
        src/frontend/createplaylistdialog.ui
        src/frontend/playlistinlist.cpp
        src/frontend/playlistinlist.h
        src/frontend/playlistinlist.ui
        src/frontend/addtoplaylistdialog.cpp
        src/frontend/addtoplaylistdialog.h
        src/frontend/addtoplaylistdialog.ui
        src/frontend/addtoplaylist.cpp
        src/frontend/addtoplaylist.h
        src/frontend/addtoplaylist.ui
        src/frontend/editor.cpp
        src/frontend/editor.h
        src/frontend/editor.ui
        src/frontend/editorsong.cpp
        src/frontend/editorsong.h
        src/frontend/editorsong.ui
        src/frontend/switcher.cpp
        src/frontend/switcher.h
        src/frontend/switcher.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(eda-mp3
        MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            resources/resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET eda-mp3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(eda-mp3 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(eda-mp3
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()


target_link_libraries(eda-mp3
        PRIVATE Qt${QT_VERSION_MAJOR}::Core
        PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
        PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.eda-mp3)
endif()
set_target_properties(eda-mp3 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE

    # TODO might have to turn this on some time later, but for now it should be off so console output is visible on windows
    WIN32_EXECUTABLE OFF
)

include(GNUInstallDirs)
install(TARGETS eda-mp3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(eda-mp3)
endif()
