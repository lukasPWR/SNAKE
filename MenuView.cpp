//
// Created by User on 06.05.2020.
//

#include "MenuView.h"

MenuView::MenuView(SnakeBoard &sb): board(sb)
{

    playButton.setSize(sf::Vector2f(board.getWindowWidth() / 3, board.getWindowHeight() / 12));
    playButton.setPosition(board.getWindowWidth() / 3,board.getWindowHeight() - board.getWindowHeight() / 4);
    playButton.setFillColor(sf::Color(48, 86, 48));

    if (!font2.loadFromFile("courier-new.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    text1.setFont(font2);
    text1.setCharacterSize(board.getWindowHeight()/30);
    text1.setString("GRAJ");
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(board.getWindowWidth()/2.2, board.getWindowHeight() - board.getWindowHeight()/4.3);

    if (!font1.loadFromFile("snake.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    text2.setFont(font1);
    text2.setCharacterSize(board.getWindowHeight()/4);
    text2.setPosition(board.getWindowWidth()/12,board.getWindowHeight()/5);
    text2.setString("SNAKE");
    text2.setFillColor(sf::Color::Red);

}

void MenuView::draw(sf::RenderWindow &win)
{
    win.draw(playButton);
    win.draw(text1);
    win.draw(text2);


}