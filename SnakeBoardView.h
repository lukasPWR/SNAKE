//
// Created by User on 04.05.2020.
////
#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"

class SnakeBoardView
{
    SnakeBoard & board;
    sf::RectangleShape wall;
    sf::Texture wall_txt;
    sf::RectangleShape background;
    sf::Texture background_txt;
    sf::RectangleShape snake;
    sf::RectangleShape food;
    sf::Texture food_txt;
    sf::Text score;
    sf::Font font;
    sf::Text space;
public:
    SnakeBoardView(SnakeBoard & b);
    void draw(sf::RenderWindow & w);
};
