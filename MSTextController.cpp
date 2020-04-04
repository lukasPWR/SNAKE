//
// Created by User on 04.04.2020.
//
#include <iostream>
#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MinesweaperBoard.h"


MSTextController::MSTextController(MinesweeperBoard &board1, MSBoardTextView &view1): board(board1),view(view1)
{

}
void MSTextController::play()
{
    int row, column;
    char move;
    int t = 1;
do
    {
        view.display();
        std::cout << "row: ";

        std::cin >> row;

        std::cout << "column: ";

        std::cin >> column;

        std::cout << "action: ";

        std::cin >> move;
        if (move == 'r') {
            board.revealField(column, row);
        }
        if (move == 'f') {
            board.toggleFlag(column, row);
        }
        t++;
    }while (board.getGameState() == RUNNING);
    {
    if(board.getGameState() == FINISHED_LOSS)
    {
        std::cout << "Game Over" << endl;
    }
    if (board.getGameState() == FINISHED_WIN)
    {
        std::cout <<"Gz" << std::endl;
    }
    }



}