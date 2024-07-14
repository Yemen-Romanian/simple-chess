namespace Engine {
    enum class Piece {
        PAWN=10,
        KNIGHT=30,
        BISHOP=35,
        ROOK=50,
        QUEEN=90,
        KING=900
    };

    void print_cost(Piece p);
}