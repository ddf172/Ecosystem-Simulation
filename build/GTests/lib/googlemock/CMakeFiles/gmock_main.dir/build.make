# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build

# Include any dependencies generated for this target.
include GTests/lib/googlemock/CMakeFiles/gmock_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include GTests/lib/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.make

# Include the progress variables for this target.
include GTests/lib/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include GTests/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make

GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: GTests/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make
GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: GTests/lib/googlemock/CMakeFiles/gmock_main.dir/includes_CXX.rsp
GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: C:/Users/franc/OneDrive/Desktop/OOP/ProjectCPP/Ecosystem-Simulation/GTests/lib/googlemock/src/gmock_main.cc
GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: GTests/lib/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj"
	cd /d C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj -MF CMakeFiles\gmock_main.dir\src\gmock_main.cc.obj.d -o CMakeFiles\gmock_main.dir\src\gmock_main.cc.obj -c C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\GTests\lib\googlemock\src\gmock_main.cc

GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /d C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\GTests\lib\googlemock\src\gmock_main.cc > CMakeFiles\gmock_main.dir\src\gmock_main.cc.i

GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /d C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\GTests\lib\googlemock\src\gmock_main.cc -o CMakeFiles\gmock_main.dir\src\gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.a: GTests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj
lib/libgmock_main.a: GTests/lib/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.a: GTests/lib/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\lib\libgmock_main.a"
	cd /d C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock_main.dir\cmake_clean_target.cmake
	cd /d C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GTests/lib/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.a
.PHONY : GTests/lib/googlemock/CMakeFiles/gmock_main.dir/build

GTests/lib/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /d C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock_main.dir\cmake_clean.cmake
.PHONY : GTests/lib/googlemock/CMakeFiles/gmock_main.dir/clean

GTests/lib/googlemock/CMakeFiles/gmock_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\GTests\lib\googlemock C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock C:\Users\franc\OneDrive\Desktop\OOP\ProjectCPP\Ecosystem-Simulation\build\GTests\lib\googlemock\CMakeFiles\gmock_main.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : GTests/lib/googlemock/CMakeFiles/gmock_main.dir/depend

