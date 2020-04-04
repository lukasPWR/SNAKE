cmake_minimum_required(VERSION 3.15)
project(PO_L2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PO_L2 main.cpp MinesweaperBoard.cpp MinesweaperBoard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h)