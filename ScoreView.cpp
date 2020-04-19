//
// Created by User on 19.04.2020.
//

#include "ScoreView.h"
#include "MinesweaperBoard.h"
#include <iostream>

ScoreView::ScoreView(MinesweeperBoard & b) : board(b) {

    if (!font_1.loadFromFile("arial-black.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    text_1.setFont(font_1);
    text_2.setFont(font_1);
    text_3.setFont(font_1);



    text_1.setFont(font_1);
    text_1.setCharacterSize(170);
    text_1.setStyle(sf::Text::Regular);
    text_1.setString("PORAZKA");
    text_1.setPosition(150, 200);
    text_1.setFillColor(sf::Color::Red);

    text_2.setFont(font_1);
    text_2.setCharacterSize(100);
    text_2.setStyle(sf::Text::Regular);
    text_2.setString("Gratulacje!");
    text_2.setPosition(180, 200);
    text_2.setFillColor(sf::Color::Red);

    text_3.setFont(font_1);
    text_3.setCharacterSize(20);
    text_3.setStyle(sf::Text::Regular);
    text_3.setString("nacisnij spacje zeby wrocic do menu");
    text_3.setFillColor(sf::Color::White);
    text_3.setPosition(360, 550);

}
void ScoreView::draw(sf::RenderWindow &win)
{
    if(board.getGameState() == FINISHED_WIN)
    {
        win.draw(text_2);
    }
    if(board.getGameState() == FINISHED_LOSS)
    {
        win.draw(text_1);
    }
    win.draw(text_3);
}