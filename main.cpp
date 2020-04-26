#include <iostream>
#include <vector>
#include "MinesweaperBoard.h"
#include <iostream>
#include "MSBoardTextView.h"
#include "MSTextController.h"

#include "MSSFMLView.h"
#include "MinesweeperController.h"

#include "StartScreen.h"
#include "StartScreenController.h"

#include "ScoreView.h"
#include "ScoreViewController.h"

#include "GameManager.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));


    MinesweeperBoard b(10, 10, EASY);



    MSSFMLView mv(b);
    MinesweeperController mc(mv, b);

    StartScreen sc;
    StartScreenController ssc(sc, b);

    ScoreView sv(b);
    ScoreViewController svc(sv);

    GameManager gm(svc, ssc, mc);


    sf::RenderWindow w{sf::VideoMode{1100, 800}, "MINESWEEPER"};

    w.setFramerateLimit(60);

        sf::Event event;

        while (w.isOpen()) {

            sf::Event event;
            while (w.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    w.close();
                b.toggleFlag(0,0);
                b.revealField(0,0);

                gm.handleEvent(event);

            }

            w.clear();

            gm.draw(w);

            w.display();
        }

        return 0;

    }


