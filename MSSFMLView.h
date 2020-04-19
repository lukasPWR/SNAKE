//
// Created by User on 08.04.2020.
//
//
#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H


#include <SFML/Graphics.hpp>
#include "MinesweaperBoard.h"
#include "MSBoardTextView.h"


class MSSFMLView
{
    MinesweeperBoard & board;

public:
    MSSFMLView(MinesweeperBoard & b);
    void drawOnWindow(sf::RenderWindow & win);

};


#endif //SAPER_MSSFMLVIEW_H
