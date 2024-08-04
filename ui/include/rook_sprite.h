#pragma once
#include "piece_sprite.h"

class RookSprite: public PieceSprite
{
    public:
        RookSprite(PieceColor);
        RookSprite(const RookSprite& pawn);
        virtual std::string toString() const;
        virtual std::vector<sf::Vector2i> getPossibleMoves() const;
};