#ifndef PIECE_H
#define PIECE_H


#include <SFML/Graphics.hpp>
#include <memory>
class Piece {
public:
    Piece(bool isWhite, int row, int col);

    int row;
    int col;
    sf::Sprite sprite;
    bool isWhite;
    bool selected;
};

#endif // !PIECE_H

