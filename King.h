#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>
//#include "Board.cpp"

class King : public Piece {
public:
    King(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    //void move(std::shared_ptr<Piece>& destination_square, bool& Turn) override;
    virtual std::vector<std::pair<int, int>> legal_movesWhite();
    virtual std::vector<std::pair<int, int>> legal_movesBlack();
    virtual std::vector<std::shared_ptr<Piece>> dangerous_movesWhite();
    virtual std::vector<std::shared_ptr<Piece>> dangerous_movesBlack();
//private:
    //std::vector<std::shared_ptr<Piece>>legal_moves;
};

#endif // PAWN_H

