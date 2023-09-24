#ifndef PAWN_H
#define PAWN_H

#include "Piece.h" // Base Class Header
#include <SFML/Graphics.hpp>
#include <memory>

class Pawn : public Piece {
public:
    Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture);

    
    void move(int row, int col, bool isWhite, bool first_move);
    bool legal_move(/*int row, int col, bool isWHite, bool first_move*/);
private:
    bool first_Move;
};

#endif // PAWN_H

