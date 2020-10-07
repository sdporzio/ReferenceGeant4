#----------------------------------------------------------------------------
# Setup the project

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Main)

set(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)
set(CMAKE_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)


#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()


#----------------------------------------------------------------------------
# Copy .mac scripts

file(GLOB MACRO_SCRIPTS ${PROJECT_SOURCE_DIR}/Macros/*)
file(COPY ${MACRO_SCRIPTS} DESTINATION ${PROJECT_BINARY_DIR}/Macros)


#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project

include(${Geant4_USE_FILE})

include_directories(
  ${Geant4_INCLUDE_DIRS}
  ${ROOT_INCLUDE_DIRS}
  Analysis/include
  PhysicsList/include
  Generator/include
  Geometry/include
  Processing/include
  )

add_subdirectory(Analysis)
add_subdirectory(PhysicsList)
add_subdirectory(Generator)
add_subdirectory(Geometry)
add_subdirectory(Processing)
add_subdirectory(Main)