//
// Created by User on 19.04.2020.
//

#ifndef SAPER_STARTSCREEN_H
#define SAPER_STARTSCREEN_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;


class StartScreen {
    sf::Font font_1;

    sf::Text text_1;

    sf::RectangleShape rectangle[3][2]; // przyciski poziomu trudnosci, wymiaru planszy
    sf::CircleShape circle; // przycisk start

public:
    StartScreen();
    void circleOutline();// pojawiajace sie obramowanie po nacisnieciu start
    void rectangleOutline(int X, int Y, bool tmp); // pojawiajace sie obramowanie po wyborze rommiaru planszy i poziomu trudnosci
    void draw(sf::RenderWindow & win);


};


#endif //SAPER_STARTSCREEN_H
