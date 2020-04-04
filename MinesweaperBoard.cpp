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
    int mines = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.at(i).size(); j++)
        {
            if(board.at(i).at(j).hasMine)
            {
                mines++;
            }
        }
    }
    return mines;
}


int MinesweeperBoard::countMines(int x, int y) const
{
int amount_mines=0;
if(board.at(y).at(x).isRevealed || isOutside(x,y))
{
    return -1;
}
else
    for(int i=0; i<2;i++)
    {
        for(int j=0;j<2; j++)
        {
            if(board.at(y-1+i).at(x+j-1).hasMine)
                amount_mines++;
        }
    }
    return amount_mines;
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
    if (isOutside(x,y)|| board.at(y).at(x).isRevealed|| !board.at(y).at(x).hasFlag)
        return false;
    return board.at(y).at(x).hasFlag;
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if (isOutside(x,y)||isRevealed(x,y)||state==FINISHED_WIN||state==FINISHED_LOSS)
        return;
    else if (!isRevealed(x,y) && hasFlag(x,y))
        board.at(y).at(x).hasMine = false;
    else if (!isRevealed(x,y) && !hasFlag(x,y))
        board.at(y).at(x).hasMine= true;
}
void MinesweeperBoard::revealField(int x, int y)
{
    if (isRevealed(x,y))
        return;
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
    GameState state;
    int mines_1=mine_count;
    int mines_2=mine_count;
    for (int i=0;i<getBoardHeight(); i++)
    {
        for (int j=0;j<getBoardWidth(); j++)
        {
            if (board.at(i).at(j).hasMine && isRevealed(j, i))

                return state=FINISHED_LOSS;

            else if (board.at(i).at(j).hasMine && hasFlag(j, i))
            {
                if (!board.at(i).at(j).hasMine && hasFlag(j, i))
                    mines_1++;
                mines_1--;
                if (mines_1==0)
                    return state=FINISHED_WIN;
            }
            else if (!isRevealed(j, i) && board.at(i).at(j).hasMine)
            {
                mines_2--;
                if (mines_2==0)
                {
                    return  state=FINISHED_WIN;
                }
            }
            else
                return state=RUNNING;
        }
    }
    abort();
}
char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if (isOutside(x,y))
        return '#';
    else if (!isRevealed(x,y) && hasFlag(x,y))
        return 'F';
    else if (!isRevealed(x,y) && !hasFlag(x,y))
        return '_';
    else if (isRevealed(x,y) && board.at(y).at(x).hasMine)
        return 'x';
    else if (isRevealed(x,y) && countMines(x,y)==0)
        return ' ';
    else if (isRevealed(x,y) && countMines(x,y)!=0)
        return countMines(x,y);
    else
        return '?';
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
