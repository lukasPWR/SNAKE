//
// Created by User on 06.05.2020.
//

#ifndef SNAKE_LUK_MENUVIEW_H
#define SNAKE_LUK_MENUVIEW_H

#include <Graphics/RenderWindow.hpp>
#include "SnakeBoard.h"
#include <SFML/Graphics.hpp>


class MenuView {
    SnakeBoard & board;
    sf::Font font1;
    sf::Font font2;
    sf::Text text1;
    sf::Text text2;
    sf::RectangleShape playButton;

public:
    MenuView(SnakeBoard &sb);
    void draw(sf::RenderWindow &win);


};


#endif //SNAKE_LUK_MENUVIEW_H
