#include "King.h"
#include "Constants.h"
#include <iostream>
#include "Board.cpp"
#include <memory>
#include "Square.h"
#include "Piece_Textures.h"

King::King(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture)
    : Piece(isWhite, row, col, figure){ // Constructor
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(row * scale, col * scale));
}

void King::move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn) {
    if (isWhite) legal_movesW();
    else legal_movesB();

}
void King::legal_movesW(/*int row, int col, bool isWhite, bool first_move*/) {
    int delta_x 
}
void King::legal_movesB(/*int row, int col, bool isWhite, bool first_move*/) {

}