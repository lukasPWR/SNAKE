//
// Created by User on 24.03.2020.
//

#include "MSBoardTextView.h"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b): board(b)
{

}

void  MSBoardTextView::display() const
{
    std::cout <<"X ";
    for ( int k = 0; k<board.getBoardWidth(); k++)
    {
        std:: cout<<" "<< k << " ";
    }
    std:: cout << std:: endl;

    for( int i = 0; i<board.getBoardHeight(); i++)
    {
        std::cout << i <<" ";
        for(int j = 0; j <board.getBoardWidth(); j++)
        {
            std::cout << "["<< board.getFieldInfo(i,j) <<"]";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
