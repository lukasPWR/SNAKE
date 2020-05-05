//
// Created by User on 28.04.2020.
////

#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H

#include <vector>
#include <iostream>
using namespace std;
enum GameState{RUNNING, FINISHED_LOSS};
enum Direction{LEFT,RIGHT,UP,DOWN};

struct Field
        {
    bool hasFood;
    bool hasSnake;
    bool isWall;
        };
struct SnakePos
        {
    int x;
    int y;
        };
class SnakeBoard
        {
    vector<vector<Field>> board;
    vector<SnakePos> snake_pos;
    int height;
    int width;
    int win_height;
    int win_width;
    GameState state;
    Direction direction;

        public:
            SnakeBoard(int windowHeight, int windowWidth);
            void debug_display() const;
            int getWindowHeight() const{ return win_height;}
            int getWindowWidth() const {return win_width;}
            int getBoardHeight() const {return height;}
            int getBoardWidth() const {return width;}
            bool hasFood(int x, int y)const;
            bool hasSnake(int x, int y)const;
            bool isWall(int x, int y)const;
            bool isCollision(int x, int y)const;
            GameState getGameState()const;
            int getSnakeSize()const;
            char getFieldInfo(int x, int y)const;
            void setFood()const;
            bool isFoodEaten() const;
            Direction changeDirection(Direction dir);
            void move() ;




        };





#endif //SNAKE_SNAKEBOARD_H
