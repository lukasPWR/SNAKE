#include <iostream>
#include <vector>
#include "MinesweaperBoard.h"
#include <iostream>
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

using namespace std;

int main() {
    MinesweeperBoard b(10,10,HARD);
    MSSFMLView mv(b);
    b.toggleFlag(1,1);
    b.revealField(2,3);
    sf::RenderWindow w{ sf::VideoMode{1100, 800}, "MINESWEEPER" };

    w.setFramerateLimit(60);
    sf::Event event;

    while (w.isOpen()) {

        sf::Event event;
        while (w.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                w.close();


        }

        w.clear(sf::Color::Magenta);
        mv.drawOnWindow(w);

        w.display();
    }

    return 0;

}