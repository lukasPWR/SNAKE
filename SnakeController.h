//
// Created by User on 05.05.2020.
//

#ifndef SNAKE_LUK_SNAKECONTROLLER_H
#define SNAKE_LUK_SNAKECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "SnakeBoardView.h"
#include "SnakeBoard.h"

class SnakeController {

    bool finished = false;
    SnakeBoardView & view;
    SnakeBoard & board;

public:
     SnakeController(SnakeBoardView & v, SnakeBoard & b);
public:
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished; }
};
#endif //SNAKE_LUK_SNAKECONTROLLER_H

