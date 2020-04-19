//
// Created by User on 08.04.2020.
//

#include "MSSFMLView.h"
#include "MSBoardTextView.h"
#include "MinesweaperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>


MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b)
{
}

void MSSFMLView::drawOnWindow(sf::RenderWindow &win) {
    int height = board.getBoardHeight();
    int width = board.getBoardWidth();
    int x = 35;
    int y = 35;
    sf::VertexArray lines(sf::Lines); // poziome linie
    for (int i = 0; i < height; ++i) {
        lines.append(sf::Vector2f(x, y + i * y));
        lines.append(sf::Vector2f(x * width, y + i * y));
    }
    //pionowe linie
    for (int i = 0; i < width; ++i) {
        lines.append(sf::Vector2f(x + i * x, y));
        lines.append(sf::Vector2f(x + i * x, y * height));
    }

    //odkryte pola
    sf::RectangleShape field(sf::Vector2f(34, 34));

    //miny
    sf::CircleShape mines(10);
    mines.setFillColor(sf::Color::Black);
    mines.setOrigin(mines.getRadius(), mines.getRadius());

    //flagi
    sf::CircleShape flags(10, 3);
    flags.setFillColor(sf::Color::Yellow);
    int flag_x = 10;
    int flag_y = 8;
    flags.setOrigin(flag_x, flag_y);
    flags.setRotation(90);
    //deklracja fonta

    sf::Font font;
    if (!font.loadFromFile("arial-black.ttf")) {
        std::cout << "error" << std::endl;
        system("pause");
    }

    sf::Text text_1;
    text_1.setFont(font);
    text_1.setCharacterSize(30);
    text_1.setStyle(sf::Text::Regular);
    text_1.setOrigin(-6, 2);

    for (int i = 0; i < board.getBoardHeight(); ++i) {
        for (int j = 0; j < board.getBoardWidth(); ++j) {
            field.setFillColor(sf::Color(255, 51, 153));
            field.setPosition(x + j * x, y + i * y);
            win.draw(field);
            if (board.getFieldInfo(i, j) == '_') { //if the field is not revealed and does not have a flag
                field.setFillColor(sf::Color(255, 102, 178));
                field.setPosition(x + j * x, y + i * y);
                win.draw(field);
            }
            if (board.getFieldInfo(i, j) == 'x') // if the field is revealed and has mine
            {
                mines.setPosition(3 * x / 2 + j * x, 3 * y / 2 + i * y);
                win.draw(mines);
            }
            if (board.getFieldInfo(i, j) == 'F') // if the field is not revealed and has a flag
            {
                flags.setPosition(3 * x / 2 + j * x, 3 * y / 2 + i * y);
                win.draw(flags);
            }

            if (board.getFieldInfo(i, j) > '0' && board.getFieldInfo(i, j) <= '9') //mines amount around
            {
                text_1.setString(board.getFieldInfo(i, j));
                text_1.setFillColor(sf::Color::Red);
                text_1.setPosition(x + i * j, y + i * y);
                win.draw(text_1);
            }


        }
    }
    win.draw(lines);
    if (board.getGameState() != RUNNING) {
        sf::Font font3;
        if (!font3.loadFromFile("courier-new.ttf")) {
            std::cout << "error " << std::endl;
            system("pause");
        }

        sf::Text text3;
        text3.setFont(font3);
        text3.setCharacterSize(20);
        text3.setStyle(sf::Text::Regular);
        text3.setString("press space to see results");
        text3.setFillColor(sf::Color::Red);
        text3.setPosition(360, 750);

        win.draw(text3);
    }


}
