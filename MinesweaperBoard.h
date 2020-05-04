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
    GameMode  mode;
    int mine_count;
    void setMines(double part);

public:

    MinesweeperBoard(int width, int height, GameMode M);
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
    bool hasMine(int x, int y) const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;
    void reset_board(int x, int y , GameMode mode);


};
#endif //PO_L2_MINESWEAPERBOARD_
