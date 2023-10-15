#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>

class King : public Piece {
public:
    King(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    //void move(std::shared_ptr<Piece>& destination_square, bool& Turn) override;
    virtual std::vector<std::shared_ptr<Piece>> legal_movesWhite(std::shared_ptr<Piece>& destination_square);
    virtual std::vector<std::shared_ptr<Piece>> legal_movesBlack(std::shared_ptr<Piece>& destination_square);
private:
    std::vector<std::shared_ptr<Piece>>legal_moves;
};

#endif // PAWN_H

