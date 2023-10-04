cmake_minimum_required(VERSION 3.0.0)
project(D-Flat VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()

set(CXX_STANDARD_REQUIRED 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(dflat-executable)
add_subdirectory(dflat)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
