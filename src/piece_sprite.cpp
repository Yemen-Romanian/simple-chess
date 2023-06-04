#include "piece_sprite.h"


PieceSprite::PieceSprite(Piece piece, PieceColor color)
{

    std::string texture_file_name;

    switch (piece)
    {
        case Piece::PAWN:
            texture_file_name = color == PieceColor::WHITE ? "white_pawn.png" : "black_pawn.png";
            break;
        case Piece::KNIGHT:
            texture_file_name = color == PieceColor::WHITE ? "white_knight.png" : "black_knight.png";
            break;
        case Piece::BISHOP:
            texture_file_name = color == PieceColor::WHITE ? "white_bishop.png" : "black_bishop.png";
            break;
        case Piece::ROOK:
            texture_file_name = color == PieceColor::WHITE ? "white_rook.png" : "black_rook.png";
            break;
        case Piece::QUEEN:
            texture_file_name = color == PieceColor::WHITE ? "white_queen.png" : "black_queen.png";
            break;
        case Piece::KING:
            texture_file_name = color == PieceColor::WHITE ? "white_king.png" : "black_king.png";
    }

    auto full_string_path = (texture_root / std::filesystem::path(texture_file_name)).string();
    texture.loadFromFile(full_string_path);
    texture.setSmooth(true);
    sprite.setTexture(texture);
}

PieceSprite::PieceSprite(const PieceSprite& piece)
{
    texture = piece.texture;
    sprite = piece.sprite;
    sprite.setTexture(texture);
}

void PieceSprite::setPosition(const sf::Vector2f& position) { sprite.setPosition(position); }
void PieceSprite::setScale(const sf::Vector2f& scale) { sprite.setScale(scale); }

sf::Vector2f PieceSprite::getPosition() const { return sprite.getPosition(); }
sf::Vector2f PieceSprite::getScale() const { return sprite.getScale(); }
sf::FloatRect PieceSprite::getGlobalBounds() const {return sprite.getGlobalBounds(); }

void PieceSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}