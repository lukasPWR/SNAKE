//
// Created by User on 19.04.2020.
//
#include <SFML/Graphics.hpp>
void test();
void test () {
    sf::RenderWindow win{sf::VideoMode{1100, 800}, "test"};
    sf::Event event;

    while (win.isOpen()) {

        sf::Event event;
        while (win.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color::Black);
        win.display();
    }
}