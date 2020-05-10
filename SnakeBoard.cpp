//
// Created by User on 28.04.2020.
#include "SnakeBoard.h"
using namespace std;


SnakeBoard::SnakeBoard(int windowHeight, int windowWidth)
{
    winHeight=windowHeight;
    winWidth=windowWidth;
    height=winHeight/40;
    width=winWidth/40;
    state=RUNNING;
    direction=RIGHT;
    board.resize(100);
    for(int i=0; i<board.size();i++)
    {
        board.at(i).resize(100);
    }

    for(int i=0;i<height;++i)
    {
        for(int k=0;k<width;++k)
        {
            board.at(k).at(i).hasFood = false;
            board.at(k).at(i).hasSnake = false;
            board.at(k).at(i).isWall = false;
        }
    }
    for(int j=0;j<100;++j)
    {
        board.at(j).at(0).isWall = true;
        board.at(j).at(width-1).isWall = true;
        board.at(0).at(j).isWall = true;
        board.at(height-1).at(j).isWall = true;
    }
    snakePosition hP ={width/2,height/2}; //head position
    snake_Pos.push_back(hP);

    snakePosition sP ={width/2,height/2-1};
    snake_Pos.push_back(sP);


    for(int i=0;i<snake_Pos.size(); ++i)
    {
        board.at(snake_Pos[i].y).at(snake_Pos[i].x).hasSnake=true;
    }
    setFeed();
}

void SnakeBoard::debug_display() const
{
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<width;++j)
        {
            cout << getFieldInfo(i, j);
        }
        cout << endl;
    }
}

void SnakeBoard::setFeed()
{
    int x=0;
    int y=0;
    do
    {
        x=rand()% height;
        y=rand()% width;
    }
    while (board.at(y).at(x).hasSnake == true || board.at(y).at(x).isWall == true);
    board.at(y).at(x).hasFood = true;
}


bool SnakeBoard::hasSnake(int x, int y) const
{
    if (board.at(y).at(x).hasSnake == true && board.at(y).at(x).isWall == false)
        return true;
    else
        return false;
}

bool SnakeBoard::isWall(int x, int y) const
{
    if (board.at(y).at(x).isWall == true)
        return true;
    else
        return false;
}


bool SnakeBoard::hasFood(int x, int y) const
{
    if (board.at(y).at(x).hasFood == true)
        return true;
    else
        return false;
}

bool SnakeBoard::isCollision(int x, int y) const
{
    if(board.at(y).at(x).isWall)
    {
        return true;
    }
    for(int i=0;i<snake_Pos.size();++i)
    {
        if (snake_Pos[i].x == x && snake_Pos[i].y == y)
        {
            return true;
        }
    }
    return false;
}

GameState SnakeBoard::getGameState() const
{
    return state;
}

int SnakeBoard::getSnakeLength() const
{
    return snake_Pos.size()-2;
}

void SnakeBoard::changeDirection(Direction dir)
{
    if (dir == RIGHT && direction != LEFT)
    {
        direction = RIGHT;
    }
    if (dir == LEFT && direction != RIGHT)
    {
        direction = LEFT;
    }
    if (dir == UP && direction != DOWN)
    {
        direction = UP;
    }
    if (dir == DOWN && direction != UP)
    {
        direction = DOWN;
    }
}

void SnakeBoard::move()// "zerkalem" do https://forum.pasja-informatyki.pl/250831/skrecanie-weza-w-grze-snake
{
    snakePosition newPos;
    if (direction == RIGHT)
    {
        newPos.x = snake_Pos[0].x+1;
        newPos.y = snake_Pos[0].y;
    }
    if (direction == LEFT)
    {
        newPos.x = snake_Pos[0].x-1;
        newPos.y = snake_Pos[0].y;
    }
    if (direction == UP)
    {
        newPos.x = snake_Pos[0].x;
        newPos.y = snake_Pos[0].y-1;
    }
    if (direction == DOWN)
    {
        newPos.x = snake_Pos[0].x;
        newPos.y = snake_Pos[0].y+1;
    }

    if(isCollision(newPos.x, newPos.y) == false)
    {
        if(isFoodEaten()==true)
        {
            board.at(newPos.y).at(newPos.x).hasSnake = true;
            snake_Pos.insert(snake_Pos.begin(), newPos);
            setFeed();
        }
        else
        {
            board.at(newPos.y).at(newPos.x).hasSnake = true;
            snake_Pos.insert(snake_Pos.begin(), newPos);
            board.at(snake_Pos[snake_Pos.size()-1].y).at(snake_Pos[snake_Pos.size()-1].x).hasSnake=false;
            snake_Pos.pop_back();
        }
    }
    else state = FINISHED_LOSS;
}

bool SnakeBoard::isFoodEaten()
{
    for(int i=0; i<snake_Pos.size();++i)
    {
        if (board.at(snake_Pos[0].y).at(snake_Pos[0].x).hasFood == true)
        {
            board.at(snake_Pos[0].y).at(snake_Pos[0].x).hasFood == false;
            return true;
        }
    }
    return false;
}


char SnakeBoard::getFieldInfo(int x, int y) const
{
    if(board.at(y).at(x).hasFood == true)
        return 'F';
    if(board.at(y).at(x).hasSnake == true)
        return 'S';
    if(board.at(y).at(x).isWall == true)
        return 'W';
    else return '-';
}


