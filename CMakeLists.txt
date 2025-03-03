cmake_minimum_required(VERSION 3.10)
project(MarketSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt's automatic processing.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64")

# Find Qt modules required.
find_package(Qt6 REQUIRED COMPONENTS Gui Qml)

# Include directories (adjust paths as needed).
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/nlohmann_json/include
    C:/msys64/mingw64/include
    C:/Qt/6.8.2/mingw_64/include
)

# List source files.
set(SOURCES
    src/main.cpp
    ${CMAKE_SOURCE_DIR}/include/DataFetcher.h
    src/DataFetcher.cpp
    src/api.cpp
    # src/display.cpp
    resources.qrc
)

add_executable(MarketSim ${SOURCES})

target_link_libraries(MarketSim
    Qt6::Gui 
    Qt6::Qml 
    "C:/msys64/mingw64/lib/libcurl.dll.a" 
    ws2_32
)