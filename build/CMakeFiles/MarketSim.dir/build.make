# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Landorus\Desktop\market-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Landorus\Desktop\market-sim\build

# Include any dependencies generated for this target.
include CMakeFiles/MarketSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MarketSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MarketSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarketSim.dir/flags.make

MarketSim_autogen/timestamp: C:/Qt/6.8.2/mingw_64/bin/moc.exe
MarketSim_autogen/timestamp: CMakeFiles/MarketSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MarketSim"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen C:/Users/Landorus/Desktop/market-sim/build/CMakeFiles/MarketSim_autogen.dir/AutogenInfo.json ""
	"C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/Landorus/Desktop/market-sim/build/MarketSim_autogen/timestamp

MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/resources.qrc
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: CMakeFiles/MarketSim_autogen.dir/AutoRcc_resources_EWIEGA46WW_Info.json
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/Main.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/SidePanel.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/CustomMenuBar.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/MainWindow.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/UntitledProject5/EventListSimulator.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/UntitledProject5/EventListModel.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/UntitledProject5/qmldir
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Users/Landorus/Desktop/market-sim/qml/UntitledProject5/Constants.qml
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Qt/6.8.2/mingw_64/bin/rcc.exe
MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp: C:/Qt/6.8.2/mingw_64/bin/rcc.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for resources.qrc"
	"C:\Program Files\CMake\bin\cmake.exe" -E cmake_autorcc C:/Users/Landorus/Desktop/market-sim/build/CMakeFiles/MarketSim_autogen.dir/AutoRcc_resources_EWIEGA46WW_Info.json 

CMakeFiles/MarketSim.dir/codegen:
.PHONY : CMakeFiles/MarketSim.dir/codegen

CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj: CMakeFiles/MarketSim.dir/flags.make
CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj: CMakeFiles/MarketSim.dir/includes_CXX.rsp
CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj: MarketSim_autogen/mocs_compilation.cpp
CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj: CMakeFiles/MarketSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\MarketSim.dir\MarketSim_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\MarketSim.dir\MarketSim_autogen\mocs_compilation.cpp.obj -c C:\Users\Landorus\Desktop\market-sim\build\MarketSim_autogen\mocs_compilation.cpp

CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Landorus\Desktop\market-sim\build\MarketSim_autogen\mocs_compilation.cpp > CMakeFiles\MarketSim.dir\MarketSim_autogen\mocs_compilation.cpp.i

CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Landorus\Desktop\market-sim\build\MarketSim_autogen\mocs_compilation.cpp -o CMakeFiles\MarketSim.dir\MarketSim_autogen\mocs_compilation.cpp.s

CMakeFiles/MarketSim.dir/src/main.cpp.obj: CMakeFiles/MarketSim.dir/flags.make
CMakeFiles/MarketSim.dir/src/main.cpp.obj: CMakeFiles/MarketSim.dir/includes_CXX.rsp
CMakeFiles/MarketSim.dir/src/main.cpp.obj: C:/Users/Landorus/Desktop/market-sim/src/main.cpp
CMakeFiles/MarketSim.dir/src/main.cpp.obj: CMakeFiles/MarketSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MarketSim.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarketSim.dir/src/main.cpp.obj -MF CMakeFiles\MarketSim.dir\src\main.cpp.obj.d -o CMakeFiles\MarketSim.dir\src\main.cpp.obj -c C:\Users\Landorus\Desktop\market-sim\src\main.cpp

CMakeFiles/MarketSim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarketSim.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Landorus\Desktop\market-sim\src\main.cpp > CMakeFiles\MarketSim.dir\src\main.cpp.i

CMakeFiles/MarketSim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarketSim.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Landorus\Desktop\market-sim\src\main.cpp -o CMakeFiles\MarketSim.dir\src\main.cpp.s

CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj: CMakeFiles/MarketSim.dir/flags.make
CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj: CMakeFiles/MarketSim.dir/includes_CXX.rsp
CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj: C:/Users/Landorus/Desktop/market-sim/src/DataFetcher.cpp
CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj: CMakeFiles/MarketSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj -MF CMakeFiles\MarketSim.dir\src\DataFetcher.cpp.obj.d -o CMakeFiles\MarketSim.dir\src\DataFetcher.cpp.obj -c C:\Users\Landorus\Desktop\market-sim\src\DataFetcher.cpp

CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Landorus\Desktop\market-sim\src\DataFetcher.cpp > CMakeFiles\MarketSim.dir\src\DataFetcher.cpp.i

CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Landorus\Desktop\market-sim\src\DataFetcher.cpp -o CMakeFiles\MarketSim.dir\src\DataFetcher.cpp.s

CMakeFiles/MarketSim.dir/src/api.cpp.obj: CMakeFiles/MarketSim.dir/flags.make
CMakeFiles/MarketSim.dir/src/api.cpp.obj: CMakeFiles/MarketSim.dir/includes_CXX.rsp
CMakeFiles/MarketSim.dir/src/api.cpp.obj: C:/Users/Landorus/Desktop/market-sim/src/api.cpp
CMakeFiles/MarketSim.dir/src/api.cpp.obj: CMakeFiles/MarketSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MarketSim.dir/src/api.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarketSim.dir/src/api.cpp.obj -MF CMakeFiles\MarketSim.dir\src\api.cpp.obj.d -o CMakeFiles\MarketSim.dir\src\api.cpp.obj -c C:\Users\Landorus\Desktop\market-sim\src\api.cpp

CMakeFiles/MarketSim.dir/src/api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarketSim.dir/src/api.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Landorus\Desktop\market-sim\src\api.cpp > CMakeFiles\MarketSim.dir\src\api.cpp.i

CMakeFiles/MarketSim.dir/src/api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarketSim.dir/src/api.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Landorus\Desktop\market-sim\src\api.cpp -o CMakeFiles\MarketSim.dir\src\api.cpp.s

CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj: CMakeFiles/MarketSim.dir/flags.make
CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj: CMakeFiles/MarketSim.dir/includes_CXX.rsp
CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj: MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp
CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj: CMakeFiles/MarketSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj -MF CMakeFiles\MarketSim.dir\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp.obj.d -o CMakeFiles\MarketSim.dir\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp.obj -c C:\Users\Landorus\Desktop\market-sim\build\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp

CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Landorus\Desktop\market-sim\build\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp > CMakeFiles\MarketSim.dir\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp.i

CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Landorus\Desktop\market-sim\build\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp -o CMakeFiles\MarketSim.dir\MarketSim_autogen\EWIEGA46WW\qrc_resources.cpp.s

# Object files for target MarketSim
MarketSim_OBJECTS = \
"CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/MarketSim.dir/src/main.cpp.obj" \
"CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj" \
"CMakeFiles/MarketSim.dir/src/api.cpp.obj" \
"CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj"

# External object files for target MarketSim
MarketSim_EXTERNAL_OBJECTS =

MarketSim.exe: CMakeFiles/MarketSim.dir/MarketSim_autogen/mocs_compilation.cpp.obj
MarketSim.exe: CMakeFiles/MarketSim.dir/src/main.cpp.obj
MarketSim.exe: CMakeFiles/MarketSim.dir/src/DataFetcher.cpp.obj
MarketSim.exe: CMakeFiles/MarketSim.dir/src/api.cpp.obj
MarketSim.exe: CMakeFiles/MarketSim.dir/MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp.obj
MarketSim.exe: CMakeFiles/MarketSim.dir/build.make
MarketSim.exe: C:/Qt/6.8.2/mingw_64/lib/libQt6Gui.a
MarketSim.exe: C:/Qt/6.8.2/mingw_64/lib/libQt6Qml.a
MarketSim.exe: C:/msys64/mingw64/lib/libcurl.dll.a
MarketSim.exe: C:/Qt/6.8.2/mingw_64/lib/libQt6Network.a
MarketSim.exe: C:/Qt/6.8.2/mingw_64/lib/libQt6Core.a
MarketSim.exe: CMakeFiles/MarketSim.dir/linkLibs.rsp
MarketSim.exe: CMakeFiles/MarketSim.dir/objects1.rsp
MarketSim.exe: CMakeFiles/MarketSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable MarketSim.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MarketSim.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarketSim.dir/build: MarketSim.exe
.PHONY : CMakeFiles/MarketSim.dir/build

CMakeFiles/MarketSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MarketSim.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MarketSim.dir/clean

CMakeFiles/MarketSim.dir/depend: MarketSim_autogen/EWIEGA46WW/qrc_resources.cpp
CMakeFiles/MarketSim.dir/depend: MarketSim_autogen/timestamp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Landorus\Desktop\market-sim C:\Users\Landorus\Desktop\market-sim C:\Users\Landorus\Desktop\market-sim\build C:\Users\Landorus\Desktop\market-sim\build C:\Users\Landorus\Desktop\market-sim\build\CMakeFiles\MarketSim.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MarketSim.dir/depend

