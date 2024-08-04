#include <filesystem>
#include "queen_sprite.h"

QueenSprite::QueenSprite(PieceColor color): PieceSprite(Piece::PAWN, color)
{
    std::string texture_file_name = color == PieceColor::WHITE ? "white_queen.png" : "black_queen.png";
    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    loadTexture(full_string_path);
}

std::string QueenSprite::toString() const
{
    std::string result = "";
    if (mPieceColor == PieceColor::BLACK) result += "Black";
    else result += "White";
    result += " Queen";
    return result;
}

std::vector<sf::Vector2i> QueenSprite::getPossibleMoves() const
{
    return std::vector<sf::Vector2i>();
}