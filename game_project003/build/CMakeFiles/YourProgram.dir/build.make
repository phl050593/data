# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\data\game_project003

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\data\game_project003\build

# Include any dependencies generated for this target.
include CMakeFiles/YourProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/YourProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/YourProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YourProgram.dir/flags.make

CMakeFiles/YourProgram.dir/src/clean.c.obj: CMakeFiles/YourProgram.dir/flags.make
CMakeFiles/YourProgram.dir/src/clean.c.obj: CMakeFiles/YourProgram.dir/includes_C.rsp
CMakeFiles/YourProgram.dir/src/clean.c.obj: C:/data/game_project003/src/clean.c
CMakeFiles/YourProgram.dir/src/clean.c.obj: CMakeFiles/YourProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/YourProgram.dir/src/clean.c.obj"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/YourProgram.dir/src/clean.c.obj -MF CMakeFiles\YourProgram.dir\src\clean.c.obj.d -o CMakeFiles\YourProgram.dir\src\clean.c.obj -c C:\data\game_project003\src\clean.c

CMakeFiles/YourProgram.dir/src/clean.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/YourProgram.dir/src/clean.c.i"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\data\game_project003\src\clean.c > CMakeFiles\YourProgram.dir\src\clean.c.i

CMakeFiles/YourProgram.dir/src/clean.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/YourProgram.dir/src/clean.c.s"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\data\game_project003\src\clean.c -o CMakeFiles\YourProgram.dir\src\clean.c.s

CMakeFiles/YourProgram.dir/src/drawing.c.obj: CMakeFiles/YourProgram.dir/flags.make
CMakeFiles/YourProgram.dir/src/drawing.c.obj: CMakeFiles/YourProgram.dir/includes_C.rsp
CMakeFiles/YourProgram.dir/src/drawing.c.obj: C:/data/game_project003/src/drawing.c
CMakeFiles/YourProgram.dir/src/drawing.c.obj: CMakeFiles/YourProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/YourProgram.dir/src/drawing.c.obj"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/YourProgram.dir/src/drawing.c.obj -MF CMakeFiles\YourProgram.dir\src\drawing.c.obj.d -o CMakeFiles\YourProgram.dir\src\drawing.c.obj -c C:\data\game_project003\src\drawing.c

CMakeFiles/YourProgram.dir/src/drawing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/YourProgram.dir/src/drawing.c.i"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\data\game_project003\src\drawing.c > CMakeFiles\YourProgram.dir\src\drawing.c.i

CMakeFiles/YourProgram.dir/src/drawing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/YourProgram.dir/src/drawing.c.s"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\data\game_project003\src\drawing.c -o CMakeFiles\YourProgram.dir\src\drawing.c.s

CMakeFiles/YourProgram.dir/src/initialization.c.obj: CMakeFiles/YourProgram.dir/flags.make
CMakeFiles/YourProgram.dir/src/initialization.c.obj: CMakeFiles/YourProgram.dir/includes_C.rsp
CMakeFiles/YourProgram.dir/src/initialization.c.obj: C:/data/game_project003/src/initialization.c
CMakeFiles/YourProgram.dir/src/initialization.c.obj: CMakeFiles/YourProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/YourProgram.dir/src/initialization.c.obj"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/YourProgram.dir/src/initialization.c.obj -MF CMakeFiles\YourProgram.dir\src\initialization.c.obj.d -o CMakeFiles\YourProgram.dir\src\initialization.c.obj -c C:\data\game_project003\src\initialization.c

CMakeFiles/YourProgram.dir/src/initialization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/YourProgram.dir/src/initialization.c.i"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\data\game_project003\src\initialization.c > CMakeFiles\YourProgram.dir\src\initialization.c.i

CMakeFiles/YourProgram.dir/src/initialization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/YourProgram.dir/src/initialization.c.s"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\data\game_project003\src\initialization.c -o CMakeFiles\YourProgram.dir\src\initialization.c.s

CMakeFiles/YourProgram.dir/src/main.c.obj: CMakeFiles/YourProgram.dir/flags.make
CMakeFiles/YourProgram.dir/src/main.c.obj: CMakeFiles/YourProgram.dir/includes_C.rsp
CMakeFiles/YourProgram.dir/src/main.c.obj: C:/data/game_project003/src/main.c
CMakeFiles/YourProgram.dir/src/main.c.obj: CMakeFiles/YourProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/YourProgram.dir/src/main.c.obj"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/YourProgram.dir/src/main.c.obj -MF CMakeFiles\YourProgram.dir\src\main.c.obj.d -o CMakeFiles\YourProgram.dir\src\main.c.obj -c C:\data\game_project003\src\main.c

CMakeFiles/YourProgram.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/YourProgram.dir/src/main.c.i"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\data\game_project003\src\main.c > CMakeFiles\YourProgram.dir\src\main.c.i

CMakeFiles/YourProgram.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/YourProgram.dir/src/main.c.s"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\data\game_project003\src\main.c -o CMakeFiles\YourProgram.dir\src\main.c.s

CMakeFiles/YourProgram.dir/src/score.c.obj: CMakeFiles/YourProgram.dir/flags.make
CMakeFiles/YourProgram.dir/src/score.c.obj: CMakeFiles/YourProgram.dir/includes_C.rsp
CMakeFiles/YourProgram.dir/src/score.c.obj: C:/data/game_project003/src/score.c
CMakeFiles/YourProgram.dir/src/score.c.obj: CMakeFiles/YourProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/YourProgram.dir/src/score.c.obj"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/YourProgram.dir/src/score.c.obj -MF CMakeFiles\YourProgram.dir\src\score.c.obj.d -o CMakeFiles\YourProgram.dir\src\score.c.obj -c C:\data\game_project003\src\score.c

CMakeFiles/YourProgram.dir/src/score.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/YourProgram.dir/src/score.c.i"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\data\game_project003\src\score.c > CMakeFiles\YourProgram.dir\src\score.c.i

CMakeFiles/YourProgram.dir/src/score.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/YourProgram.dir/src/score.c.s"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\data\game_project003\src\score.c -o CMakeFiles\YourProgram.dir\src\score.c.s

CMakeFiles/YourProgram.dir/src/updating.c.obj: CMakeFiles/YourProgram.dir/flags.make
CMakeFiles/YourProgram.dir/src/updating.c.obj: CMakeFiles/YourProgram.dir/includes_C.rsp
CMakeFiles/YourProgram.dir/src/updating.c.obj: C:/data/game_project003/src/updating.c
CMakeFiles/YourProgram.dir/src/updating.c.obj: CMakeFiles/YourProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/YourProgram.dir/src/updating.c.obj"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/YourProgram.dir/src/updating.c.obj -MF CMakeFiles\YourProgram.dir\src\updating.c.obj.d -o CMakeFiles\YourProgram.dir\src\updating.c.obj -c C:\data\game_project003\src\updating.c

CMakeFiles/YourProgram.dir/src/updating.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/YourProgram.dir/src/updating.c.i"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\data\game_project003\src\updating.c > CMakeFiles\YourProgram.dir\src\updating.c.i

CMakeFiles/YourProgram.dir/src/updating.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/YourProgram.dir/src/updating.c.s"
	C:\llvm-mingw-20231114-msvcrt-x86_64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\data\game_project003\src\updating.c -o CMakeFiles\YourProgram.dir\src\updating.c.s

# Object files for target YourProgram
YourProgram_OBJECTS = \
"CMakeFiles/YourProgram.dir/src/clean.c.obj" \
"CMakeFiles/YourProgram.dir/src/drawing.c.obj" \
"CMakeFiles/YourProgram.dir/src/initialization.c.obj" \
"CMakeFiles/YourProgram.dir/src/main.c.obj" \
"CMakeFiles/YourProgram.dir/src/score.c.obj" \
"CMakeFiles/YourProgram.dir/src/updating.c.obj"

# External object files for target YourProgram
YourProgram_EXTERNAL_OBJECTS =

C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/src/clean.c.obj
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/src/drawing.c.obj
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/src/initialization.c.obj
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/src/main.c.obj
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/src/score.c.obj
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/src/updating.c.obj
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/build.make
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_primitives.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_image.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_audio.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_acodec.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_font.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_ttf.dll.a
C:/data/game_project003/YourProgram.exe: D:/AllegroLib_5.2.8/lib/liballegro_dialog.dll.a
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/linkLibs.rsp
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/objects1.rsp
C:/data/game_project003/YourProgram.exe: CMakeFiles/YourProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\data\game_project003\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable C:\data\game_project003\YourProgram.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\YourProgram.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YourProgram.dir/build: C:/data/game_project003/YourProgram.exe
.PHONY : CMakeFiles/YourProgram.dir/build

CMakeFiles/YourProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\YourProgram.dir\cmake_clean.cmake
.PHONY : CMakeFiles/YourProgram.dir/clean

CMakeFiles/YourProgram.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\data\game_project003 C:\data\game_project003 C:\data\game_project003\build C:\data\game_project003\build C:\data\game_project003\build\CMakeFiles\YourProgram.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/YourProgram.dir/depend

