#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <memory>
class Square : public Piece {
public:
    Square(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture);
    void move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn) override;
  /*  int row;
    int col;
    bool selected = false;
    std::shared_ptr<sf::Texture> texture;*/

    //Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture);
};

