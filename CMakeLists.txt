cmake_minimum_required(VERSION 3.15)
project(SAPER)

set(CMAKE_CXX_STANDARD 14)

add_executable(SAPER main.cpp MinesweaperBoard.cpp MSBoardTextView.cpp MSTextController.cpp MSSFMLView.cpp MinesweeperController.cpp MinesweeperController.h StartScreen.cpp StartScreen.h test.cpp StartScreenController.cpp StartScreenController.h ScoreView.cpp ScoreView.h ScoreViewController.cpp ScoreViewController.h GameManager.cpp)# Detect and add SFML
set(SFML_PATH "C:/Program Files (x86)/c/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    target_link_libraries(SAPER sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()