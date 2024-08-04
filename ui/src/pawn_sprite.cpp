#include <filesystem>
#include "pawn_sprite.h"

PawnSprite::PawnSprite(PieceColor color): PieceSprite(Piece::PAWN, color)
{
    std::string texture_file_name = color == PieceColor::WHITE ? "white_pawn.png" : "black_pawn.png";
    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    loadTexture(full_string_path);
}

std::string PawnSprite::toString() const
{
    std::string result = "";
    if (mPieceColor == PieceColor::BLACK) result += "Black";
    else result += "White";
    result += " Pawn";
    return result;
}

std::vector<sf::Vector2i> PawnSprite::getPossibleMoves() const
{
    return std::vector<sf::Vector2i>();
}