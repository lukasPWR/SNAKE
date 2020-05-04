
// Created by User on 09.03.2020.
//

#include "MinesweaperBoard.h"
#include <iostream>

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode M):height(height), width(width), mode(M)
{
    reset_board(height,width,mode);


}
void MinesweeperBoard::reset_board(int x, int y, GameMode m)
{
    state=START;
    float percent=0;
    board.resize(100);
    width=x;
    height=y;
    mode=m;

    for(int i = 0; i < board.size(); i++)
    {
        board.at(i).resize(100);
    }
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.at(i).size(); j++)
        {
            board.at(i).at(j).hasMine = false;
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
    int minedFields = 0;
    minedFields = percent * width*height;
    int a = 0;
    int b = 0;

    for (int m1 = 0; m1 < minedFields; m1++)
    {
        do
        {
            a = rand() % height;
            b = rand() % width;

        } while (board.at(a).at(b).hasMine == 1);

        board.at(a).at(b).hasMine = 1;
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
            if(board.at(i).at(j).hasMine == 1)
            {
                minesAmount++;
            }
        }
    }
    return minesAmount;
}


int MinesweeperBoard::countMines(int x, int y) const
{
    int mines_around = 0;
    if(board.at(y).at(x).isRevealed == 0)
    {
        return -1;
    }
    if((x<0) || (x >=getBoardHeight()) ||(y<0) || (y>=getBoardWidth()))
    {
        return -1;
    }
    if((x!= 0) && (board.at(y-1).at(x).hasMine == true))
    {
        mines_around++;
    }
    if((x != getBoardHeight()-1) && (board.at(y+1).at(x).hasMine == true))
    {
        mines_around++;
    }
    if(( y!= 0) && (x!=0) && (board.at(y-1).at(x-1).hasMine == true))
    {
        mines_around++;
    }
    if((y!=0) && (board.at(y).at(x-1).hasMine ==  true))
    {
        mines_around++;
    }
    if((y!=0) && (x!=getBoardHeight()-1) && (board.at(y+1).at(x-1).hasMine == true))
    {
        mines_around++;
    }
    if ((y!= getBoardWidth()- 1) && (x!=0) && (board.at(y-1).at(x+1).hasMine == true))
    {
        mines_around++;
    }
    if((y!=getBoardWidth()-1) && (board.at(y).at(x+1).hasMine ==  true))
    {
        mines_around++;
    }
    if((y!=getBoardWidth()-1) && (x!=getBoardHeight()-1) && (board.at(y+1).at(x+1).hasMine ==  true))
    {
        mines_around++;
    }
    return mines_around;
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
    if(isOutside(x,y))
    {
        return ;
    }
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
bool MinesweeperBoard::hasMine(int x, int y) const
{
    if ((x >= getBoardHeight() || y >= getBoardWidth()) || (board.at(y).at(x).hasMine == false) || (board.at(y).at(x).isRevealed == true))
    {
        return false;
    }
    if (board.at(y).at(x).hasMine == true)
    {
        return true;
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
