# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cache-_s/rendu/allegro/allegro-5.0.11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cache-_s/rendu/allegro/allegro-5.0.11/Build

# Utility rule file for run_tests_d3d.

# Include the progress variables for this target.
include tests/CMakeFiles/run_tests_d3d.dir/progress.make

tests/CMakeFiles/run_tests_d3d: tests/test_driver
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/tests && ./test_driver --force-d3d /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_bitmaps.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_bitmaps2.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_blend.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_locking.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_locking2.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_backbuffer.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_image.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_fonts.ini /home/cache-_s/rendu/allegro/allegro-5.0.11/tests/test_prim.ini

run_tests_d3d: tests/CMakeFiles/run_tests_d3d
run_tests_d3d: tests/CMakeFiles/run_tests_d3d.dir/build.make
.PHONY : run_tests_d3d

# Rule to build all files generated by this target.
tests/CMakeFiles/run_tests_d3d.dir/build: run_tests_d3d
.PHONY : tests/CMakeFiles/run_tests_d3d.dir/build

tests/CMakeFiles/run_tests_d3d.dir/clean:
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/tests && $(CMAKE_COMMAND) -P CMakeFiles/run_tests_d3d.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/run_tests_d3d.dir/clean

tests/CMakeFiles/run_tests_d3d.dir/depend:
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cache-_s/rendu/allegro/allegro-5.0.11 /home/cache-_s/rendu/allegro/allegro-5.0.11/tests /home/cache-_s/rendu/allegro/allegro-5.0.11/Build /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/tests /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/tests/CMakeFiles/run_tests_d3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/run_tests_d3d.dir/depend

