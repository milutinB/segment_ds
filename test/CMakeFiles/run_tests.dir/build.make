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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mica/Documents/segment_ds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mica/Documents/segment_ds

# Include any dependencies generated for this target.
include test/CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/run_tests.dir/flags.make

test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o: test/CMakeFiles/run_tests.dir/flags.make
test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o: test/NodeUtilsTest.cpp
test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o: test/CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mica/Documents/segment_ds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o"
	cd /Users/mica/Documents/segment_ds/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o -MF CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o.d -o CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o -c /Users/mica/Documents/segment_ds/test/NodeUtilsTest.cpp

test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.i"
	cd /Users/mica/Documents/segment_ds/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mica/Documents/segment_ds/test/NodeUtilsTest.cpp > CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.i

test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.s"
	cd /Users/mica/Documents/segment_ds/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mica/Documents/segment_ds/test/NodeUtilsTest.cpp -o CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

test/run_tests: test/CMakeFiles/run_tests.dir/NodeUtilsTest.cpp.o
test/run_tests: test/CMakeFiles/run_tests.dir/build.make
test/run_tests: lib/libgtest_main.a
test/run_tests: src/libsegment_ds_lib.a
test/run_tests: lib/libgtest.a
test/run_tests: /opt/homebrew/lib/libgmpxx.dylib
test/run_tests: /opt/homebrew/lib/libmpfr.dylib
test/run_tests: /opt/homebrew/lib/libgmp.dylib
test/run_tests: test/CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mica/Documents/segment_ds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable run_tests"
	cd /Users/mica/Documents/segment_ds/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/mica/Documents/segment_ds/test && /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -D TEST_TARGET=run_tests -D TEST_EXECUTABLE=/Users/mica/Documents/segment_ds/test/run_tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/mica/Documents/segment_ds/test -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=run_tests_TESTS -D CTEST_FILE=/Users/mica/Documents/segment_ds/test/run_tests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/Cellar/cmake/3.22.3/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/run_tests.dir/build: test/run_tests
.PHONY : test/CMakeFiles/run_tests.dir/build

test/CMakeFiles/run_tests.dir/clean:
	cd /Users/mica/Documents/segment_ds/test && $(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/run_tests.dir/clean

test/CMakeFiles/run_tests.dir/depend:
	cd /Users/mica/Documents/segment_ds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mica/Documents/segment_ds /Users/mica/Documents/segment_ds/test /Users/mica/Documents/segment_ds /Users/mica/Documents/segment_ds/test /Users/mica/Documents/segment_ds/test/CMakeFiles/run_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/run_tests.dir/depend

