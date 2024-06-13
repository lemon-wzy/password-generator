cmake_minimum_required(VERSION 3.29)
project(password_generator)

set(CMAKE_CXX_STANDARD 20)

add_executable(pg main.cpp
        lib/password_generator.h
        src/generator_string.cpp
        src/read_console_args.cpp
        src/console_args.cpp
        lib/console_args.h
        lib/common_lib.h
)
