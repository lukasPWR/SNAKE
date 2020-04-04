#include <iostream>
#include <vector>
#include "MinesweaperBoard.h"
#include <iostream>
#include "MSBoardTextView.h"
#include "MSTextController.h"
using namespace std;

int main() {
    MinesweeperBoard board (20, 10, GameMode::EASY);
    MSBoardTextView view ( board );
    MSTextController ctrl ( board, view );
    ctrl.play();








}