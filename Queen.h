#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Queen : public Piece {
public:
    Queen(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    virtual std::vector<std::pair<int, int>> legal_movesWhite();
    virtual std::vector<std::pair<int, int>> legal_movesBlack();
};

#endif