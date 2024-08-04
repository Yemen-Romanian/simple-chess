#pragma once
#include <memory>

class PieceSprite;
enum class Piece;
enum class PieceColor;
std::shared_ptr<PieceSprite> getPieceSprite(Piece, PieceColor);