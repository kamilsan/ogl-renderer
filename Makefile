# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/kamil/Pulpit/ogl-renderer (kopia)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kamil/Pulpit/ogl-renderer (kopia)"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/kamil/Pulpit/ogl-renderer (kopia)/CMakeFiles" "/home/kamil/Pulpit/ogl-renderer (kopia)/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/kamil/Pulpit/ogl-renderer (kopia)/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named renderer

# Build rule for target.
renderer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 renderer
.PHONY : renderer

# fast build rule for target.
renderer/fast:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/build
.PHONY : renderer/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/main.cpp.s
.PHONY : main.cpp.s

shaderProgram.o: shaderProgram.cpp.o

.PHONY : shaderProgram.o

# target to build an object file
shaderProgram.cpp.o:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/shaderProgram.cpp.o
.PHONY : shaderProgram.cpp.o

shaderProgram.i: shaderProgram.cpp.i

.PHONY : shaderProgram.i

# target to preprocess a source file
shaderProgram.cpp.i:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/shaderProgram.cpp.i
.PHONY : shaderProgram.cpp.i

shaderProgram.s: shaderProgram.cpp.s

.PHONY : shaderProgram.s

# target to generate assembly for a file
shaderProgram.cpp.s:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/shaderProgram.cpp.s
.PHONY : shaderProgram.cpp.s

src/glad.o: src/glad.c.o

.PHONY : src/glad.o

# target to build an object file
src/glad.c.o:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/src/glad.c.o
.PHONY : src/glad.c.o

src/glad.i: src/glad.c.i

.PHONY : src/glad.i

# target to preprocess a source file
src/glad.c.i:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/src/glad.c.i
.PHONY : src/glad.c.i

src/glad.s: src/glad.c.s

.PHONY : src/glad.s

# target to generate assembly for a file
src/glad.c.s:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/src/glad.c.s
.PHONY : src/glad.c.s

window.o: window.cpp.o

.PHONY : window.o

# target to build an object file
window.cpp.o:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/window.cpp.o
.PHONY : window.cpp.o

window.i: window.cpp.i

.PHONY : window.i

# target to preprocess a source file
window.cpp.i:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/window.cpp.i
.PHONY : window.cpp.i

window.s: window.cpp.s

.PHONY : window.s

# target to generate assembly for a file
window.cpp.s:
	$(MAKE) -f CMakeFiles/renderer.dir/build.make CMakeFiles/renderer.dir/window.cpp.s
.PHONY : window.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... renderer"
	@echo "... edit_cache"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... shaderProgram.o"
	@echo "... shaderProgram.i"
	@echo "... shaderProgram.s"
	@echo "... src/glad.o"
	@echo "... src/glad.i"
	@echo "... src/glad.s"
	@echo "... window.o"
	@echo "... window.i"
	@echo "... window.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

