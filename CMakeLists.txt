cmake_minimum_required(VERSION 3.16)
project(MarketSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Tell CMake where to find the Qt6 configuration files.
# This directory typically contains subdirectories like Qt6Core, Qt6Gui, Qt6Widgets, etc.
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")

# Find the Qt6 Widgets module
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add your executable target
add_executable(market_sim
    src/main.cpp
    src/MainWindow.cpp
    src/MarketSimulator.cpp
    src/MathUtils.cpp
    include/MainWindow.h
)

target_include_directories(market_sim PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link the Qt6 Widgets library to your target
target_link_libraries(market_sim Qt6::Widgets)