# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Users/wescande/.brew/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /Users/wescande/.brew/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wescande/Documents/corewar/allegro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wescande/Documents/corewar/allegro/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/ex_blend_bench.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ex_blend_bench.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ex_blend_bench.dir/flags.make

examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o: examples/CMakeFiles/ex_blend_bench.dir/flags.make
examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o: ../examples/ex_blend_bench.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wescande/Documents/corewar/allegro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o"
	cd /Users/wescande/Documents/corewar/allegro/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o   -c /Users/wescande/Documents/corewar/allegro/examples/ex_blend_bench.c

examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.i"
	cd /Users/wescande/Documents/corewar/allegro/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wescande/Documents/corewar/allegro/examples/ex_blend_bench.c > CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.i

examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.s"
	cd /Users/wescande/Documents/corewar/allegro/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wescande/Documents/corewar/allegro/examples/ex_blend_bench.c -o CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.s

examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.requires:

.PHONY : examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.requires

examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.provides: examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.requires
	$(MAKE) -f examples/CMakeFiles/ex_blend_bench.dir/build.make examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.provides.build
.PHONY : examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.provides

examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.provides.build: examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o


# Object files for target ex_blend_bench
ex_blend_bench_OBJECTS = \
"CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o"

# External object files for target ex_blend_bench
ex_blend_bench_EXTERNAL_OBJECTS =

examples/ex_blend_bench: examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o
examples/ex_blend_bench: examples/CMakeFiles/ex_blend_bench.dir/build.make
examples/ex_blend_bench: lib/liballegro_main.5.2.2.dylib
examples/ex_blend_bench: lib/liballegro_image.5.2.2.dylib
examples/ex_blend_bench: lib/liballegro_primitives.5.2.2.dylib
examples/ex_blend_bench: lib/liballegro_dialog.5.2.2.dylib
examples/ex_blend_bench: lib/liballegro.5.2.2.dylib
examples/ex_blend_bench: examples/CMakeFiles/ex_blend_bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wescande/Documents/corewar/allegro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ex_blend_bench"
	cd /Users/wescande/Documents/corewar/allegro/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_blend_bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ex_blend_bench.dir/build: examples/ex_blend_bench

.PHONY : examples/CMakeFiles/ex_blend_bench.dir/build

examples/CMakeFiles/ex_blend_bench.dir/requires: examples/CMakeFiles/ex_blend_bench.dir/ex_blend_bench.c.o.requires

.PHONY : examples/CMakeFiles/ex_blend_bench.dir/requires

examples/CMakeFiles/ex_blend_bench.dir/clean:
	cd /Users/wescande/Documents/corewar/allegro/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/ex_blend_bench.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ex_blend_bench.dir/clean

examples/CMakeFiles/ex_blend_bench.dir/depend:
	cd /Users/wescande/Documents/corewar/allegro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wescande/Documents/corewar/allegro /Users/wescande/Documents/corewar/allegro/examples /Users/wescande/Documents/corewar/allegro/build /Users/wescande/Documents/corewar/allegro/build/examples /Users/wescande/Documents/corewar/allegro/build/examples/CMakeFiles/ex_blend_bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ex_blend_bench.dir/depend

