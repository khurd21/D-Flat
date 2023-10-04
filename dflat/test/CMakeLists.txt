set(binary ${CMAKE_PROJECT_NAME}_test)

set(sources
    placeholder_test.cpp
)

add_executable(${binary} ${sources})
target_link_libraries(${binary} PRIVATE dflat::library GTest::gtest GTest::gtest_main)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Add compile options for Debug to the library
    target_compile_options(${PROJECT_NAME} PRIVATE
        -gdwarf-4
    )
endif()

include(GoogleTest)
gtest_discover_tests(${binary})