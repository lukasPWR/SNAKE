//
// Created by User on 19.04.2020.
//

#include "GameManager.h"
GameManager::GameManager (ScoreViewController &svc,StartScreenController &sc,MinesweeperController&mc):
        scoreViewC(svc), startScreenC(sc), minesweeperBoardC(mc)
        {
    state=START;
        }
        void GameManager::statee(){

        switch(state)
        {
            case START:
                if(startScreenC.isFinished())
                {
                    state=GAME;
                }
                break;
            case GAME:
                if(minesweeperBoardC.isFinished())
                {
                    state= SCORE;
                }
                break;
            case SCORE:
                break;
        }
    }



void GameManager::handleEvent(sf::Event &event) {
    switch (state) {
        case START:
            startScreenC.handleEvent(event);
            break;
        case GAME:
            minesweeperBoardC.handleEvent(event);
            break;
        case SCORE:
            scoreViewC.handleEvent(event);
            break;
    }

    statee();

}
void GameManager::draw(sf::RenderWindow &win) {


        switch (state) {
            case START:
                startScreenC.draw(win);
                break;
            case GAME:
                minesweeperBoardC.drawOnWindow(win);
                break;
            case SCORE:
                scoreViewC.draw(win);
                if (scoreViewC.isFinished())
                    win.close();
                break;
        }
    }




