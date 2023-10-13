#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>

class King : public Piece {
public:
    King(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture);
    void move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn) override;
    void legal_movesW();
    void legal_movesB();
private:
    std::vector<std::shared_ptr<Piece>>legal_moves;
};

#endif // PAWN_H

