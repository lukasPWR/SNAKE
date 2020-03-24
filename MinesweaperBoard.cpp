//
// Created by User on 09.03.2020.
//

#include "MinesweaperBoard.h"
#include <iostream>



    MinesweeperBoard:: MinesweeperBoard(int width, int height, GameMode mode): width(width), height(height)
    {
    board.resize(this->width);
    for(int i=0; i<board.size(); i++)
    {
        board.at(i).resize(height);
    }
    for(int i=0; i<this->width;i++)

        for(int i=0; i<this->height;i++)
        {
            this->board.at(i).at(i).hasMine=false;
        }
    }


    int MinesweeperBoard::getBoardHeight() const
    {
    return board.at(0).size();
}

int MinesweeperBoard::getBoardWidth() const
{
    return board.size();
}
int MinesweeperBoard::getMineCount() const {
    int licznikbomb = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.at(i).size(); j++) {
            if (board.at(i).at(j).hasMine) {
                licznikbomb++;
            }
        }
    }
    return licznikbomb;
}
int MinesweeperBoard::countMines(int x, int y) const
{

}
void MinesweeperBoard::debug_display() const
{

    char pierwszy = '.';
    char drugi = '.';
    char trzeci = '.';
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size();j++)
        {
            pierwszy = '.';
            drugi = '.';
            trzeci = '.';
            if (board.at(i).at(i).hasMine)
            {
                pierwszy = 'M';
            }
            if(board.at(i).at(i).isRevealed)
            {
                drugi = 'o';
            }
            if(board.at(i).at(i).hasFlag)
            {
                trzeci = 'f';
            }
            std::cout << '{' << pierwszy << drugi << trzeci << '}';

        }
        std::cout << std::endl;
    }

}


