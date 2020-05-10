//
// Created by User on 06.05.2020.
//

#ifndef SNAKE_LUK_MENUCONTROLLER_H
#define SNAKE_LUK_MENUCONTROLLER_H

#include "SnakeBoard.h"
#include "MenuView.h"


class MenuController {
    SnakeBoard &board;
    MenuView &view;
    bool finished=false;
public:
    MenuController (SnakeBoard &sb, MenuView &v);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished; }

};


#endif //SNAKE_LUK_MENUCONTROLLER_H
