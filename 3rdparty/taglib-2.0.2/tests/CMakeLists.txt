INCLUDE_DIRECTORIES(
        ../taglib
        ../taglib/toolkit
        ../bindings/c
        ../taglib/ape
        ../taglib/asf
        ../taglib/mpeg/id3v1
        ../taglib/mpeg/id3v2
        ../taglib/mpeg/id3v2/frames
        ../taglib/mpeg
        ../taglib/mpc
        ../taglib/mp4
        ../taglib/riff
        ../taglib/riff/aiff
        ../taglib/riff/wav
        ../taglib/trueaudio
        ../taglib/ogg
        ../taglib/ogg/vorbis
        ../taglib/ogg/flac
        ../taglib/ogg/speex
        ../taglib/ogg/opus
        ../taglib/flac
        ../taglib/wavpack
        ../taglib/mod
        ../taglib/s3m
        ../taglib/it
        ../taglib/xm
        ../taglib/dsf
        ../taglib/dsdiff
)

SET(test_runner_SRCS
        main.cpp
        test_list.cpp
        test_map.cpp
        test_mpeg.cpp
        test_synchdata.cpp
        test_trueaudio.cpp
        test_bytevector.cpp
        test_bytevectorlist.cpp
        test_bytevectorstream.cpp
        test_string.cpp
        test_propertymap.cpp
        test_variant.cpp
        test_complexproperties.cpp
        test_file.cpp
        test_fileref.cpp
        test_id3v1.cpp
        test_id3v2.cpp
        test_id3v2framefactory.cpp
        test_xiphcomment.cpp
        test_aiff.cpp
        test_riff.cpp
        test_ogg.cpp
        test_oggflac.cpp
        test_flac.cpp
        test_flacpicture.cpp
        test_flacunknownmetadatablock.cpp
        test_ape.cpp
        test_apetag.cpp
        test_wav.cpp
        test_info.cpp
        test_wavpack.cpp
        test_mp4.cpp
        test_mp4item.cpp
        test_mp4coverart.cpp
        test_asf.cpp
        test_mod.cpp
        test_s3m.cpp
        test_it.cpp
        test_xm.cpp
        test_mpc.cpp
        test_opus.cpp
        test_speex.cpp
        test_dsf.cpp
        test_dsdiff.cpp
        test_sizes.cpp
        test_versionnumber.cpp
)
IF(BUILD_BINDINGS)
  SET(test_runner_SRCS ${test_runner_SRCS}
          test_tag_c.cpp
  )
ENDIF()

INCLUDE_DIRECTORIES(${CPPUNIT_INCLUDE_DIR})

ADD_EXECUTABLE(test_runner ${test_runner_SRCS})
TARGET_LINK_LIBRARIES(test_runner tag ${CPPUNIT_LIBRARIES})
IF(BUILD_BINDINGS)
  TARGET_LINK_LIBRARIES(test_runner tag_c)
ENDIF()

ADD_TEST(test_runner test_runner)
ADD_CUSTOM_TARGET(check COMMAND ${CMAKE_CTEST_COMMAND} -V
                  DEPENDS test_runner)
