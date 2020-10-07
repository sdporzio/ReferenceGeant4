project(Main)

include_directories(
  ../Analysis/include
  ../PhysicsList/include
  ../Generator/include
  ../Geometry/include
  ../Processing/include
  )

add_executable(sdp_main sdp_main.cc)
target_link_libraries(sdp_main
  ${Geant4_LIBRARIES}
  Analysis
  PhysicsList
  Generator
  Geometry
  Processing
  )

install(TARGETS sdp_main DESTINATION ${CMAKE_INSTALL_BINDIR})
