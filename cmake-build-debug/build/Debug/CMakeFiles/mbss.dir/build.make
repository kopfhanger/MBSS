# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kopfhanger/cpp_pro/mbss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug

# Include any dependencies generated for this target.
include CMakeFiles/mbss.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mbss.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mbss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mbss.dir/flags.make

CMakeFiles/mbss.dir/main.cpp.o: CMakeFiles/mbss.dir/flags.make
CMakeFiles/mbss.dir/main.cpp.o: /home/kopfhanger/cpp_pro/mbss/main.cpp
CMakeFiles/mbss.dir/main.cpp.o: CMakeFiles/mbss.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mbss.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mbss.dir/main.cpp.o -MF CMakeFiles/mbss.dir/main.cpp.o.d -o CMakeFiles/mbss.dir/main.cpp.o -c /home/kopfhanger/cpp_pro/mbss/main.cpp

CMakeFiles/mbss.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mbss.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kopfhanger/cpp_pro/mbss/main.cpp > CMakeFiles/mbss.dir/main.cpp.i

CMakeFiles/mbss.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mbss.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kopfhanger/cpp_pro/mbss/main.cpp -o CMakeFiles/mbss.dir/main.cpp.s

# Object files for target mbss
mbss_OBJECTS = \
"CMakeFiles/mbss.dir/main.cpp.o"

# External object files for target mbss
mbss_EXTERNAL_OBJECTS =

mbss: CMakeFiles/mbss.dir/main.cpp.o
mbss: CMakeFiles/mbss.dir/build.make
mbss: CMakeFiles/mbss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mbss"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mbss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mbss.dir/build: mbss
.PHONY : CMakeFiles/mbss.dir/build

CMakeFiles/mbss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mbss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mbss.dir/clean

CMakeFiles/mbss.dir/depend:
	cd /home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kopfhanger/cpp_pro/mbss /home/kopfhanger/cpp_pro/mbss /home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug /home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug /home/kopfhanger/cpp_pro/mbss/cmake-build-debug/build/Debug/CMakeFiles/mbss.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mbss.dir/depend

