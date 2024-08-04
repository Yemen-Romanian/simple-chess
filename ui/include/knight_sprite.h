#pragma once
#include "piece_sprite.h"

class KnightSprite: public PieceSprite
{
    public:
        KnightSprite(PieceColor);
        KnightSprite(const KnightSprite& pawn);
        virtual std::string toString() const;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const;
};