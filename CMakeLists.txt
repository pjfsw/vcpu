cmake_minimum_required(VERSION 3.10)

project(cpgemu)

set(CMAKE_C_STANDARD 23)
add_compile_options(-g -Wall -Wextra -pedantic -Werror -O3 -Wno-unused-parameter -Wno-newline-eof -Wno-strict-prototypes)

include(FindPkgConfig)

FILE(GLOB_RECURSE MyCSources *.c)

add_executable(vcpu ${MyCSources})

target_link_libraries(vcpu m)


