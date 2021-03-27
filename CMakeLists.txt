cmake_minimum_required(VERSION 3.17)
project(RPG)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPG src/main.cpp src/Game.cpp src/Game.h src/State.cpp src/State.h)