//
// Created by User on 06.05.2020.
//

#ifndef SNAKE_LUK_SCOREVIEW_H
#define SNAKE_LUK_SCOREVIEW_H

#include "SnakeBoard.h"
#include <SFML/Graphics.hpp>

class ScoreView {
    SnakeBoard & board;
    sf::Text gameOver;
    sf::Font font1;
    sf::Text scoreText;
    sf::Font font2;
    sf::RectangleShape background;
public:
    ScoreView(SnakeBoard & sb);
    void draw(sf::RenderWindow &win);
};


#endif //SNAKE_LUK_SCOREVIEW_H
