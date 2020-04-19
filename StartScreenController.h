//
// Created by User on 19.04.2020.
//

#ifndef SAPER_STARTSCREENCONTROLLER_H
#define SAPER_STARTSCREENCONTROLLER_H
#include <SFML/Graphics.hpp>
#include "StartScreen.h"
#include "MinesweaperBoard.h"


class StartScreenController {
    MinesweeperBoard &board;
    StartScreen &view;
    int x;
    int y;
    GameMode mode;
    bool finished;
public:
    explicit StartScreenController(StartScreen &ssv, MinesweeperBoard &b);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win) { view.draw(win); }
    int get_x()const;
    int get_y()const;
    GameMode getMode()const;
    bool isFinished() const {return finished;}



};


#endif //SAPER_STARTSCREENCONTROLLER_H
