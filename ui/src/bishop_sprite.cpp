#include <filesystem>
#include "bishop_sprite.h"

BishopSprite::BishopSprite(PieceColor color): PieceSprite(Piece::PAWN, color)
{
    std::string texture_file_name = color == PieceColor::WHITE ? "white_bishop.png" : "black_bishop.png";
    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    loadTexture(full_string_path);
}

std::string BishopSprite::toString() const
{
    std::string result = "";
    if (mPieceColor == PieceColor::BLACK) result += "Black";
    else result += "White";
    result += " Bishop";
    return result;
}

std::vector<sf::Vector2i> BishopSprite::getPossibleMoves() const
{
    return std::vector<sf::Vector2i>();
}