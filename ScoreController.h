//
// Created by User on 10.05.2020.
//

#ifndef SNAKE_LUK_SCORECONTROLLER_H
#define SNAKE_LUK_SCORECONTROLLER_H

#include "ScoreView.h"


class ScoreController {
    ScoreView &view;
    bool finished = false;
    bool again = false;
public:
    ScoreController(ScoreView &v);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win){view.draw(win);}
    bool isFinished() const { return finished;}
    bool playAgain() { return again; }
    void setPlayAgainToFalse() { again = false; }
    void setFinishedToFalse() { finished = false; }
};


#endif //SNAKE_LUK_SCORECONTROLLER_H
