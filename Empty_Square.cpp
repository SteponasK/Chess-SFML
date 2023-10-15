#include "Empty_Square.h"
#include "Constants.h"
#include <iostream>


Empty_Square::Empty_Square(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
        : Piece( x, y, isWhite, isEmpty) {
        sprite.setTexture(*texture);
        sprite.setPosition(sf::Vector2f(x * scale, y * scale));
    }
    //We just do nothing
    void Empty_Square::move(std::shared_ptr<Piece>& destination_square, bool Capture, bool& Turn) {}
    bool Empty_Square::legal_movesWhite(std::shared_ptr<Piece>& destination_square) { return 0; }
    bool Empty_Square::legal_movesBlack(std::shared_ptr<Piece>& destination_square) { return 0; }
    bool isEmpty;
    int x;
    int y;
    bool selected = false;
    std::shared_ptr<sf::Texture> texture;
    //Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture);