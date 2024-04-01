#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>
class Board; // Forward declaration (circular dependancy workaround)
class Pawn : public Piece {
public:
    Pawn(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    std::shared_ptr<Piece> clone() const override {
        return  std::make_shared<Pawn>(*this);
    }
    virtual std::vector<std::pair<int, int>> legal_movesWhite(const Board& tempBoard);
    virtual std::vector<std::pair<int, int>> legal_movesBlack(const Board& tempBoard);
};
#endif