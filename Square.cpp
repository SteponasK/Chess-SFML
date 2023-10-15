#include "Square.h"
#include "Constants.h"
#include <iostream>


    Square::Square(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture)
        : Piece(isWhite, row, col, figure) { // Constructor
        sprite.setTexture(*texture);
        sprite.setPosition(sf::Vector2f(row * scale, col * scale));
    }
    void Square::move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn)
    {
       
    }
    int row;
    int col;
    bool selected = false;
    std::shared_ptr<sf::Texture> texture;
    //Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture);
