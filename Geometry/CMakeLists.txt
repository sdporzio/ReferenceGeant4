project(Geometry)

include_directories(
  include
)

aux_source_directory(src GEOMETRY_SRCS)
add_library(Geometry SHARED ${GEOMETRY_SRCS})
target_link_libraries(Geometry
  ${Geant4_LIBRARIES}
  ${ROOT_LIBRARIES}
  )

# install instructions
file(GLOB PACKAGE_HEADERS include/*.hh include/*.h)
install(TARGETS Geometry DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PACKAGE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
unset(PACKAGE_HEADERS)