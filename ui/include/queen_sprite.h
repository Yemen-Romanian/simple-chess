#pragma once
#include "piece_sprite.h"

class QueenSprite: public PieceSprite
{
    public:
        QueenSprite(PieceColor);
        QueenSprite(const QueenSprite& pawn);
        virtual std::string toString() const;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const;
};