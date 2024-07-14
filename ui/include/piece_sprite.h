#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

const auto texture_root = std::filesystem::path("textures");

enum class Piece
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum class PieceColor
{
    WHITE,
    BLACK
};

class PieceSprite: public sf::Drawable
{
    public:
        PieceSprite(Piece, PieceColor);
        PieceSprite(const PieceSprite& piece);
        void setScale(const sf::Vector2f&);
        sf::Vector2f getScale() const;
        void setPosition(const sf::Vector2f&);
        sf::Vector2f getPosition() const;
        sf::FloatRect getGlobalBounds() const;

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};