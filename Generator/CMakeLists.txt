project(Generator)

include_directories(
  include
)

aux_source_directory(src GENERATOR_SRCS)
add_library(Generator SHARED ${GENERATOR_SRCS})
target_link_libraries(Generator
  ${Geant4_LIBRARIES}
  ${ROOT_LIBRARIES}
  )

# install instructions
file(GLOB PACKAGE_HEADERS include/*.hh include/*.h)
install(TARGETS Generator DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PACKAGE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
unset(PACKAGE_HEADERS)