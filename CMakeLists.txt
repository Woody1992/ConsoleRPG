cmake_minimum_required(VERSION 3.17)
project(RPG)

set(CMAKE_CXX_STANDARD 14)


add_executable(RPG src/main.cpp src/Game.cpp src/Game.h src/States/State.cpp src/States/State.h src/Character.cpp src/Character.h src/States/GameState.cpp src/States/GameState.h src/States/MainMenuState.cpp src/States/MainMenuState.h src/States/CharacterCreatorState.cpp src/States/CharacterCreatorState.h src/States/CharacterMenuState.cpp src/States/CharacterMenuState.h src/States/CharacterSelectorState.cpp src/States/CharacterSelectorState.h src/States/TravelMenuState.cpp src/States/TravelMenuState.h src/Enemy.cpp src/Enemy.h)