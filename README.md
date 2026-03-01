# CPong

A simple implementation of the classic game Pong in C++, built using the [raylib](https://www.raylib.com/) library.

## Features
- Classic 1v1 Pong gameplay.
- AI-controlled paddle (CPU) support.
- Modern C++ implementation (C++20).
- Cross-platform support (Windows, macOS, Linux).

## Project Structure
- `src/`: Contains the source code for the game logic, entities (ball, paddle, cpu_paddle), and main entry point.
- `src/include/`: Header files for the game's components.
- `vendor/`: Contains third-party dependencies, currently featuring a pre-compiled version of raylib for macOS.

## Building and Running
This project uses CMake as its build system.

### Prerequisites
- A C++ compiler supporting C++20.
- [CMake](https://cmake.org/download/) 3.31 or higher.

### Build Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/sir-geronimo/cpong.git
   cd cpong
   ```
2. Create a build directory and configure the project:
   ```bash
   mkdir build && cd build
   cmake ..
   ```
3. Build the executable:
   ```bash
   cmake --build .
   ```
4. Run the game:
   ```bash
   ./CPong
   ```

## Dependencies
- **raylib**: This project automatically fetches and builds raylib version 5.5 from source using CMake's `FetchContent`. No manual installation of raylib is required.

## License
This project is licensed under the [GNU GPLv3 License](LICENSE).
