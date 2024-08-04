#include "piece_sprite.h"


PieceSprite::PieceSprite(Piece piece, PieceColor color): mPieceType(piece), mPieceColor(color)
{

}

PieceSprite::PieceSprite(const PieceSprite& piece)
{
    texture = piece.texture;
    sprite = piece.sprite;
    sprite.setTexture(texture);
}

void PieceSprite::loadTexture(const std::string& texturePath)
{
    texture.loadFromFile(texturePath);
    texture.setSmooth(true);
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