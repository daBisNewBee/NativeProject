# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/CLionProjects/NativeProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/CLionProjects/NativeProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NativeProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NativeProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NativeProject.dir/flags.make

CMakeFiles/NativeProject.dir/main.c.o: CMakeFiles/NativeProject.dir/flags.make
CMakeFiles/NativeProject.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/CLionProjects/NativeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/NativeProject.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/NativeProject.dir/main.c.o   -c /Users/user/CLionProjects/NativeProject/main.c

CMakeFiles/NativeProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/NativeProject.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/CLionProjects/NativeProject/main.c > CMakeFiles/NativeProject.dir/main.c.i

CMakeFiles/NativeProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/NativeProject.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/CLionProjects/NativeProject/main.c -o CMakeFiles/NativeProject.dir/main.c.s

CMakeFiles/NativeProject.dir/main.c.o.requires:

.PHONY : CMakeFiles/NativeProject.dir/main.c.o.requires

CMakeFiles/NativeProject.dir/main.c.o.provides: CMakeFiles/NativeProject.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/NativeProject.dir/build.make CMakeFiles/NativeProject.dir/main.c.o.provides.build
.PHONY : CMakeFiles/NativeProject.dir/main.c.o.provides

CMakeFiles/NativeProject.dir/main.c.o.provides.build: CMakeFiles/NativeProject.dir/main.c.o


# Object files for target NativeProject
NativeProject_OBJECTS = \
"CMakeFiles/NativeProject.dir/main.c.o"

# External object files for target NativeProject
NativeProject_EXTERNAL_OBJECTS =

NativeProject: CMakeFiles/NativeProject.dir/main.c.o
NativeProject: CMakeFiles/NativeProject.dir/build.make
NativeProject: ../output/libskf.dylib
NativeProject: CMakeFiles/NativeProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/user/CLionProjects/NativeProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable NativeProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NativeProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NativeProject.dir/build: NativeProject

.PHONY : CMakeFiles/NativeProject.dir/build

CMakeFiles/NativeProject.dir/requires: CMakeFiles/NativeProject.dir/main.c.o.requires

.PHONY : CMakeFiles/NativeProject.dir/requires

CMakeFiles/NativeProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NativeProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NativeProject.dir/clean

CMakeFiles/NativeProject.dir/depend:
	cd /Users/user/CLionProjects/NativeProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/CLionProjects/NativeProject /Users/user/CLionProjects/NativeProject /Users/user/CLionProjects/NativeProject/cmake-build-debug /Users/user/CLionProjects/NativeProject/cmake-build-debug /Users/user/CLionProjects/NativeProject/cmake-build-debug/CMakeFiles/NativeProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NativeProject.dir/depend

