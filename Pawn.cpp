#include "Pawn.h"
#include "Constants.h"

Pawn::Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture)
    : Piece(isWhite, row, col), first_Move(false) { // Constructor
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(row * scale, col * scale));
}

void Pawn::move(int row, int col, bool isWhite, bool first_move) {
    if (isWhite) {
        col--;
      //  sprite.move(sf::Vector2f(0, -1 * scale));
    }
    else {
        col++;
       // sprite.move(sf::Vector2f(0, 1 * scale));
    }
}
bool Pawn::legal_move(/*int row, int col, bool isWhite, bool first_move*/) {
    if (isWhite)
    {
        if (first_Move)
        {

        }
    }
    return true;
}