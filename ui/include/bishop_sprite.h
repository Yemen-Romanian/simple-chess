#pragma once
#include "piece_sprite.h"

class BishopSprite: public PieceSprite
{
    public:
        BishopSprite(PieceColor);
        BishopSprite(const BishopSprite& pawn);
        virtual std::string toString() const;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const;
};