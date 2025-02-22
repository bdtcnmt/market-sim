cmake_minimum_required(VERSION 3.10)
project(MarketSim)

# Specify the C++ standard (C++17 in this example)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories for project headers and third-party libraries
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/nlohmann_json
    ${CMAKE_SOURCE_DIR}/external/libcurl/include
)

# Collect source files (add more as your project grows)
set(SOURCES
    src/main.cpp
    src/api.cpp
    src/display.cpp
)

# Create the executable from the source files
add_executable(MarketSim ${SOURCES})

# Link external libraries
# Assuming you have built or downloaded libcurl as a static library (.a or .lib)
target_link_libraries(MarketSim
    "C:/msys64/mingw64/lib/libcurl.dll.a"
)

# If you're on Windows, you may need to link additional system libraries.
if(WIN32)
    target_link_libraries(MarketSim ws2_32)
endif()