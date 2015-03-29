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

# Include any dependencies generated for this target.
include addons/memfile/CMakeFiles/allegro_memfile.dir/depend.make

# Include the progress variables for this target.
include addons/memfile/CMakeFiles/allegro_memfile.dir/progress.make

# Include the compile flags for this target's objects.
include addons/memfile/CMakeFiles/allegro_memfile.dir/flags.make

lib/Headers/allegro5/allegro_memfile.h: ../addons/memfile/allegro5/allegro_memfile.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content lib/Headers/allegro5/allegro_memfile.h"
	$(CMAKE_COMMAND) -E copy /home/cache-_s/rendu/allegro/allegro-5.0.11/addons/memfile/allegro5/allegro_memfile.h lib/Headers/allegro5/allegro_memfile.h

addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o: addons/memfile/CMakeFiles/allegro_memfile.dir/flags.make
addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o: ../addons/memfile/memfile.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o"
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_MEMFILE_SRC  -DALLEGRO_LIB_BUILD -o CMakeFiles/allegro_memfile.dir/memfile.c.o   -c /home/cache-_s/rendu/allegro/allegro-5.0.11/addons/memfile/memfile.c

addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_memfile.dir/memfile.c.i"
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_MEMFILE_SRC  -DALLEGRO_LIB_BUILD -E /home/cache-_s/rendu/allegro/allegro-5.0.11/addons/memfile/memfile.c > CMakeFiles/allegro_memfile.dir/memfile.c.i

addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_memfile.dir/memfile.c.s"
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_MEMFILE_SRC  -DALLEGRO_LIB_BUILD -S /home/cache-_s/rendu/allegro/allegro-5.0.11/addons/memfile/memfile.c -o CMakeFiles/allegro_memfile.dir/memfile.c.s

addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.requires:
.PHONY : addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.requires

addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.provides: addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.requires
	$(MAKE) -f addons/memfile/CMakeFiles/allegro_memfile.dir/build.make addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.provides.build
.PHONY : addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.provides

addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.provides.build: addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o

# Object files for target allegro_memfile
allegro_memfile_OBJECTS = \
"CMakeFiles/allegro_memfile.dir/memfile.c.o"

# External object files for target allegro_memfile
allegro_memfile_EXTERNAL_OBJECTS =

lib/liballegro_memfile.so.5.0.11: addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o
lib/liballegro_memfile.so.5.0.11: addons/memfile/CMakeFiles/allegro_memfile.dir/build.make
lib/liballegro_memfile.so.5.0.11: lib/liballegro.so.5.0.11
lib/liballegro_memfile.so.5.0.11: /usr/lib64/libSM.so
lib/liballegro_memfile.so.5.0.11: /usr/lib64/libICE.so
lib/liballegro_memfile.so.5.0.11: /usr/lib64/libX11.so
lib/liballegro_memfile.so.5.0.11: /usr/lib64/libXext.so
lib/liballegro_memfile.so.5.0.11: /usr/lib64/libGL.so
lib/liballegro_memfile.so.5.0.11: /usr/lib64/libGLU.so
lib/liballegro_memfile.so.5.0.11: addons/memfile/CMakeFiles/allegro_memfile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../../lib/liballegro_memfile.so"
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_memfile.dir/link.txt --verbose=$(VERBOSE)
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liballegro_memfile.so.5.0.11 ../../lib/liballegro_memfile.so.5.0 ../../lib/liballegro_memfile.so

lib/liballegro_memfile.so.5.0: lib/liballegro_memfile.so.5.0.11

lib/liballegro_memfile.so: lib/liballegro_memfile.so.5.0.11

# Rule to build all files generated by this target.
addons/memfile/CMakeFiles/allegro_memfile.dir/build: lib/liballegro_memfile.so
addons/memfile/CMakeFiles/allegro_memfile.dir/build: lib/Headers/allegro5/allegro_memfile.h
.PHONY : addons/memfile/CMakeFiles/allegro_memfile.dir/build

addons/memfile/CMakeFiles/allegro_memfile.dir/requires: addons/memfile/CMakeFiles/allegro_memfile.dir/memfile.c.o.requires
.PHONY : addons/memfile/CMakeFiles/allegro_memfile.dir/requires

addons/memfile/CMakeFiles/allegro_memfile.dir/clean:
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile && $(CMAKE_COMMAND) -P CMakeFiles/allegro_memfile.dir/cmake_clean.cmake
.PHONY : addons/memfile/CMakeFiles/allegro_memfile.dir/clean

addons/memfile/CMakeFiles/allegro_memfile.dir/depend:
	cd /home/cache-_s/rendu/allegro/allegro-5.0.11/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cache-_s/rendu/allegro/allegro-5.0.11 /home/cache-_s/rendu/allegro/allegro-5.0.11/addons/memfile /home/cache-_s/rendu/allegro/allegro-5.0.11/Build /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile /home/cache-_s/rendu/allegro/allegro-5.0.11/Build/addons/memfile/CMakeFiles/allegro_memfile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : addons/memfile/CMakeFiles/allegro_memfile.dir/depend

