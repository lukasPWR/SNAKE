#include <iostream>
#include <vector>
#include "MinesweaperBoard.h"
#include <iostream>
#include "MSBoardTextView.h"
using namespace std;

int main() {
    MinesweeperBoard board (20, 10, GameMode::EASY);
    MSBoardTextView view ( board );
    view.display();
    board.revealField(0,5);
    view.display();



}