//
// Created by User on 19.04.2020.
//

#include "StartScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>

StartScreen::StartScreen()
{
    if (!font_1.loadFromFile("courier-new.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    text_1.setFont(font_1);

    // pola przyciskow
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            rectangle[i][j].setSize(sf::Vector2f(120,40));
            rectangle[i][j].setFillColor(sf::Color(0,153,76));

        }
    }
    circle.setRadius(125);
    circle.setFillColor(sf::Color(0,153,76));




}
void StartScreen::circleOutline()
{
    circle.setOutlineThickness(8);
    circle.setOutlineColor(sf::Color::Green);
}
void StartScreen::rectangleOutline(int X, int Y, bool tmp)
{
    if( tmp == true)
    {
        rectangle[X][Y].setOutlineThickness(8);
        rectangle[X][Y].setOutlineColor(sf::Color(0,153,153));
    }
    if(tmp == false)
    {
        rectangle[X][Y].setOutlineThickness(8);
        rectangle[X][Y].setOutlineColor(sf::Color::Magenta);

    }

}
void StartScreen::draw(sf::RenderWindow &win)
{

    // przyciski rozmiaru i lvl

    for( int i =0; i< 3; ++i)
    {
        for( int j = 0; j<2; ++j )
        {
            rectangle[i][j].setPosition(35+j*180, 350 + i*100 );
            win.draw(rectangle[i][j]);
        }
        circle.setRadius(100);
        circle.setFillColor(sf::Color(0, 153, 153));
        circle.setPosition(700, 400);
    }
    text_1.setCharacterSize(50);
    text_1.setStyle(sf::Text::Bold);
    text_1.setString("SAPER");
    text_1.setPosition(400,50);
    text_1.setFillColor(sf::Color::Green);
    win.draw(text_1);

    text_1.setFillColor(sf::Color::Green);
    text_1.setCharacterSize(25);

    text_1.setString("10x10");
    text_1.setPosition(50,355);
    win.draw(text_1);

    text_1.setString("15x15");
    text_1.setPosition(50,455);
    win.draw(text_1);

    text_1.setString("30x15");
    text_1.setPosition(50,555);
    win.draw(text_1);

    text_1.setString("EASY");
    text_1.setPosition(240,355);
    win.draw(text_1);

    text_1.setString("NORMAL");
    text_1.setPosition(225,455);
    win.draw(text_1);

    text_1.setString("HARD");
    text_1.setPosition(240,555);
    win.draw(text_1);

    win.draw(circle);

    text_1.setString("START");
    text_1.setPosition(750, 480);
    win.draw(text_1);


}
