#include <chess_board.h>
#include <sprite_factory.h>
#include <piece_sprite.h>
#include <fmt/core.h>

void ChessBoard::load(const sf::Vector2u& cellSize, const sf::Vector2f& offset, const ChessPalette& palette, const PieceColor& players_color)
{
    this->offset = offset;
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(board_height * board_width * 4);

    for (unsigned int i = 0; i < board_width; i++)
        for (unsigned int j = 0; j < board_height; j++)
        {
            sf::Vertex* quad = &vertices[(i*board_height + j) * 4];

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

    load_pieces(cellSize, offset, players_color);
}

void ChessBoard::load_pieces(const sf::Vector2u& cellSize, const sf::Vector2f& offset, const PieceColor& players_color)
{
    std::vector<Piece> pieces_in_order;
    PieceColor opponent_color;
    if (players_color == PieceColor::WHITE)
    {
        pieces_in_order = {Piece::ROOK, Piece::KNIGHT, Piece::BISHOP, Piece::QUEEN, Piece::KING, Piece::BISHOP, Piece::KNIGHT, Piece::ROOK};
        opponent_color = PieceColor::BLACK;
    }
    else
    {
        pieces_in_order = {Piece::ROOK, Piece::KNIGHT, Piece::BISHOP, Piece::KING, Piece::QUEEN, Piece::BISHOP, Piece::KNIGHT, Piece::ROOK};
        opponent_color = PieceColor::WHITE;
    }

    for (int i = 0; i < pieces_in_order.size(); i++)
    {
        auto players_piece_sprite = getPieceSprite(pieces_in_order[i], players_color);
        sf::FloatRect players_rect = players_piece_sprite->getGlobalBounds();
        players_piece_sprite->setScale(sf::Vector2f {cellSize.x / players_rect.width, cellSize.y / players_rect.height});
        players_piece_sprite->setPosition(sf::Vector2f {offset.x + i * cellSize.x, offset.y + (board_height - 1) * cellSize.y});
        chess_field[7][i] = players_piece_sprite;

        auto opponents_piece_sprite = getPieceSprite(pieces_in_order[i], opponent_color);
        sf::FloatRect opponents_rect = opponents_piece_sprite->getGlobalBounds();
        opponents_piece_sprite->setScale(sf::Vector2f {cellSize.x / opponents_rect.width, cellSize.y / opponents_rect.height});
        opponents_piece_sprite->setPosition(sf::Vector2f {offset.x + i * cellSize.x, offset.y});
        chess_field[0][i] = opponents_piece_sprite;

        std::shared_ptr<PieceSprite> players_pawn = getPieceSprite(Piece::PAWN, players_color);
        players_rect = players_pawn->getGlobalBounds();
        players_pawn->setScale(sf::Vector2f {cellSize.x / players_rect.width, cellSize.y / players_rect.height});
        players_pawn->setPosition(sf::Vector2f {offset.x + i * cellSize.x, offset.y + (board_height - 2) * cellSize.y});
        chess_field[6][i] = players_pawn;

        std::shared_ptr<PieceSprite> opponents_pawn = getPieceSprite(Piece::PAWN, opponent_color);
        opponents_rect = opponents_pawn->getGlobalBounds();
        opponents_pawn->setScale(sf::Vector2f {cellSize.x / opponents_rect.width, cellSize.y / opponents_rect.height});
        opponents_pawn->setPosition(sf::Vector2f {offset.x + i * cellSize.x, offset.y + cellSize.y});
        chess_field[1][i] = opponents_pawn;
    }
}

void ChessBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(vertices, states);
    for (int i = 0; i < board_height; i++)
    {
        for (int j = 0; j < board_width; j++)
        {
            if (chess_field[i][j] != nullptr)
                target.draw(*chess_field[i][j]);
        }
    }
}

void ChessBoard::processMouseButtonPressedEvent(const sf::Vector2i& aPressedCoordinates)
{
    sf::Vector2f floatCoordinates {aPressedCoordinates};
    if (!vertices.getBounds().contains(floatCoordinates))
    {
        fmt::println("Clicked outside board");
        return;
    }

    fmt::println("Clicked on board");
    auto boardPosition = screenCoordinatesToBoardPosition(aPressedCoordinates);
    auto clickedPiece = chess_field[boardPosition.x][boardPosition.y];

    if (clickedPiece == nullptr) return;
    fmt::println(clickedPiece->toString());
}

sf::Vector2i ChessBoard::screenCoordinatesToBoardPosition(const sf::Vector2i& screenCoordinates)
{
    int cellSize = vertices.getBounds().height / 8;
    int i = (screenCoordinates.y - offset.y) / cellSize;
    int j = (screenCoordinates.x - offset.x) / cellSize;
    fmt::println("Clicked in {} {} {}", i, j, cellSize);
    return {i, j};
}

ChessPalette::ChessPalette() : white_color(sf::Color::White), black_color(sf::Color::Blue) {}
ChessPalette::ChessPalette(const sf::Color& white, const sf::Color& black) : white_color(white), black_color(black) {}
sf::Color ChessPalette::getBlackFieldColor() const{ return black_color; }
sf::Color ChessPalette::getWhiteFieldColor() const{ return white_color; }