#include <chess_board.h>
#include <iostream>

void ChessBoard::load(const sf::Vector2u& cellSize, const sf::Vector2f& offset, const ChessPalette& palette)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(board_height * board_width * 4);

    for (unsigned int i = 0; i < board_width; i++)
        for (unsigned int j = 0; j < board_height; j++)
        {
            sf::Vertex* quad = &m_vertices[(i*board_height + j ) * 4];

            quad[0].position = sf::Vector2f(offset.x + i * cellSize.x, offset.y + j * cellSize.y);
            quad[1].position = sf::Vector2f(offset.x + (i + 1) * cellSize.x, offset.y + j * cellSize.y);
            quad[2].position = sf::Vector2f(offset.x + (i + 1) * cellSize.x, offset.y + (j + 1) * cellSize.y);
            quad[3].position = sf::Vector2f(offset.x + i * cellSize.x, offset.y + (j + 1) * cellSize.y);

            sf::Color cell_color;
            if (j % 2 == 0)
            {
                cell_color = (i + j * board_width) % 2 == 0 ? palette.getWhiteFieldColor() : palette.getBlackFieldColor();
            }
            else
            {
                cell_color = (i + j * board_width) % 2 != 0 ? palette.getWhiteFieldColor() : palette.getBlackFieldColor();
            }

            quad[0].color = cell_color;
            quad[1].color = cell_color;
            quad[2].color = cell_color;
            quad[3].color = cell_color;
        }
}

void ChessBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_vertices, states);
}

ChessPalette::ChessPalette() : white_color(sf::Color::White), black_color(sf::Color::Blue) {}
ChessPalette::ChessPalette(const sf::Color& white, const sf::Color& black) : white_color(white), black_color(black) {}
sf::Color ChessPalette::getBlackFieldColor() const{ return black_color; }
sf::Color ChessPalette::getWhiteFieldColor() const{ return white_color; }