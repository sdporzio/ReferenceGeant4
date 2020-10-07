# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build

# Include any dependencies generated for this target.
include Main/CMakeFiles/sdp_main.dir/depend.make

# Include the progress variables for this target.
include Main/CMakeFiles/sdp_main.dir/progress.make

# Include the compile flags for this target's objects.
include Main/CMakeFiles/sdp_main.dir/flags.make

Main/CMakeFiles/sdp_main.dir/sdp_main.cc.o: Main/CMakeFiles/sdp_main.dir/flags.make
Main/CMakeFiles/sdp_main.dir/sdp_main.cc.o: ../Main/sdp_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Main/CMakeFiles/sdp_main.dir/sdp_main.cc.o"
	cd /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdp_main.dir/sdp_main.cc.o -c /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Main/sdp_main.cc

Main/CMakeFiles/sdp_main.dir/sdp_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdp_main.dir/sdp_main.cc.i"
	cd /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Main/sdp_main.cc > CMakeFiles/sdp_main.dir/sdp_main.cc.i

Main/CMakeFiles/sdp_main.dir/sdp_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdp_main.dir/sdp_main.cc.s"
	cd /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Main/sdp_main.cc -o CMakeFiles/sdp_main.dir/sdp_main.cc.s

# Object files for target sdp_main
sdp_main_OBJECTS = \
"CMakeFiles/sdp_main.dir/sdp_main.cc.o"

# External object files for target sdp_main
sdp_main_EXTERNAL_OBJECTS =

Main/sdp_main: Main/CMakeFiles/sdp_main.dir/sdp_main.cc.o
Main/sdp_main: Main/CMakeFiles/sdp_main.dir/build.make
Main/sdp_main: PhysicsList/libPhysicsList.dylib
Main/sdp_main: Geometry/libGeometry.dylib
Main/sdp_main: Processing/libProcessing.dylib
Main/sdp_main: Analysis/libAnalysis.dylib
Main/sdp_main: Generator/libGenerator.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4Tree.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4GMocren.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4FR.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4visHepRep.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4RayTracer.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4VRML.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4OpenGL.dylib
Main/sdp_main: /usr/X11R6/lib/libXmu.dylib
Main/sdp_main: /usr/X11R6/lib/libXext.dylib
Main/sdp_main: /usr/X11R6/lib/libXt.dylib
Main/sdp_main: /usr/X11R6/lib/libSM.dylib
Main/sdp_main: /usr/X11R6/lib/libICE.dylib
Main/sdp_main: /usr/X11R6/lib/libX11.dylib
Main/sdp_main: /usr/local/Cellar/qt/5.12.2/lib/QtOpenGL.framework/QtOpenGL
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4gl2ps.dylib
Main/sdp_main: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
Main/sdp_main: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
Main/sdp_main: /usr/X11R6/lib/libGLU.dylib
Main/sdp_main: /usr/X11R6/lib/libGL.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4vis_management.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4modeling.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4interfaces.dylib
Main/sdp_main: /usr/local/Cellar/qt/5.12.2/lib/QtPrintSupport.framework/QtPrintSupport
Main/sdp_main: /usr/local/Cellar/qt/5.12.2/lib/QtWidgets.framework/QtWidgets
Main/sdp_main: /usr/local/Cellar/qt/5.12.2/lib/QtGui.framework/QtGui
Main/sdp_main: /usr/local/Cellar/qt/5.12.2/lib/QtCore.framework/QtCore
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4persistency.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4error_propagation.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4readout.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4physicslists.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4run.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4event.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4tracking.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4parmodels.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4processes.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4analysis.dylib
Main/sdp_main: /usr/lib/libexpat.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4digits_hits.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4track.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4particles.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4geometry.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4materials.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4graphics_reps.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4intercoms.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4global.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4clhep.dylib
Main/sdp_main: /Users/sdporzio/Software/geant4.10.06.p01/install/lib/libG4zlib.dylib
Main/sdp_main: Main/CMakeFiles/sdp_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sdp_main"
	cd /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sdp_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Main/CMakeFiles/sdp_main.dir/build: Main/sdp_main

.PHONY : Main/CMakeFiles/sdp_main.dir/build

Main/CMakeFiles/sdp_main.dir/clean:
	cd /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main && $(CMAKE_COMMAND) -P CMakeFiles/sdp_main.dir/cmake_clean.cmake
.PHONY : Main/CMakeFiles/sdp_main.dir/clean

Main/CMakeFiles/sdp_main.dir/depend:
	cd /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Main /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main/CMakeFiles/sdp_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Main/CMakeFiles/sdp_main.dir/depend
