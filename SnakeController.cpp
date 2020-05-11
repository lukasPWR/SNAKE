//
// Created by User on 05.05.2020.
//

#include <synchapi.h>
#include "SnakeController.h"




SnakeController::SnakeController(SnakeBoardView & v, SnakeBoard & b) : view(v), board(b)
{
}

void SnakeController::handleEvent(sf::Event & event)
{
    if (event.type == sf::Event::KeyPressed && board.getGameState()==RUNNING)
    {
        if (event.key.code == sf::Keyboard::D)
        {
            board.changeDirection(RIGHT);
        }
        if (event.key.code == sf::Keyboard::A)
        {
            board.changeDirection(LEFT);
        }
        if (event.key.code == sf::Keyboard::W)
        {
            board.changeDirection(UP);
        }
        if (event.key.code == sf::Keyboard::S)
        {
            board.changeDirection(DOWN);
        }
    }



    if (board.getGameState() == FINISHED_LOSS)
    {


        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
                finished = true;
            }
        }
    }

}
