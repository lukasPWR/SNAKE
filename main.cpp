#include <iostream>
#include "SnakeBoard.h"
#include "SnakeBoardView.h"
#include "SnakeController.h"
#include "MenuView.h"
#include "MenuController.h"
#include "ScoreView.h"
#include "ScoreController.h"
#include "GameMenager.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    SnakeBoard sb(1000,1000);
    SnakeBoardView sbv(sb);
    SnakeController sc(sbv, sb);

    MenuView mv(sb);
    MenuController mc(sb,mv);

    ScoreView sv(sb);
    ScoreController scc(sv);

    GameMenager gm(sc,mc,scc);



    unsigned int width;
    unsigned int height;

    width = (unsigned)sb.getWindowWidth();
    height = (unsigned)sb.getWindowHeight();





    sf::RenderWindow w{ sf::VideoMode{width, height}, "SNAKE" };

    w.setFramerateLimit(60);
    sf::Event event;

    while (w.isOpen()) {

        sf::Event event;
        while (w.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                w.close();
            }
                scc.handleEvent(event);





        }


        w.clear();
        sv.draw(w);


        w.display();
    }

    return 0;


}
