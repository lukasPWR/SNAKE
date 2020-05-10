cmake_minimum_required(VERSION 3.15)
project(SNAKE_LUK)

set(CMAKE_CXX_STANDARD 14)

add_executable(SNAKE_LUK main.cpp SnakeBoard.cpp SnakeBoard.h SnakeBoardView.cpp SnakeBoardView.h SnakeController.cpp SnakeController.h MenuView.cpp MenuView.h MenuController.cpp MenuController.h ScoreView.cpp ScoreView.h GameMenager.cpp GameMenager.h ScoreController.cpp ScoreController.h)# Detect and add SFML
set(SFML_PATH "C:/Program Files (x86)/c/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    target_link_libraries(SNAKE_LUK sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()