//
// Created by User on 09.03.2020.
//

#ifndef PO_L2_MINESWEAPERBOARD_H
#define PO_L2_MINESWEAPERBOARD_H
#include <vector>
using namespace std;
enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { START, RUNNING, FINISHED_WIN, FINISHED_LOSS };



struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


class MinesweeperBoard
{
    vector<vector<Field>>board;
    int width;
    int height;
    GameState state;
    int mine_count;

public:

    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool isOutside(int x, int y) const;
    bool isRevealed(int x, int y) const;
    bool hasFlag(int x, int y) const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;

};
#endif //PO_L2_MINESWEAPERBOARD_H
