#include "King.h"
#include "Constants.h"
#include <iostream>
#include "Board.cpp"
#include <memory>
#include "Empty_Square.h"
#include "Piece_Textures.h"

King::King(int x, int y, bool isWhite, bool isEmpty,  std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty ){ // Constructor
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::shared_ptr<Piece>> King::legal_movesWhite(std::shared_ptr<Piece>& destination) {
    std::vector<std::shared_ptr<Piece>> legalMoves;
    std::vector<std::shared_ptr<Piece>> dangerousMoves;
    
    //if(x > 0 && y < 7 && x < 7 && y > 0)


    // legalMoves = legalMoves - dangerous_movesWhite_VECTOR;
    // return legalMoves, tada substractinam dangerous moves.
    return legalMoves;
}
std::vector<std::shared_ptr<Piece>> King::legal_movesBlack(std::shared_ptr<Piece>& destination) {
    return std::vector<std::shared_ptr<Piece>>();
}
std::vector<std::shared_ptr<Piece>> King::dangerous_movesWhite()
{
    return std::vector<std::shared_ptr<Piece>>();
}
std::vector<std::shared_ptr<Piece>> King::dangerous_movesBlack()
{
    return std::vector<std::shared_ptr<Piece>>();
}