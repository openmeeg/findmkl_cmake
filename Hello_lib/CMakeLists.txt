include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Hello_lib)

add_library(Hello_lib SHARED
  Speaker.h
  Speaker.cpp)

target_compile_definitions(Hello_lib PUBLIC ${BLA_DEFINITIONS})

target_link_libraries(Hello_lib PRIVATE ${BLAS_LIBRARIES})

target_include_directories(Hello_lib
    INTERFACE
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    PRIVATE
        ${BLA_INCLUDE_DIR}
)

add_library(Hello_lib::Hello_lib ALIAS Hello_lib)

install (TARGETS Hello_lib
    EXPORT Hello_lib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install (FILES Speaker.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/Hello_lib-ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/Hello_lib-ConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)


#Export the targets to xxxxConfig.cmake
install(EXPORT Hello_lib
  FILE
    Hello_libConfig.cmake
  NAMESPACE
    Hello_lib::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)
