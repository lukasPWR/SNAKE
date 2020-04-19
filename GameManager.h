//
// Created by User on 19.04.2020.
//

#ifndef SAPER_GAMEMANAGER_H
#define SAPER_GAMEMANAGER_H

#include "ScoreViewController.h"
#include "StartScreenController.h"
#include "MinesweeperController.h"


class GameManager {
    ScoreViewController &scoreViewC;
    StartScreenController &startScreenC;
    MinesweeperController &minesweeperBoardC;
    enum GameState{START, GAME, SCORE} state;
    void statee();
public:
    GameManager (ScoreViewController &svc,StartScreenController &sc,MinesweeperController &mc);
    void draw(sf::RenderWindow &win);
    void handleEvent(sf::Event &event);

};


#endif //SAPER_GAMEMANAGER_H
