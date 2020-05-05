//
// Created by User on 28.04.2020.
////

#include "SnakeBoard.h"

SnakeBoard::SnakeBoard(int windowHeight, int windowWidth) {
    win_height = windowHeight;
    win_width = windowWidth;
    height = win_height / 40;
    width = win_width / 40;
    state = RUNNING;

    board.resize(100);

    for (int i = 0; i < board.size(); ++i) {
        board.at(i).resize(100);
    }
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.at(i).size(); j++)
        {
            board.at(i).at(j).hasFood = false;
            board.at(i).at(j).hasSnake = false;
            board.at(i).at(j).isWall = false;
        }
    }
    for (int k = 0; k < 100; ++k) {
        board.at(k).at(0).isWall = true;
        board.at(k).at(width - 1).isWall = true;
        board.at(0).at(k).isWall = true;
        board.at(height - 1).at(k).isWall = true;
    }

    SnakePos Sp_1 = {width / 2, height / 2};
    snake_pos.push_back(Sp_1);
    SnakePos Sp_2 = {width / 2, height / 2 -1};
     snake_pos.push_back(Sp_2);

    for (int l = 0; l < snake_pos.size(); ++l) {
        board.at(snake_pos[l].y).at(snake_pos[l].x).hasSnake = true;
    }
    setFood();


}
void SnakeBoard::debug_display() const
{
    for(int i=0; i<getBoardHeight();++i)
    {
        for(int j=0; j<getBoardWidth(); ++j)
        {
            cout << getFieldInfo(i,j);
        }
        cout << endl;
    }
}
void SnakeBoard::setFood()const
{
    int x=0;
    int y=0;
    do
    {
        x = rand()% height;
        y= rand()% width;
        if(board.at(y).at(x).hasSnake)
        {
            board.at(y).at(x).hasFood == true;
        }
    } while(board.at(y).at(x).hasFood);


}
bool SnakeBoard::hasSnake(int x, int y) const
{
    if(board.at(y).at(x).isWall == false && board.at(y).at(x).hasSnake == true)
    {
        return true;
    }
    else
        return false;

}
bool SnakeBoard::isWall(int x, int y)const
{
    if(board.at(y).at(x).isWall == true)
    {
        return true;
    }
    else
        return false;
}
bool SnakeBoard::hasFood(int x, int y) const
{
    if(board.at(y).at(x).hasFood == true)
    {
        return true;
    }
    else
        return false;
}
char SnakeBoard::getFieldInfo(int x, int y) const
{
    if(board.at(y).at(x).hasFood ==  true)
    {
        return 'F';
    }
    if(board.at(y).at(x).isWall == true)
    {
        return 'W';
    }
    if(board.at(y).at(x).hasSnake)
    {
        return 'S';
    }
    else
        return '_';
}
bool SnakeBoard::isCollision(int x, int y)const
{
    if(board.at(y).at(x).isWall)
    {
        return true;
    }
    for(int i=0; i<snake_pos.size(); ++i)
    {
        if(snake_pos[i].x == x && snake_pos[i].y == y)
        {
            return true;
        }
    }
}
GameState SnakeBoard:: getGameState()const
{
    return state;
}
int SnakeBoard::getSnakeSize()const
{
    return snake_pos.size()-2;
}
bool SnakeBoard::isFoodEaten() const
{
    for(int i=0; i<snake_pos.size();++i)
    {
        if(board.at(snake_pos[0].x).at(snake_pos[0].y).hasFood == true)
        {
            board.at(snake_pos[0].x).at(snake_pos[0].y).hasFood == false;
            return  true;
        }
    }
    return  false;
}
Direction SnakeBoard::changeDirection(Direction dir)
{
    if(dir == RIGHT && direction != LEFT)
    {
        direction == RIGHT;
    }
    if(dir == LEFT && direction != RIGHT)
    {
        direction == LEFT;
    }
    if(dir == UP && direction != DOWN)
    {
        direction == LEFT;
    }
    if(dir == DOWN && direction !=UP)
    {
        direction ==DOWN;
    }
}
void SnakeBoard::move()
{
    SnakePos new_pos;
    if(direction == RIGHT)
    {
        new_pos.x = snake_pos[0].x+1;
        new_pos.y = snake_pos[0].y;

    }
    if(direction == LEFT)
    {
        new_pos.x = snake_pos[0].x-1;
        new_pos.y = snake_pos[0].y;


    }
    if(direction == UP)
    {
        new_pos.x = snake_pos[0].x;
        new_pos.y = snake_pos[0].y-1;

    }
    if( direction == DOWN) // troche wzorowane na https://forum.pasja-informatyki.pl/250831/skrecanie-weza-w-grze-snake
    {
        new_pos.x == snake_pos[0].x;
        new_pos.y = snake_pos[0].y+1;

    }
    if(isCollision(new_pos.x,new_pos.y) == false)
    {
        if(isFoodEaten())
        {
            board.at(new_pos.y).at(new_pos.x).hasSnake == true;
            snake_pos.insert(snake_pos.begin(),new_pos);
            setFood();

        }
        else
            {
                board.at(new_pos.y).at(new_pos.x).hasSnake == true;
                snake_pos.insert(snake_pos.begin(),new_pos);
                board.at(snake_pos.at(snake_pos.size()-1).y).at(snake_pos.at(snake_pos.size()-1).x).hasSnake == false;
                snake_pos.pop_back();

            }

    }
    else
         state == FINISHED_LOSS;
}


