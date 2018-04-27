cmake_minimum_required(VERSION 3.9)
project(Course_MTM)

set(CMAKE_CXX_STANDARD 11)

add_executable(Course_MTM
        driver.h
        season.h
        team.c
        team.h
        main.c)
