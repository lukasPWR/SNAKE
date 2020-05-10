//
// Created by User on 06.05.2020.
//

#include "MenuController.h"

MenuController::MenuController(SnakeBoard &sb, MenuView &v): board(sb), view(v)
{

}
void MenuController::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if ((event.mouseButton.x > board.getWindowWidth() / 3) && (event.mouseButton.x < board.getWindowWidth() / 3 + board.getWindowWidth() / 3) && (event.mouseButton.y > board.getWindowHeight() - board.getWindowHeight() / 4) && (event.mouseButton.y < board.getWindowHeight() - board.getWindowHeight() / 4 + board.getWindowHeight() / 12))
            {
                finished = true;
            }
        }
    }
}
