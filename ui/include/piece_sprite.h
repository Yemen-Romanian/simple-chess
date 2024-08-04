#pragma once

#include <filesystem>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


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
        virtual ~PieceSprite() = default;
        void setScale(const sf::Vector2f&);
        sf::Vector2f getScale() const;
        void setPosition(const sf::Vector2f&);
        sf::Vector2f getPosition() const;
        sf::FloatRect getGlobalBounds() const;
        virtual std::string toString() const = 0;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const = 0;

    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f mCurrentPosition;
        Piece mPieceType;
        PieceColor mPieceColor;
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        void loadTexture(const std::string&);
        const std::filesystem::path texture_root = std::filesystem::path("textures");
};