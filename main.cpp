#include <iostream>
#include <vector>
#include "MinesweaperBoard.h"
#include <iostream>
using namespace std;

int main() {
MinesweeperBoard board(10,10, HARD);
MinesweeperBoard game(10,10,HARD);
game.debug_display();
cout << game.getBoardHeight() << endl << game.getBoardWidth()<< endl << game.getMineCount();
    return 0;
}