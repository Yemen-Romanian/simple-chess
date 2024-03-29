#include <SFML/Window.hpp>
#include "chess_board.h"
#include "piece_sprite.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main chess window", sf::Style::Default);
    ChessBoard board;
    sf::Color white(239, 238, 211);
    sf::Color black(118, 151, 84);
    ChessPalette palette(white, black);
    // ChessPalette palette;
    sf::Vector2u cellSize {100, 100};
    sf::Vector2f offset {300, 100};
    board.load(cellSize, offset, palette, PieceColor::BLACK);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(board);


        // end the current frame
        window.display();
    }

    return 0;
}