#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>
class Empty_Square : public Piece {
public:
    Empty_Square(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    void move(std::shared_ptr<Piece>& destination_square, bool Capture, bool& Turn) override;
    virtual std::vector<std::pair<int, int>> legal_movesWhite();
    virtual std::vector<std::pair<int, int>> legal_movesBlack();
};

