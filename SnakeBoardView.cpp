//
// Created by User on 04.05.2020.
////

#include <Windows.h>

#include "SnakeBoardView.h"
#include <Windows.h>


SnakeBoardView::SnakeBoardView(SnakeBoard & b) : board(b)
{
    //tlo
    if (!background_txt.loadFromFile("background.jpg"))
    {
        std::cout << "error" << std::endl;
        system("pause");

    }
    background.setSize(sf::Vector2f(board.getWindowWidth(), board.getWindowWidth()));
    background.setTexture(&background_txt);
    //sciana
    if (!wall_txt.loadFromFile("wall.jpg"))
    {
        cout << "error" << endl;
        system("pause");

    }
    wall.setSize(sf::Vector2f(board.getWindowWidth() / board.getBoardWidth(), board.getWindowHeight() / board.getBoardHeight()));
    wall.setTexture(&wall_txt);
    //waz
    snake.setSize(sf::Vector2f((board.getWindowWidth() / board.getBoardWidth()), (board.getWindowHeight() / board.getBoardHeight())));
    snake.setFillColor(sf::Color(48, 86, 48));
    snake.setOutlineThickness(3);
    snake.setOutlineColor(sf::Color::Blue);


    if (!food_txt.loadFromFile("images.png"))
    {
       cout << "error" << endl;
        system("pause");

    }
    food.setSize(sf::Vector2f(1.1*(board.getWindowWidth() / board.getBoardWidth()), 1.1*(board.getWindowHeight() / board.getBoardHeight())));
    food.setTexture(&food_txt);

    if (!font.loadFromFile("silkscreen.ttf"))
    {
        cout << "error " << endl;
        system("pause");
    }

    score.setFont(font);
    score.setCharacterSize(board.getWindowHeight() / 50);
    score.setFillColor(sf::Color::Black);
    score.setPosition(board.getWindowWidth() / 2.5, 0);

    space.setFont(font);
    space.setCharacterSize(board.getWindowHeight() / 50);
    space.setString("nacisnij spacje aby zobaczyc wynik");
    space.setFillColor(sf::Color::Black);
    space.setPosition(board.getWindowWidth() / 4, board.getWindowHeight()/2);
}



void SnakeBoardView::draw(sf::RenderWindow & w)
{
    board.move();
    w.draw(background);
    for(int i=0; i<board.getBoardHeight(); ++i)
    {
        for (int j=0; j<board.getBoardWidth(); ++j)
        {
            if (board.getFieldInfo(j, i) == 'S')
            {
                snake.setPosition(sf::Vector2f(j*(board.getWindowWidth() / board.getBoardWidth()), i*(board.getWindowHeight() / board.getBoardHeight())));
                w.draw(snake);
            }
            if (board.getFieldInfo(j, i) == 'F')
            {
                food.setPosition(sf::Vector2f(j*(board.getWindowWidth() / board.getBoardWidth()), i*(board.getWindowHeight() / board.getBoardHeight())));
                w.draw(food);
            }
            if (board.getFieldInfo(j, i) == 'W')
            {
                wall.setPosition(sf::Vector2f(j*(board.getWindowWidth() / board.getBoardWidth()), i*(board.getWindowHeight() / board.getBoardHeight())));
                w.draw(wall);
            }

        }
    }
    score.setString("Wynik:" + std::to_string(board.getSnakeLength()));
    w.draw(score);

    if (board.getGameState() != RUNNING)
    {
        w.draw(space);
    }
    Sleep(150);
}
