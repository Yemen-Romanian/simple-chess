#include <filesystem>
#include "rook_sprite.h"

RookSprite::RookSprite(PieceColor color): PieceSprite(Piece::PAWN, color)
{
    std::string texture_file_name = color == PieceColor::WHITE ? "white_rook.png" : "black_rook.png";
    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    loadTexture(full_string_path);
}

std::string RookSprite::toString() const
{
    std::string result = "";
    if (mPieceColor == PieceColor::BLACK) result += "Black";
    else result += "White";
    result += " Rook";
    return result;
}

std::vector<sf::Vector2i> RookSprite::getPossibleMoves() const
{
    return std::vector<sf::Vector2i>();
}