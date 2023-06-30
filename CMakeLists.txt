cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    crillab-except
    VERSION 0.1.0
    DESCRIPTION "An exception library for C++"
    HOMEPAGE_URL "https://github.com/crillab/except"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    crillab-except_crillab-except
    source/except.cpp
)
add_library(crillab-except::crillab-except ALIAS crillab-except_crillab-except)

include(GenerateExportHeader)
generate_export_header(
    crillab-except_crillab-except
    BASE_NAME crillab-except
    EXPORT_FILE_NAME export/crillab-except/except.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(crillab-except_crillab-except PUBLIC CRILLAB_EXCEPT_STATIC_DEFINE)
endif()

set_target_properties(
    crillab-except_crillab-except PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME crillab-except
    OUTPUT_NAME crillab-except
)

target_compile_features(crillab-except_crillab-except PUBLIC cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT crillab-except_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of crillab-except"
  )
endif()

include(cmake/dev-mode.cmake)
