#include <iostream>
#include "piece.h"

namespace Engine{
    void print_cost(Piece p)
    {
        switch (p){
            case Engine::Piece::KING: 
                std::cout << "900" << std::endl;
                break;
            case Engine::Piece::QUEEN: 
                std::cout << "90" << std::endl;
                break;
            case Engine::Piece::ROOK: 
                std::cout << "50" << std::endl;
                break;
            case Engine::Piece::KNIGHT: 
                std::cout << "30" << std::endl;
                break;
            case Engine::Piece::BISHOP: 
                std::cout << "30" << std::endl;
                break;
            case Engine::Piece::PAWN: 
                std::cout << "10" << std::endl;
                break;
        }
    }
}