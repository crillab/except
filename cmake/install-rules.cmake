if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/crillab-except-${PROJECT_VERSION}"
      CACHE PATH ""
  )
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package crillab-except)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT crillab-except_Development
)

install(
    TARGETS crillab-except_crillab-except
    EXPORT crillab-exceptTargets
    RUNTIME #
    COMPONENT crillab-except_Runtime
    LIBRARY #
    COMPONENT crillab-except_Runtime
    NAMELINK_COMPONENT crillab-except_Development
    ARCHIVE #
    COMPONENT crillab-except_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    crillab-except_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/share/${package}"
    CACHE PATH "CMake package config location relative to the install prefix"
)
mark_as_advanced(crillab-except_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${crillab-except_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT crillab-except_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${crillab-except_INSTALL_CMAKEDIR}"
    COMPONENT crillab-except_Development
)

install(
    EXPORT crillab-exceptTargets
    NAMESPACE crillab-except::
    DESTINATION "${crillab-except_INSTALL_CMAKEDIR}"
    COMPONENT crillab-except_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
