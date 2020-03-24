//
// Created by User on 24.03.2020.
//

#ifndef PO_L2_MSBOARDTEXTVIEW_H
#define PO_L2_MSBOARDTEXTVIEW_H
#include"MinesweaperBoard.h"


class MSBoardTextView
        {
    MinesweeperBoard &board;
    void showField(int x,int y) const;

public:
    MSBoardTextView(MinesweeperBoard &board);
    void display () const;


};


#endif //PO_L2_MSBOARDTEXTVIEW_H
