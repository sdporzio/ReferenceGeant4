project(Analysis)

include_directories(
  include
)

aux_source_directory(src ANALYSIS_SRCS)
add_library(Analysis SHARED ${ANALYSIS_SRCS})

# install instructions
file(GLOB PACKAGE_HEADERS include/*.hh include/*.h)
install(TARGETS Analysis DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PACKAGE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
unset(PACKAGE_HEADERS)