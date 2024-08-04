#include <filesystem>
#include "knight_sprite.h"

KnightSprite::KnightSprite(PieceColor color): PieceSprite(Piece::PAWN, color)
{
    std::string texture_file_name = color == PieceColor::WHITE ? "white_knight.png" : "black_knight.png";
    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    loadTexture(full_string_path);
}

std::string KnightSprite::toString() const
{
    std::string result = "";
    if (mPieceColor == PieceColor::BLACK) result += "Black";
    else result += "White";
    result += " Knight";
    return result;
}

std::vector<sf::Vector2i> KnightSprite::getPossibleMoves() const
{
    return std::vector<sf::Vector2i>();
}