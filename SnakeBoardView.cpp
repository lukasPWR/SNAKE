//
// Created by User on 04.05.2020.
////

#include "SnakeBoardView.h"
#include <Windows.h>

SnakeBoardView::SnakeBoardView(SnakeBoard &b): board(b)
{

}

void SnakeBoardView::drawOnWindow(sf::RenderWindow &win)
{

    //tlo
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(board.getWindowWidth(),board.getWindowWidth()));
    background.setFillColor(sf::Color::Magenta);
    //sciany
    sf::RectangleShape wall;
    wall.setSize(sf::Vector2f(board.getWindowWidth()/board.getWindowWidth(),board.getWindowHeight()/board.getWindowHeight()));
    wall.setFillColor((sf::Color::Black));
    wall.setOutlineThickness(3);
    wall.setOutlineColor(sf::Color::White);
    //segmenty
    sf::RectangleShape snake_body;
    snake_body.setSize(sf::Vector2f(board.getWindowWidth()/board.getBoardWidth(),board.getWindowHeight()/board.getBoardHeight()));
    snake_body.setFillColor(sf::Color::Green);
    //glowa
    sf::RectangleShape snake_head;
    snake_head.setSize(sf::Vector2f(board.getWindowWidth()/board.getBoardWidth(),board.getWindowHeight()/board.getBoardHeight()));
    snake_head.setFillColor(sf::Color(0,35,34));
    //jedzonko
    sf::RectangleShape food;
    sf::Texture food_txt;
    if (!food_txt.loadFromFile("images.png"))
    {
        std::cout << "error" << endl;
        system("pause");
    }

    food.setSize(sf::Vector2f(1.25*(board.getWindowWidth()/board.getBoardWidth()),1.25*(board.getWindowHeight()/board.getBoardHeight())));
    food.setTexture(&food_txt);

    sf::Font font;
    sf::Text score;
    sf::Text end_caption;
    if(!font.loadFromFile("silkscreen.ttf"))
    {
        std::cout << "error" << endl;
        system("pause");
    }
    score.setFont(font);
    score.setCharacterSize(board.getWindowHeight()/50);
    score.setFillColor(sf::Color::Cyan);
    score.setPosition(board.getWindowWidth() / 2.3, 0);
    end_caption.setFont(font);
    end_caption.setCharacterSize(board.getWindowHeight()/50);
    end_caption.setFillColor(sf::Color::Cyan);
    end_caption.setPosition(board.getWindowWidth() / 4, board.getWindowHeight()/2);

    board.move();
    win.draw(background);

    for(int i = 0; i< board.getBoardHeight();++i)
    {
        for(int j=0; j< board.getBoardWidth(); ++j)
        {
            if(board.getFieldInfo(j,i) == 'S')
            {
                snake_body.setPosition(sf::Vector2f(j*(board.getWindowWidth()/board.getBoardWidth()),i*(board.getWindowHeight()/board.getBoardHeight())));
                win.draw(snake_body);
            }
            if(board.getFieldInfo(j,i) == 'W')
            {
                wall.setPosition(sf::Vector2f(j*(board.getWindowWidth()/board.getBoardWidth()),i*(board.getWindowHeight()/board.getBoardHeight())));
                win.draw(wall);
            }
            if(board.getFieldInfo(j,i) == 'F')
            {
                food.setPosition(sf::Vector2f(j*(board.getWindowWidth()/board.getBoardWidth()),i*(board.getWindowHeight()/board.getBoardHeight())));
                win.draw(food);
            }
        }
    }
    score.setString("Wynik: "+ to_string(board.getSnakeSize()));
    win.draw(score);
    if (board.getGameState() != RUNNING)
    {
        win.draw(end_caption);
    }

}
