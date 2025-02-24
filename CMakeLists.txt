cmake_minimum_required(VERSION 3.10)
project(MarketSim)

# Specify the C++ standard required for the project.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add directories where the compiler should look for header files.
include_directories(
    ${CMAKE_SOURCE_DIR}/include                          # Your project-specific headers.
    ${CMAKE_SOURCE_DIR}/external/nlohmann_json/include     # The nlohmann JSON header.
    C:/msys64/mingw64/include                              # Headers provided by your MSYS2 MinGW toolchain (including libcurl headers).
)

# List all source files that make up your project.
set(SOURCES
    src/main.cpp
    src/api.cpp
    src/display.cpp
)

# Define an executable target. This tells CMake to compile these source files into an executable named StockSimulator.
add_executable(MarketSim ${SOURCES})

# Link external libraries required by your project.
# In this case, we link against the libcurl import library from MSYS2.
target_link_libraries(MarketSim
    "C:/msys64/ucrt64/lib/libcurl.dll.a"  # The import library for dynamic linking of libcurl.
    ws2_32                                  # Windows Sockets library needed for network operations.
)

# (Optional) You can add additional linking for other system libraries if needed.