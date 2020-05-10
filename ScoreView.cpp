//
// Created by User on 06.05.2020.
//

#include "ScoreView.h"

ScoreView::ScoreView(SnakeBoard &sb):board(sb)
{
    if (!font1.loadFromFile("arial-black.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }
    gameOver.setFont(font1);
    gameOver.setFillColor(sf::Color::Red);

    if (!font2.loadFromFile("silkscreen.ttf"))
    {
        std::cout << "error " << std::endl;
        system("pause");
    }

    scoreText.setFont(font2);
    scoreText.setCharacterSize(board.getWindowHeight() / 50);
    scoreText.setFillColor(sf::Color::White);

}
void ScoreView::draw(sf::RenderWindow &win)
{
    gameOver.setPosition(board.getWindowWidth() / 6, board.getWindowHeight() / 9);
    gameOver.setString("Przegrana");
    gameOver.setCharacterSize(board.getWindowHeight() / 8);
    win.draw(gameOver);


    scoreText.setString("Twoj wynik: " + std::to_string(board.getSnakeLength()));
    scoreText.setPosition(board.getWindowWidth() / 2.7, board.getWindowHeight() / 1.5);
    win.draw(scoreText);

    scoreText.setString("nacisnij spacje aby wrocic do menu");
    scoreText.setPosition(board.getWindowWidth() / 5, board.getWindowHeight() / 1.3);
    win.draw(scoreText);
}
