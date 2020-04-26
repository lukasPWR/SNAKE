//
// Created by User on 16.04.2020.
//

#include "MinesweeperController.h"


MinesweeperController::MinesweeperController(MSSFMLView & v, MinesweeperBoard & b) : view(v), board(b)
{
}

void MinesweeperController::handleEvent(sf::Event & event)
{
    if (event.type == sf::Event::MouseButtonPressed && board.getGameState() == RUNNING)
    {
        for(int i=0; i< board.getBoardHeight(); ++i)
        {
            for( int j=0; j< board.getBoardWidth(); ++j)
            {
                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    if((event.mouseButton.y> 35+ i*35) && (event.mouseButton.y< 70+ i*35) && (event.mouseButton.x> 35+ j*35) && (event.mouseButton.x< 70+ j*35) )
                    {
                        board.toggleFlag(i, j);
                    }
                }
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if((event.mouseButton.y> 35+ i*35) && (event.mouseButton.y< 70+ i*35) && (event.mouseButton.x> 35+ j*35) && (event.mouseButton.x< 70+ j*35) )
                    {
                        board.revealField(i, j);
                    }
                }
            }
        }

    }
    if (board.getGameState() != RUNNING)
    {
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space)
            {
                finished = true;
            }

        }
    }

}

