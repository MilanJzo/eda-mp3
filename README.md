# EDA-MP3

A simple GUI based MP3-player. Built with Qt6 and C++. This has been created as part of the EDA module within the media technology course at the Technological University of Cologne.

**Please note that this project is by no means professional!**

## Features

- yt-dlp integration
- Play MP3 files
- Queue MP3 files
- Create playlists
- Edit playlists
- Simple and intuitive GUI

## Requirements

- Qt6
- C++17 or later
- CMake

## Installation

0. Install the required dependencies:
    Qt6-Core, Qt6-Gui, Qt6-Widgets, Qt6-Multimedia

1. Install optional dependencies:
    yt-dlp (for downloading MP3 files from YouTube), ffmpeg (recommended by yt-dlp) and ffprobe (recommended by yt-dlp)

2. Clone the repository:
    ```sh
    git clone https://github.com/MilanJzo/eda-mp3.git
    cd eda-mp3
    ```

3. Build the project:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

4. Run the application:
    ```sh
    ./EDA-MP3
    ```

## Usage

- Open the application and use the GUI to load and play MP3 files.
- Edit playlists by selecting the playlist and using the provided editor.

## Contributing

No contributions are accepted at this time. Thanks for your interest!

## License

We are currently considering what license to use.