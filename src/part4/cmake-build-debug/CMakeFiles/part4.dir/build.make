# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Git/5LIG0_AS1/src/part4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/part4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/part4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/part4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/part4.dir/flags.make

CMakeFiles/part4.dir/src/dijkstra.cpp.o: CMakeFiles/part4.dir/flags.make
CMakeFiles/part4.dir/src/dijkstra.cpp.o: ../src/dijkstra.cpp
CMakeFiles/part4.dir/src/dijkstra.cpp.o: CMakeFiles/part4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/part4.dir/src/dijkstra.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/part4.dir/src/dijkstra.cpp.o -MF CMakeFiles/part4.dir/src/dijkstra.cpp.o.d -o CMakeFiles/part4.dir/src/dijkstra.cpp.o -c /mnt/c/Git/5LIG0_AS1/src/part4/src/dijkstra.cpp

CMakeFiles/part4.dir/src/dijkstra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part4.dir/src/dijkstra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Git/5LIG0_AS1/src/part4/src/dijkstra.cpp > CMakeFiles/part4.dir/src/dijkstra.cpp.i

CMakeFiles/part4.dir/src/dijkstra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part4.dir/src/dijkstra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Git/5LIG0_AS1/src/part4/src/dijkstra.cpp -o CMakeFiles/part4.dir/src/dijkstra.cpp.s

CMakeFiles/part4.dir/src/graph.cpp.o: CMakeFiles/part4.dir/flags.make
CMakeFiles/part4.dir/src/graph.cpp.o: ../src/graph.cpp
CMakeFiles/part4.dir/src/graph.cpp.o: CMakeFiles/part4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/part4.dir/src/graph.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/part4.dir/src/graph.cpp.o -MF CMakeFiles/part4.dir/src/graph.cpp.o.d -o CMakeFiles/part4.dir/src/graph.cpp.o -c /mnt/c/Git/5LIG0_AS1/src/part4/src/graph.cpp

CMakeFiles/part4.dir/src/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part4.dir/src/graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Git/5LIG0_AS1/src/part4/src/graph.cpp > CMakeFiles/part4.dir/src/graph.cpp.i

CMakeFiles/part4.dir/src/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part4.dir/src/graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Git/5LIG0_AS1/src/part4/src/graph.cpp -o CMakeFiles/part4.dir/src/graph.cpp.s

CMakeFiles/part4.dir/src/main.cpp.o: CMakeFiles/part4.dir/flags.make
CMakeFiles/part4.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/part4.dir/src/main.cpp.o: CMakeFiles/part4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/part4.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/part4.dir/src/main.cpp.o -MF CMakeFiles/part4.dir/src/main.cpp.o.d -o CMakeFiles/part4.dir/src/main.cpp.o -c /mnt/c/Git/5LIG0_AS1/src/part4/src/main.cpp

CMakeFiles/part4.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part4.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Git/5LIG0_AS1/src/part4/src/main.cpp > CMakeFiles/part4.dir/src/main.cpp.i

CMakeFiles/part4.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part4.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Git/5LIG0_AS1/src/part4/src/main.cpp -o CMakeFiles/part4.dir/src/main.cpp.s

CMakeFiles/part4.dir/src/mission.cpp.o: CMakeFiles/part4.dir/flags.make
CMakeFiles/part4.dir/src/mission.cpp.o: ../src/mission.cpp
CMakeFiles/part4.dir/src/mission.cpp.o: CMakeFiles/part4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/part4.dir/src/mission.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/part4.dir/src/mission.cpp.o -MF CMakeFiles/part4.dir/src/mission.cpp.o.d -o CMakeFiles/part4.dir/src/mission.cpp.o -c /mnt/c/Git/5LIG0_AS1/src/part4/src/mission.cpp

CMakeFiles/part4.dir/src/mission.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part4.dir/src/mission.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Git/5LIG0_AS1/src/part4/src/mission.cpp > CMakeFiles/part4.dir/src/mission.cpp.i

CMakeFiles/part4.dir/src/mission.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part4.dir/src/mission.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Git/5LIG0_AS1/src/part4/src/mission.cpp -o CMakeFiles/part4.dir/src/mission.cpp.s

CMakeFiles/part4.dir/src/siteconfiguration.cpp.o: CMakeFiles/part4.dir/flags.make
CMakeFiles/part4.dir/src/siteconfiguration.cpp.o: ../src/siteconfiguration.cpp
CMakeFiles/part4.dir/src/siteconfiguration.cpp.o: CMakeFiles/part4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/part4.dir/src/siteconfiguration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/part4.dir/src/siteconfiguration.cpp.o -MF CMakeFiles/part4.dir/src/siteconfiguration.cpp.o.d -o CMakeFiles/part4.dir/src/siteconfiguration.cpp.o -c /mnt/c/Git/5LIG0_AS1/src/part4/src/siteconfiguration.cpp

CMakeFiles/part4.dir/src/siteconfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part4.dir/src/siteconfiguration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Git/5LIG0_AS1/src/part4/src/siteconfiguration.cpp > CMakeFiles/part4.dir/src/siteconfiguration.cpp.i

CMakeFiles/part4.dir/src/siteconfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part4.dir/src/siteconfiguration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Git/5LIG0_AS1/src/part4/src/siteconfiguration.cpp -o CMakeFiles/part4.dir/src/siteconfiguration.cpp.s

# Object files for target part4
part4_OBJECTS = \
"CMakeFiles/part4.dir/src/dijkstra.cpp.o" \
"CMakeFiles/part4.dir/src/graph.cpp.o" \
"CMakeFiles/part4.dir/src/main.cpp.o" \
"CMakeFiles/part4.dir/src/mission.cpp.o" \
"CMakeFiles/part4.dir/src/siteconfiguration.cpp.o"

# External object files for target part4
part4_EXTERNAL_OBJECTS =

part4: CMakeFiles/part4.dir/src/dijkstra.cpp.o
part4: CMakeFiles/part4.dir/src/graph.cpp.o
part4: CMakeFiles/part4.dir/src/main.cpp.o
part4: CMakeFiles/part4.dir/src/mission.cpp.o
part4: CMakeFiles/part4.dir/src/siteconfiguration.cpp.o
part4: CMakeFiles/part4.dir/build.make
part4: CMakeFiles/part4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable part4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/part4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/part4.dir/build: part4
.PHONY : CMakeFiles/part4.dir/build

CMakeFiles/part4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/part4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/part4.dir/clean

CMakeFiles/part4.dir/depend:
	cd /mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Git/5LIG0_AS1/src/part4 /mnt/c/Git/5LIG0_AS1/src/part4 /mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug /mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug /mnt/c/Git/5LIG0_AS1/src/part4/cmake-build-debug/CMakeFiles/part4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/part4.dir/depend

