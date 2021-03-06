//
// Created by User on 10.05.2020.
//

#include "GameMenager.h"

GameMenager::GameMenager(SnakeController &snc, MenuController &mc,ScoreController &sc, SnakeBoard &b):snakeC(snc), menuC(mc),scoreC(sc),board(b)
{
    state=MENU;



}
void GameMenager::update()
{
    switch(state)
    {
        case MENU:
            if(menuC.isFinished())
            {
                state=GAME;
            }
            break;
        case GAME:
            if(snakeC.isFinished())
            {
                state=SCORE;
            }
            break;
        case SCORE:
            if(scoreC.isFinished())
            {
                menuC.setFinishedToFalse();
                state=MENU;
                snakeC.setFinishedToFalse();
                snakeC.playAgain();



                



            }

            break;

    }

}


void GameMenager::handleEvent(sf::Event &event)
{
    switch(state) {
        case MENU:
            menuC.handleEvent(event);
            break;
        case GAME:
            snakeC.handleEvent(event);
            break;
        case SCORE:
            scoreC.handleEvent(event);
            break;
    }
    update();

}
void GameMenager::draw(sf::RenderWindow &win)
{
    switch(state)
    {
        case MENU:
            menuC.draw(win);
            break;
        case GAME:
            snakeC.draw(win);
            break;
        case SCORE:
            scoreC.draw(win);
            break;
    }

}
