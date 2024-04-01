#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>
class Board; // Forward declaration (circular dependancy workaround)
class Empty_Square : public Piece {
public:
    Empty_Square(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    void move(std::shared_ptr<Piece>& destination_square, bool Capture, bool& Turn) override;
    std::shared_ptr<Piece> clone() const override {
        return  std::make_shared<Empty_Square>(*this);
    }
    virtual std::vector<std::pair<int, int>> legal_movesWhite(const Board& tempBoard);
    virtual std::vector<std::pair<int, int>> legal_movesBlack(const Board& tempBoard);
};

