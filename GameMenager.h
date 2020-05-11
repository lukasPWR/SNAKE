//
// Created by User on 10.05.2020.
//

#ifndef SNAKE_LUK_GAMEMENAGER_H
#define SNAKE_LUK_GAMEMENAGER_H

#include "SnakeBoard.h"
#include "SnakeController.h"
#include "MenuController.h"
#include "ScoreController.h"



class GameMenager {
    SnakeBoard &board;
    SnakeController &snakeC;
    MenuController &menuC;
    ScoreController &scoreC;
    void update();
    enum GameState {MENU,GAME,SCORE} state;
public:
    GameMenager(SnakeController &snc, MenuController &mc,ScoreController &sc, SnakeBoard &b);
    void draw(sf::RenderWindow &win);
    void handleEvent(sf::Event &event);



};


#endif //SNAKE_LUK_GAMEMENAGER_H
