# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build

# Include any dependencies generated for this target.
include CMakeFiles/get_matching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/get_matching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/get_matching.dir/flags.make

CMakeFiles/get_matching.dir/get_matching.cpp.o: CMakeFiles/get_matching.dir/flags.make
CMakeFiles/get_matching.dir/get_matching.cpp.o: ../get_matching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/get_matching.dir/get_matching.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/get_matching.dir/get_matching.cpp.o -c /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/get_matching.cpp

CMakeFiles/get_matching.dir/get_matching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/get_matching.dir/get_matching.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/get_matching.cpp > CMakeFiles/get_matching.dir/get_matching.cpp.i

CMakeFiles/get_matching.dir/get_matching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/get_matching.dir/get_matching.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/get_matching.cpp -o CMakeFiles/get_matching.dir/get_matching.cpp.s

# Object files for target get_matching
get_matching_OBJECTS = \
"CMakeFiles/get_matching.dir/get_matching.cpp.o"

# External object files for target get_matching
get_matching_EXTERNAL_OBJECTS =

libget_matching.a: CMakeFiles/get_matching.dir/get_matching.cpp.o
libget_matching.a: CMakeFiles/get_matching.dir/build.make
libget_matching.a: CMakeFiles/get_matching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libget_matching.a"
	$(CMAKE_COMMAND) -P CMakeFiles/get_matching.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/get_matching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/get_matching.dir/build: libget_matching.a

.PHONY : CMakeFiles/get_matching.dir/build

CMakeFiles/get_matching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/get_matching.dir/cmake_clean.cmake
.PHONY : CMakeFiles/get_matching.dir/clean

CMakeFiles/get_matching.dir/depend:
	cd /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build /home/kirillbogatiy/Documents/Hypergamy-in-Matching-Markets/build/CMakeFiles/get_matching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/get_matching.dir/depend

