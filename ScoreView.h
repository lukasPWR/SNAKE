//
// Created by User on 19.04.2020.
//

#ifndef SAPER_SCOREVIEW_H
#define SAPER_SCOREVIEW_H
#include "MinesweaperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>



class ScoreView {
    MinesweeperBoard & board;
    sf::Font font_1;
    sf::Text text_1;
    sf::Text text_2;
    sf::Text text_3;
public:
 ScoreView(MinesweeperBoard &b);
 void draw(sf::RenderWindow &win);


};


#endif //SAPER_SCOREVIEW_H
