//
// Created by User on 04.04.2020.
//


#ifndef PO_L2_MSTEXTCONTROLLER_H
#define PO_L2_MSTEXTCONTROLLER_H

#include "MSBoardTextView.h"
#include "MinesweaperBoard.h"


class MSTextController {
    MinesweeperBoard & board;
    MSBoardTextView & view;
public:
    MSTextController(MinesweeperBoard &board1, MSBoardTextView &view1);
    void play();

};


#endif //PO_L2_MSTEXTCONTROLLER_H
