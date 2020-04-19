//
// Created by User on 19.04.2020.
//

#include "ScoreViewController.h"

ScoreViewController::ScoreViewController(ScoreView &v): view(v)
{}


void ScoreViewController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space)
        {
            finished = true;
        }
    }

}