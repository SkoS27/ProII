# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Carmelo\Documents\proII\P2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.c.obj: ../main.c
CMakeFiles/main.dir/main.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/main.c.obj"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/main.c.obj -MF CMakeFiles\main.dir\main.c.obj.d -o CMakeFiles\main.dir\main.c.obj -c C:\Users\Carmelo\Documents\proII\P2\main.c

CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Carmelo\Documents\proII\P2\main.c > CMakeFiles\main.dir\main.c.i

CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Carmelo\Documents\proII\P2\main.c -o CMakeFiles\main.dir\main.c.s

CMakeFiles/main.dir/product_list.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/product_list.c.obj: ../product_list.c
CMakeFiles/main.dir/product_list.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/product_list.c.obj"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/product_list.c.obj -MF CMakeFiles\main.dir\product_list.c.obj.d -o CMakeFiles\main.dir\product_list.c.obj -c C:\Users\Carmelo\Documents\proII\P2\product_list.c

CMakeFiles/main.dir/product_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/product_list.c.i"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Carmelo\Documents\proII\P2\product_list.c > CMakeFiles\main.dir\product_list.c.i

CMakeFiles/main.dir/product_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/product_list.c.s"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Carmelo\Documents\proII\P2\product_list.c -o CMakeFiles\main.dir\product_list.c.s

CMakeFiles/main.dir/bid_stack.c.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/bid_stack.c.obj: ../bid_stack.c
CMakeFiles/main.dir/bid_stack.c.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/bid_stack.c.obj"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/bid_stack.c.obj -MF CMakeFiles\main.dir\bid_stack.c.obj.d -o CMakeFiles\main.dir\bid_stack.c.obj -c C:\Users\Carmelo\Documents\proII\P2\bid_stack.c

CMakeFiles/main.dir/bid_stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/bid_stack.c.i"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Carmelo\Documents\proII\P2\bid_stack.c > CMakeFiles\main.dir\bid_stack.c.i

CMakeFiles/main.dir/bid_stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/bid_stack.c.s"
	C:\Users\Carmelo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Carmelo\Documents\proII\P2\bid_stack.c -o CMakeFiles\main.dir\bid_stack.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.obj" \
"CMakeFiles/main.dir/product_list.c.obj" \
"CMakeFiles/main.dir/bid_stack.c.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

../bin/main.exe: CMakeFiles/main.dir/main.c.obj
../bin/main.exe: CMakeFiles/main.dir/product_list.c.obj
../bin/main.exe: CMakeFiles/main.dir/bid_stack.c.obj
../bin/main.exe: CMakeFiles/main.dir/build.make
../bin/main.exe: CMakeFiles/main.dir/linklibs.rsp
../bin/main.exe: CMakeFiles/main.dir/objects1.rsp
../bin/main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ..\bin\main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: ../bin/main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Carmelo\Documents\proII\P2 C:\Users\Carmelo\Documents\proII\P2 C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug C:\Users\Carmelo\Documents\proII\P2\cmake-build-debug\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
