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
CMAKE_SOURCE_DIR = /mnt/hgfs/zhouqian/log/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/zhouqian/log/build

# Include any dependencies generated for this target.
include CMakeFiles/log_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/log_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/log_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/log_lib.dir/flags.make

CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o: CMakeFiles/log_lib.dir/flags.make
CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o: /mnt/hgfs/zhouqian/log/src/log.c
CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o: CMakeFiles/log_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/zhouqian/log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o -MF CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o.d -o CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o -c /mnt/hgfs/zhouqian/log/src/log.c

CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/zhouqian/log/src/log.c > CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.i

CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/zhouqian/log/src/log.c -o CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.s

CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o: CMakeFiles/log_lib.dir/flags.make
CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o: /mnt/hgfs/zhouqian/log/src/log_utils.c
CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o: CMakeFiles/log_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/zhouqian/log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o -MF CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o.d -o CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o -c /mnt/hgfs/zhouqian/log/src/log_utils.c

CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/hgfs/zhouqian/log/src/log_utils.c > CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.i

CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/hgfs/zhouqian/log/src/log_utils.c -o CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.s

# Object files for target log_lib
log_lib_OBJECTS = \
"CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o" \
"CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o"

# External object files for target log_lib
log_lib_EXTERNAL_OBJECTS =

liblog_lib.a: CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log.c.o
liblog_lib.a: CMakeFiles/log_lib.dir/mnt/hgfs/zhouqian/log/src/log_utils.c.o
liblog_lib.a: CMakeFiles/log_lib.dir/build.make
liblog_lib.a: CMakeFiles/log_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/zhouqian/log/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library liblog_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/log_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/log_lib.dir/build: liblog_lib.a
.PHONY : CMakeFiles/log_lib.dir/build

CMakeFiles/log_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/log_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/log_lib.dir/clean

CMakeFiles/log_lib.dir/depend:
	cd /mnt/hgfs/zhouqian/log/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/zhouqian/log/test /mnt/hgfs/zhouqian/log/test /mnt/hgfs/zhouqian/log/build /mnt/hgfs/zhouqian/log/build /mnt/hgfs/zhouqian/log/build/CMakeFiles/log_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/log_lib.dir/depend

