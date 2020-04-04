//
// Created by User on 24.03.2020.
//

#include "MSBoardTextView.h"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board): board(board)
{
    this->board=board;
}
void MSBoardTextView::showField(int x, int y) const
{
    char a=board.getFieldInfo(x,y);
    std::cout << a <<endl;
}
void  MSBoardTextView::display() const
{
    int h=board.getBoardHeight();
    int w=board.getBoardWidth();
    for (int i=0;i<h; i++)
    {
        for(int j=0;j<w; j++)
        {
            showField(j,i);
        }
    }

}
