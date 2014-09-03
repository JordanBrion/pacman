cmake_minimum_required( VERSION 2.8 )
project( PacMan )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
        ${SDL2_DIR}
        ${SDL2_IMAGE_DIR}
        ${SDL2_TTF_DIR}
)

link_directories(
        ${SDL2_LIB}
        ${SDL2_IMAGE_LIB}
        ${SDL2_TTF_LIB}
)

file(
    GLOB_RECURSE
    include
    ${CMAKE_SOURCE_DIR}/include/*
)

file(
    GLOB_RECURSE
    common
    ${CMAKE_SOURCE_DIR}/common/*
)

file(
    GLOB_RECURSE
    src_files
    ${CMAKE_SOURCE_DIR}/src/*
)

add_executable(
    ${PROJECT_NAME}
    ${include}
    ${common}
    ${src_files}
)

target_link_libraries(
    ${PROJECT_NAME}
    SDL2
    SDL2_image
    SDL2_ttf
)
