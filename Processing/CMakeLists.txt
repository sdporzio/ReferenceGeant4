project(Processing)

include_directories(
  include
)

aux_source_directory(src PROCESSING_SRCS)
add_library(Processing SHARED ${PROCESSING_SRCS})
target_link_libraries(Processing
  Analysis
  Generator
  ${Geant4_LIBRARIES}
  ${ROOT_LIBRARIES}
  )

# install instructions
file(GLOB PACKAGE_HEADERS include/*.hh include/*.h)
install(TARGETS Processing DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PACKAGE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
unset(PACKAGE_HEADERS)