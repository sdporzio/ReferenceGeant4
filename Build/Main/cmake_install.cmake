# Install script for directory: /Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Main

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/sdp_main")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Main/sdp_main")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/sdp_main" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/PhysicsList"
      "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Geometry"
      "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Processing"
      "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Analysis"
      "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/sdporzio/Work/WorkingProjects/Geant4Sim_PtfeReflection/Build/Generator"
      "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/sdporzio/Software/geant4.10.06.p01/install/lib"
      "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}/usr/local/bin/sdp_main")
    endif()
  endif()
endif()

