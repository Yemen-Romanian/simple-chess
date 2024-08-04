#include <filesystem>
#include "king_sprite.h"

KingSprite::KingSprite(PieceColor color): PieceSprite(Piece::PAWN, color)
{
    std::string texture_file_name = color == PieceColor::WHITE ? "white_king.png" : "black_king.png";
    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    loadTexture(full_string_path);
}

std::string KingSprite::toString() const
{
    std::string result = "";
    if (mPieceColor == PieceColor::BLACK) result += "Black";
    else result += "White";
    result += " King";
    return result;
}

std::vector<sf::Vector2i> KingSprite::getPossibleMoves() const
{
    return std::vector<sf::Vector2i>();
}