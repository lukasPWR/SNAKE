//
// Created by User on 16.04.2020.
//
#pragma once
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MinesweaperBoard.h"

class MinesweeperController {

    bool finished = false;
    MSSFMLView &view;
    MinesweeperBoard &board;

public:
    explicit MinesweeperController(MSSFMLView &v, MinesweeperBoard & b);
    void handleEvent(sf::Event &event);
    void drawOnWindow(sf::RenderWindow & win) { view.drawOnWindow(win); }
    bool isFinished() const { return finished; }
};