project(DFlat-Executable)

add_executable(${PROJECT_NAME} main.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Add compile options for Debug to the executable
    target_compile_options(${PROJECT_NAME} PRIVATE
        -gdwarf-4
    )
endif()

target_link_libraries(${PROJECT_NAME}
    dflat::library
)