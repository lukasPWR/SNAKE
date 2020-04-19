//
// Created by User on 19.04.2020.
//

#include "StartScreenController.h"
StartScreenController::StartScreenController(StartScreen &ssv, MinesweeperBoard &b):view(ssv), board(b)
{}
int StartScreenController::get_x() const
{
    return x;
}

int StartScreenController::get_y() const
{
    return y;
}

GameMode StartScreenController::getMode() const
{
    return mode;
}

void StartScreenController::handleEvent(sf::Event &event)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if ((event.mouseButton.x > 35) && (event.mouseButton.x < 155))
            {
                if ((event.mouseButton.y > 350) && (event.mouseButton.y < 400))

                {
                    view.rectangleOutline(0,0, true);
                    view.rectangleOutline(0,2,false);
                    view.rectangleOutline(0,4,false);
                    x=10;
                    y=10;
                }
                else if ((event.mouseButton.y > 450) && (event.mouseButton.y < 500))
                {
                    view.rectangleOutline(0,2,true);
                    view.rectangleOutline(0,0,false);
                    view.rectangleOutline(0,4,false);
                    x=10;
                    y= 15;

                }
                else if ((event.mouseButton.y > 550) && (event.mouseButton.y < 600)) {
                    view.rectangleOutline(0, 4, true);
                    view.rectangleOutline(0,0,false);
                    view.rectangleOutline(0,2,false);
                    x = 30;
                    y = 15;
                }

            }
            if ((event.mouseButton.x > 220) && (event.mouseButton.x < 340))
            {
                if ((event.mouseButton.y > 350) && (event.mouseButton.y < 390))
                {
                    view.rectangleOutline(0,1,true);
                    view.rectangleOutline(0,3,false);
                    view.rectangleOutline(0,5,false);
                    mode = EASY;
                }
                else if ((event.mouseButton.y > 450) && (event.mouseButton.y < 490))
                {
                    view.rectangleOutline(0,3,true);
                    view.rectangleOutline(0,1,false);
                    view.rectangleOutline(0,5,false);
                    mode = NORMAL;
                }
                else if ((event.mouseButton.y > 550) && (event.mouseButton.y < 590))
                {
                    view.rectangleOutline(0,5,true);
                    view.rectangleOutline(0,3,false);
                    view.rectangleOutline(0,1,false);
                    mode = HARD;
                }
            }
        }
    }
    if ((event.mouseButton.x > 700) && (event.mouseButton.x < (700 + 2 * 170)) && (event.mouseButton.y > 400) && (event.mouseButton.y < (400 + 2 * 170)))
    {
        view.circleOutline();
        board.reset_board(get_x(), get_y(), getMode());

        finished = true;
    }
}

