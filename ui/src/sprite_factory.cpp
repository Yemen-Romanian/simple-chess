#include "sprite_factory.h"
#include "piece_sprite.h"
#include "pawn_sprite.h"
#include "bishop_sprite.h"
#include "knight_sprite.h"
#include "rook_sprite.h"
#include "king_sprite.h"
#include "queen_sprite.h"


std::shared_ptr<PieceSprite> getPieceSprite(Piece piece, PieceColor color)
{
    switch (piece)
    {
        case Piece::PAWN:
            return std::make_shared<PawnSprite>(color);
        case Piece::KNIGHT:
            return std::make_shared<KnightSprite>(color);
        case Piece::ROOK:
            return std::make_shared<RookSprite>(color);
        case Piece::KING:
            return std::make_shared<KingSprite>(color);
        case Piece::QUEEN:
            return std::make_shared<QueenSprite>(color);
        case Piece::BISHOP:
            return std::make_shared<BishopSprite>(color);
        default:
            return std::make_shared<PawnSprite>(color);
    }
}