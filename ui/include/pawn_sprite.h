#pragma once
#include "piece_sprite.h"

class PawnSprite: public PieceSprite
{
    public:
        PawnSprite(PieceColor);
        PawnSprite(const PawnSprite&);
        virtual std::string toString() const;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const;
};