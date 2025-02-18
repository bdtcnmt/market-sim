cmake_minimum_required(VERSION 3.16)
project(MarketSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Tell CMake where to find the Qt6 configuration files.
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")

# Find necessary Qt6 modules.
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

# Automatically collect all .cpp and .h files.
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/include/*.h"
)

# Create the executable with all source files.
add_executable(market_sim ${SOURCES})

# Add include directories.
target_include_directories(market_sim PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link against the required Qt6 modules.
target_link_libraries(market_sim Qt6::Widgets Qt6::Network)
