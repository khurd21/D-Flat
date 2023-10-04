project(DFlat)

set(sources
    src/classifier.cpp
    src/command_line_args.cpp
    src/lexer.cpp
    src/token.cpp
)

add_library(${PROJECT_NAME} ${sources})
add_library(dflat::library ALIAS ${PROJECT_NAME})

add_subdirectory(test)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Add compile options for Debug to the library
    target_compile_options(${PROJECT_NAME} PRIVATE
        -gdwarf-4
    )
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)