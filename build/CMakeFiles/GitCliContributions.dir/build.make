# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/petemango/Documents/CLI Git Contributions"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/petemango/Documents/CLI Git Contributions/build"

# Include any dependencies generated for this target.
include CMakeFiles/GitCliContributions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GitCliContributions.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GitCliContributions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GitCliContributions.dir/flags.make

CMakeFiles/GitCliContributions.dir/scan.cpp.o: CMakeFiles/GitCliContributions.dir/flags.make
CMakeFiles/GitCliContributions.dir/scan.cpp.o: /Users/petemango/Documents/CLI\ Git\ Contributions/scan.cpp
CMakeFiles/GitCliContributions.dir/scan.cpp.o: CMakeFiles/GitCliContributions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/petemango/Documents/CLI Git Contributions/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GitCliContributions.dir/scan.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GitCliContributions.dir/scan.cpp.o -MF CMakeFiles/GitCliContributions.dir/scan.cpp.o.d -o CMakeFiles/GitCliContributions.dir/scan.cpp.o -c "/Users/petemango/Documents/CLI Git Contributions/scan.cpp"

CMakeFiles/GitCliContributions.dir/scan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GitCliContributions.dir/scan.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/petemango/Documents/CLI Git Contributions/scan.cpp" > CMakeFiles/GitCliContributions.dir/scan.cpp.i

CMakeFiles/GitCliContributions.dir/scan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GitCliContributions.dir/scan.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/petemango/Documents/CLI Git Contributions/scan.cpp" -o CMakeFiles/GitCliContributions.dir/scan.cpp.s

# Object files for target GitCliContributions
GitCliContributions_OBJECTS = \
"CMakeFiles/GitCliContributions.dir/scan.cpp.o"

# External object files for target GitCliContributions
GitCliContributions_EXTERNAL_OBJECTS =

GitCliContributions: CMakeFiles/GitCliContributions.dir/scan.cpp.o
GitCliContributions: CMakeFiles/GitCliContributions.dir/build.make
GitCliContributions: /opt/homebrew/lib/libgit2.dylib
GitCliContributions: CMakeFiles/GitCliContributions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/petemango/Documents/CLI Git Contributions/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GitCliContributions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GitCliContributions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GitCliContributions.dir/build: GitCliContributions
.PHONY : CMakeFiles/GitCliContributions.dir/build

CMakeFiles/GitCliContributions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GitCliContributions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GitCliContributions.dir/clean

CMakeFiles/GitCliContributions.dir/depend:
	cd "/Users/petemango/Documents/CLI Git Contributions/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/petemango/Documents/CLI Git Contributions" "/Users/petemango/Documents/CLI Git Contributions" "/Users/petemango/Documents/CLI Git Contributions/build" "/Users/petemango/Documents/CLI Git Contributions/build" "/Users/petemango/Documents/CLI Git Contributions/build/CMakeFiles/GitCliContributions.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/GitCliContributions.dir/depend
