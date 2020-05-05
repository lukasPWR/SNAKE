//
// Created by User on 04.05.2020.
////
#ifndef SNAKE_SNAKEBOARDVIEW_H
#define SNAKE_SNAKEBOARDVIEW_H

#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"



class SnakeBoardView {
    SnakeBoard & board;
public:
    SnakeBoardView(SnakeBoard &b);
    void drawOnWindow(sf::RenderWindow & win);


};


#endif //SNAKE_SNAKEBOARDVIEW_H
