#pragma once
#include "piece_sprite.h"

class KingSprite: public PieceSprite
{
    public:
        KingSprite(PieceColor);
        KingSprite(const KingSprite& pawn);
        virtual std::string toString() const;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const;
};