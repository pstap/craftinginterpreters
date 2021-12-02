# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/peter/src/craftinginterpreters

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peter/src/craftinginterpreters

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/peter/src/craftinginterpreters/CMakeFiles /home/peter/src/craftinginterpreters//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/peter/src/craftinginterpreters/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named i

# Build rule for target.
i : cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 i
.PHONY : i

# fast build rule for target.
i/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/build
.PHONY : i/fast

lox.o: lox.cpp.o
.PHONY : lox.o

# target to build an object file
lox.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/lox.cpp.o
.PHONY : lox.cpp.o

lox.i: lox.cpp.i
.PHONY : lox.i

# target to preprocess a source file
lox.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/lox.cpp.i
.PHONY : lox.cpp.i

lox.s: lox.cpp.s
.PHONY : lox.s

# target to generate assembly for a file
lox.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/lox.cpp.s
.PHONY : lox.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/main.cpp.s
.PHONY : main.cpp.s

scanner.o: scanner.cpp.o
.PHONY : scanner.o

# target to build an object file
scanner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/scanner.cpp.o
.PHONY : scanner.cpp.o

scanner.i: scanner.cpp.i
.PHONY : scanner.i

# target to preprocess a source file
scanner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/scanner.cpp.i
.PHONY : scanner.cpp.i

scanner.s: scanner.cpp.s
.PHONY : scanner.s

# target to generate assembly for a file
scanner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/scanner.cpp.s
.PHONY : scanner.cpp.s

token.o: token.cpp.o
.PHONY : token.o

# target to build an object file
token.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/token.cpp.o
.PHONY : token.cpp.o

token.i: token.cpp.i
.PHONY : token.i

# target to preprocess a source file
token.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/token.cpp.i
.PHONY : token.cpp.i

token.s: token.cpp.s
.PHONY : token.s

# target to generate assembly for a file
token.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/i.dir/build.make CMakeFiles/i.dir/token.cpp.s
.PHONY : token.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... i"
	@echo "... lox.o"
	@echo "... lox.i"
	@echo "... lox.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... scanner.o"
	@echo "... scanner.i"
	@echo "... scanner.s"
	@echo "... token.o"
	@echo "... token.i"
	@echo "... token.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
