# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\TPSIT\PUNTATORI\ES_000

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\TPSIT\PUNTATORI\ES_000\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ES_000.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ES_000.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ES_000.dir/flags.make

CMakeFiles/ES_000.dir/main.c.obj: CMakeFiles/ES_000.dir/flags.make
CMakeFiles/ES_000.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\TPSIT\PUNTATORI\ES_000\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ES_000.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ES_000.dir\main.c.obj   -c F:\TPSIT\PUNTATORI\ES_000\main.c

CMakeFiles/ES_000.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ES_000.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\TPSIT\PUNTATORI\ES_000\main.c > CMakeFiles\ES_000.dir\main.c.i

CMakeFiles/ES_000.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ES_000.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\TPSIT\PUNTATORI\ES_000\main.c -o CMakeFiles\ES_000.dir\main.c.s

# Object files for target ES_000
ES_000_OBJECTS = \
"CMakeFiles/ES_000.dir/main.c.obj"

# External object files for target ES_000
ES_000_EXTERNAL_OBJECTS =

ES_000.exe: CMakeFiles/ES_000.dir/main.c.obj
ES_000.exe: CMakeFiles/ES_000.dir/build.make
ES_000.exe: CMakeFiles/ES_000.dir/linklibs.rsp
ES_000.exe: CMakeFiles/ES_000.dir/objects1.rsp
ES_000.exe: CMakeFiles/ES_000.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\TPSIT\PUNTATORI\ES_000\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ES_000.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ES_000.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ES_000.dir/build: ES_000.exe

.PHONY : CMakeFiles/ES_000.dir/build

CMakeFiles/ES_000.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ES_000.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ES_000.dir/clean

CMakeFiles/ES_000.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\TPSIT\PUNTATORI\ES_000 F:\TPSIT\PUNTATORI\ES_000 F:\TPSIT\PUNTATORI\ES_000\cmake-build-debug F:\TPSIT\PUNTATORI\ES_000\cmake-build-debug F:\TPSIT\PUNTATORI\ES_000\cmake-build-debug\CMakeFiles\ES_000.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ES_000.dir/depend

