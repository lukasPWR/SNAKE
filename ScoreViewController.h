//
// Created by User on 19.04.2020.
//

#ifndef SAPER_SCOREVIEWCONTROLLER_H
#define SAPER_SCOREVIEWCONTROLLER_H
#include <SFML/Graphics.hpp>
#include "ScoreView.h"
#include "MinesweaperBoard.h"

class ScoreViewController {
    ScoreView &view;
    bool finished = false;
public:
    explicit ScoreViewController(ScoreView & v);
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished; }
};

#endif