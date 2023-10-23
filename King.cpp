#include "King.h"
#include "Constants.h"
#include <memory>
#include "Board.cpp"

King::King(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture) { 
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}
//King::King(const Piece& king) {
//    // deep copy
//    this->x = king.x;
//    this->y = king.y;
//    this->isWhite = king.isWhite;
//    this->isEmpty = king.isEmpty;
//    this->isKing = true;
//    this->sprite = king.sprite;
//}
std::vector<std::pair<int, int>>  King::legal_movesWhite(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;
    std::vector<std::pair<int, int>> moveDirections = {
    {-1, -1}, {0, -1}, {1, -1},
    {-1, 0},           {1, 0},
    {-1, 1}, {0, 1}, {1, 1}
    };
    for (const auto& direction : moveDirections){
        int newX = x + direction.first;
        int newY = y + direction.second;

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));
            if (tempBoard.square[newX][newY]->isWhite && !tempBoard.square[newX][newY]->isEmpty)
                legalMoves.pop_back();
        }
    }
    if (isFirstMove) {
        if (tempBoard.square[7][7]->isRook && tempBoard.square[7][7]->isFirstMove) {
            if (tempBoard.square[5][7]->isEmpty && tempBoard.square[6][7]->isEmpty) {
                legalMoves.push_back(std::make_pair(6,7));
            }
        }
        if (tempBoard.square[0][7]->isRook && tempBoard.square[0][7]->isFirstMove) {
            if (tempBoard.square[1][7]->isEmpty && tempBoard.square[2][7]->isEmpty
                && tempBoard.square[3][7]->isEmpty) {
                legalMoves.push_back(std::make_pair(2, 7));
            }
        }
    }
    return legalMoves;
}
std::vector<std::pair<int, int>>  King::legal_movesBlack(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;
    std::vector<std::pair<int, int>> moveDirections = {
    {-1, -1}, {0, -1}, {1, -1},
    {-1, 0},           {1, 0},
    {-1, 1}, {0, 1}, {1, 1}
    };
    for (const auto& direction : moveDirections) {
        int newX = x + direction.first;
        int newY = y + direction.second;

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));
            if (!tempBoard.square[newX][newY]->isWhite && !tempBoard.square[newX][newY]->isEmpty)
                legalMoves.pop_back();
        }
    }
    if (isFirstMove) {
        if (tempBoard.square[7][0]->isRook && tempBoard.square[7][0]->isFirstMove) {
            if (tempBoard.square[5][0]->isEmpty && tempBoard.square[6][0]->isEmpty) {
                legalMoves.push_back(std::make_pair(6, 0));
            }
        }
        if (tempBoard.square[0][0]->isRook && tempBoard.square[0][0]->isFirstMove) {
            if (tempBoard.square[1][0]->isEmpty && tempBoard.square[2][0]->isEmpty
                && tempBoard.square[3][0]->isEmpty) {
                legalMoves.push_back(std::make_pair(2, 0));
            }
        }
    }
    // neturi castling logic
    return legalMoves;
}