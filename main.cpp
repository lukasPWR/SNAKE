#include <iostream>
#include "SnakeBoard.h"
#include "SnakeBoardView.h"
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

int main() {

    SnakeBoard b(920,920);
    SnakeBoardView sbv(b);
    unsigned int width;
    unsigned int height;

    width = (unsigned)b.getWindowWidth();
    height = (unsigned)b.getWindowHeight();


    sf::RenderWindow win{ sf::VideoMode{width, height}, "SNAKE" };

    win.setFramerateLimit(60);

    sf::Event event;

    while (win.isOpen()) {

        sf::Event event;
        while (win.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                win.close();

        }


        win.clear();
        sbv.drawOnWindow(win);

        win.display();
    }

    return 0;



}
