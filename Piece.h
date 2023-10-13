#ifndef PIECE_H
#define PIECE_H


#include <SFML/Graphics.hpp>
#include <memory>
class Piece {
public:
    Piece(bool isWhite, int row, int col, char figure);
    virtual void move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn); // sita padaryt kkiekvienos vaiko class .cpp faile
    //virtual void move(std::shared_ptr<Piece> destination_square);
    int row;
    int col;
    sf::Sprite sprite;
    bool isWhite;
    bool selected;
    bool empty_square = false;
    char figure; // sito nereikia, jeigu padarysime .move funkcija visur
    // N knight, Q queen, P pawn, B bishop, K king, R rook, E empty 
};

#endif // !PIECE_H

