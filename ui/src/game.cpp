#include <utility>
#include <tuple>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <fmt/core.h>

#include "chess_board.h"
#include "piece_sprite.h"
#include "game.h"

namespace
{
    constexpr std::pair<int, int> DefaultResolution {1920, 1080};
    constexpr std::tuple<int, int, int> DefaultWhiteColor {239, 238, 211};
    constexpr std::tuple<int, int, int> DefaultBlackColor {118, 151, 84};
    constexpr std::pair<int, int> DefaultCellSize {100, 100};
    constexpr std::pair<int, int> DefaultOffset {300, 100};
}

ChessGame::ChessGame()
{

}

ChessGame::~ChessGame()
{

}

int ChessGame::run()
{
    sf::RenderWindow window(sf::VideoMode(DefaultResolution.first, DefaultResolution.second), "Main chess window", sf::Style::Fullscreen);
    ChessBoard board;
    sf::Color white(std::get<0>(DefaultWhiteColor), std::get<1>(DefaultWhiteColor), std::get<2>(DefaultWhiteColor));
    sf::Color black(std::get<0>(DefaultBlackColor), std::get<1>(DefaultBlackColor), std::get<2>(DefaultBlackColor));
    ChessPalette palette(white, black);
    // ChessPalette palette;
    sf::Vector2u cellSize {DefaultCellSize.first, DefaultCellSize.second};
    sf::Vector2f offset {DefaultOffset.first, DefaultOffset.second};
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

            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                auto mousePosition = sf::Mouse::getPosition();
                fmt::println("Clicked in {} {}", mousePosition.x, mousePosition.y);
                board.processMouseButtonPressedEvent(mousePosition);
            }
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