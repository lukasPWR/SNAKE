//
// Created by User on 09.03.2020.
//

#include "MinesweaperBoard.h"
#include <iostream>

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode):height(height), width(width)
{
    state=START;
    float percent=0;
    board.resize(100);
    for(int i = 0; i < board.size(); i++)
    {
        board.at(i).resize(100);
    }
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.at(i).size(); j++)
        {
            this ->board.at(i).at(j).hasMine = false;
        }
    }

    if(mode == EASY)
    {
        percent = 0.1;
    }
    else if(mode == NORMAL)
    {
        percent = 0.2;
    }
    else if(mode == HARD)
    {
        percent = 0.3;
    }
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++ )
        {
            board.at(i).at(j).hasFlag=false;
            board.at(i).at(j).hasMine=false;
            board.at(i).at(j).isRevealed=false;
        }
    }
    if(mode == DEBUG)
    {
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                if(i == j)
                {
                    board.at(j).at(i).hasMine = true;
                }
                if(j == 0)
                {
                    board.at(j).at(i).hasMine = true;
                }
                if(i == 0 && j%2 == 0)
                {
                    board.at(j).at(i).hasMine = true;
                }
            }
        }
    }
    mine_count=width*height*percent;
    int mmine_amount=mine_count;
    while(mmine_amount>0)
    {
        int a= rand()%height;
        int b= rand()%width;
        if(!board.at(a).at(b).hasMine)
        {
            board.at(a).at(b).hasMine=rand()%2;
            if(board.at(a).at(b).hasMine)
                mmine_amount--;
        }
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

int MinesweeperBoard::getMineCount() const
{
    int minesAmount = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.at(i).size(); j++)
        {
            if(board.at(i).at(j).hasMine)
            {
                minesAmount++;
            }
        }
    }
    return minesAmount;
}


int MinesweeperBoard::countMines(int x, int y) const
{
    int licznik = 0;
    if(isOutside(x, y))
        return -1;
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            if(i == 0 & j == 0)
            {

            }
            else if(!isOutside(x + j, y + i)  && board.at(y + i).at(x + j).hasMine)
            {
                licznik++;
            }
        }
    }
    return licznik;
}




bool MinesweeperBoard::isRevealed(int x, int y) const
{
    if(board.at(y).at(x).isRevealed)
    {
        return 1;
    }
    else
        return 0;
}
bool MinesweeperBoard::isOutside(int x, int y) const
{
    if (x<0|| y<0||x>=getBoardWidth()||y>=getBoardHeight())
    {
        return true;
    }
    return false;
}
bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if (isOutside(x,y)|| board.at(y).at(x).isRevealed|| !board.at(y).at(x).hasFlag) {
        return false;
    }
    if (board.at(y).at(x).hasFlag)
        return true;
}

void::MinesweeperBoard::toggleFlag(int x, int y)
{
    if (board.at(y).at(x).isRevealed == 0)
    {
        board.at(y).at(x).hasFlag = 1;
    }
    if ((board.at(y).at(x).isRevealed == 1) || (x >= height || y >= width) || (state == FINISHED_WIN || state == FINISHED_LOSS))
    {
        return;
    }
}

void MinesweeperBoard::revealField(int x, int y)
{
    if (isRevealed(x,y))
        return ;
    if (state==RUNNING && !board.at(y).at(x).hasMine)
    {
        board.at(y).at(x).isRevealed = true;
    }
    if (board.at(y).at(x).hasMine && state==START)
    {
        board.at(y).at(x).hasMine= false;
        for (int i=0; i>0;)
        {
            int a = rand()%height;
            int b = rand()%width;
            if (board.at(a).at(b).hasMine)
            {
                board.at(a).at(b).hasMine = true;
                i++;
            }
        }
    }
    state=RUNNING;
    if (board.at(y).at(x).hasMine)
    {
        state = FINISHED_LOSS;
    }
    if (!isRevealed(x, y))
    {
        board.at(y).at(x).isRevealed= true;
    }

}
GameState MinesweeperBoard::getGameState() const
{
    int flags = 0;
    int flagsOnMine = 0;
    int fieldsWithoutMine = 0;
    fieldsWithoutMine = width * height - getMineCount();
    int revealedFields = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board.at(i).at(j).isRevealed == 1 && board.at(i).at(j).hasMine == 1)
            {
                return FINISHED_LOSS;
            }
            if (board.at(i).at(j).hasFlag == 1)
            {
                flags++;
            }
            if (board.at(i).at(j).hasFlag == 1 && board.at(i).at(j).hasMine == 1)
            {
                flagsOnMine++;
                if (flagsOnMine == flags && flagsOnMine == getMineCount())
                {
                    return FINISHED_WIN;
                }
            }
            if (board.at(i).at(j).isRevealed == 1 && board.at(i).at(j).hasMine == 0)
            {
                revealedFields++;
                if (revealedFields == fieldsWithoutMine)
                {
                    return FINISHED_WIN;
                }
            }
        }
    }
    return state;

}
char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if (x >= height || y >= width)
    {
        return '#';
    }
    if (board.at(y).at(x).isRevealed == 0 && board.at(y).at(x).hasFlag == 1)
    {
        return 'F';
    }
    if (board.at(y).at(x).isRevealed == 0 && board.at(y).at(x).hasFlag == 0)
    {
        return '_';
    }
    if (board.at(y).at(x).isRevealed == 1 && board.at(y).at(x).hasMine == 1)
    {
        return 'x';
    }
    if (board.at(y).at(x).isRevealed == 1 && countMines(x, y) == 0)
    {
        return 'r';
    }
    if (board.at(y).at(x).isRevealed == 1 && countMines(x, y) != 0)
    {
        int tmpx = 0;
        tmpx = countMines(x, y);
        return '0' + tmpx;
    }
}
void MinesweeperBoard::debug_display() const
{
    char jeden = '.';
    char dwa = '.';
    char trzy = '.';
    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < this->width;j++)
        {
            jeden  = '.';
            dwa= '.';
            trzy = '.';
            if (board.at(i).at(j).hasMine)
            {
                jeden = 'M';
            }
            if(board.at(i).at(j).isRevealed)
            {
                dwa = 'o';
            }
            if(board.at(i).at(j).hasFlag)
            {
                trzy = 'f';
            }
            std::cout << '{' << jeden << dwa << trzy << '}';

        }
        std::cout << std::endl;
    }

}
