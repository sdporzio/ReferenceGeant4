project(PhysicsList)

include_directories(
  include
)

aux_source_directory(src PHYSICS_LIST_SRCS)
add_library(PhysicsList SHARED ${PHYSICS_LIST_SRCS})
target_link_libraries(PhysicsList
  ${Geant4_LIBRARIES}
  ${ROOT_LIBRARIES}
  )

# install instructions
file(GLOB PACKAGE_HEADERS include/*.hh include/*.h)
install(TARGETS PhysicsList DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PACKAGE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
unset(PACKAGE_HEADERS)