//
// Created by User on 10.05.2020.
//

#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &v): view(v)
{
    finished = false;
    again = false;

}
void ScoreController::handleEvent(sf::Event &event)
{
    finished = false;
    again = false;
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Space)
        {
            finished = true;
            again = true;
        }
    }
}
