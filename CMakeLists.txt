cmake_minimum_required(VERSION 3.10)

project(vcpu)

set(CMAKE_C_STANDARD 23)
add_compile_options(-g -Wall -Wextra -pedantic -Werror -O3 -Wno-unused-parameter -Wno-newline-eof -Wno-strict-prototypes)

include_directories("src/core" "src/cpu")

include(FindPkgConfig)

FILE(GLOB_RECURSE MyCSources src/*.c)

add_executable(vcpu ${MyCSources})

target_link_libraries(vcpu m)


