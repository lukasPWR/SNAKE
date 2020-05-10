//
// Created by User on 28.04.2020.
////

#pragma once
#include <iostream>
#include <vector>
using  namespace std;

enum GameState { RUNNING, FINISHED_LOSS };
enum Direction {RIGHT, LEFT, UP, DOWN};

struct Field
{
    bool hasFood;
    bool isWall;
    bool hasSnake;
};

struct snakePosition
{
    int x;
    int y;
};

class SnakeBoard
{
    vector<vector<Field>> board;
    vector <snakePosition> snake_Pos;
    int winHeight;
    int winWidth;
    int height;
    int width;
    GameState state;
    Direction direction;
    void setFeed();
public:
    SnakeBoard(int windowHeight, int windowWidth);
    void debug_display() const;
    int getWindowHeight() const { return winHeight; }
    int getWindowWidth() const { return winWidth; }
    int getBoardHeight() const { return height; }
    int getBoardWidth() const { return width; }
    bool hasSnake(int x, int y) const;
    bool isWall(int x, int y) const;
    bool hasFood(int x, int y) const;
    bool isCollision(int x, int y) const;
    GameState getGameState() const;
    int getSnakeLength() const;
    void changeDirection(Direction dir);
    void move();
    bool isFoodEaten();
    char getFieldInfo(int x, int y) const;
};




