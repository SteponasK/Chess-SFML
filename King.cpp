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

    if (x > 0 && x < 7 && y > 0 && y < 7)
    {
        legalMoves.push_back(board.square[x][y]);
        //legalMoves.push_back(square);
    }
    printf("QEIFWIUOFNWIOUGNWERIOGNWEIUORGNWEIOURGNWIOUERGNWEIOURGNWUIEORNGIWOERIGNWERGUWEORUGNW");
    legalMoves.push_back(board.square[x+1][y-1]);
    return legalMoves;
}
std::vector<std::shared_ptr<Piece>> King::legal_movesBlack(std::shared_ptr<Piece>& destination) {
    std::vector<std::shared_ptr<Piece>> pieces;

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