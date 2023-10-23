#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>
class Board; // Forward declaration (circular dependancy workaround)
class Knight : public Piece {
public:
    Knight(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    std::shared_ptr<Piece> clone() const override {
        return  std::make_shared<Knight>(*this);
    }
    virtual std::vector<std::pair<int, int>> legal_movesWhite(const Board& tempBoard);
    virtual std::vector<std::pair<int, int>> legal_movesBlack(const Board& tempBoard);
};
#endif