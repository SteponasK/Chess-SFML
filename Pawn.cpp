#include "Pawn.h"
#include "Constants.h"
#include <memory>
#include "Board.cpp"

Pawn::Pawn(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture) {
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::pair<int, int>>  Pawn::legal_movesWhite(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;

    std::vector<std::pair<int, int>> captureDirection = {
        {-1, -1},   {1, -1}
    };
    for (const auto& direction : captureDirection) {
        int newX = x + direction.first;
        int newY = y + direction.second;
        if (newX >= 0 && newY >= 0 && newX < 8 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));
            if (tempBoard.square[newX][newY]->isEmpty || tempBoard.square[newX][newY]->isWhite){
                legalMoves.pop_back();
            }
        }
    }
    if (y - 1 >= 0 && y < 8  && tempBoard.square[x][y-1]->isEmpty) {
        legalMoves.push_back(std::make_pair(x, y - 1));
        if (y == 6 && tempBoard.square[x][y-2]->isEmpty) {
            legalMoves.push_back(std::make_pair(x, y - 2));
        }
    }
    std::pair<Piece, Piece> previousMove = tempBoard.getPreviousMove();
    if (previousMove.first.isPawn && previousMove.first.y == 1
        && previousMove.second.y == 3) {
        if (y == 3) {
            if ((x - 1 < 8 && x - 1 >= 0 && x - 1 == previousMove.second.x) ||
                (x + 1 < 8 && x + 1 >= 0 && x + 1 == previousMove.second.x)) {
                legalMoves.push_back(std::make_pair(previousMove.second.x, previousMove.second.y-1));
            }
        }  
    }

    return legalMoves;
}
std::vector<std::pair<int, int>>  Pawn::legal_movesBlack(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;


    std::vector<std::pair<int, int>> captureDirection = {
        {-1, 1},   {1, 1}
    };
    for (const auto& direction : captureDirection) {
        int newX = x + direction.first;
        int newY = y + direction.second;
        if (newX >= 0 && newY >= 0 && newX < 8 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));
            if (tempBoard.square[newX][newY]->isEmpty || (!tempBoard.square[newX][newY]->isWhite
                && !board.square[newX][newY]->isEmpty)) {
                legalMoves.pop_back();
            }
        }
    }
    if (y - 1 >= 0 && y < 8 && tempBoard.square[x][y + 1]->isEmpty) {
        legalMoves.push_back(std::make_pair(x, y + 1));
        if (y == 1 && tempBoard.square[x][y + 2]->isEmpty) {
            legalMoves.push_back(std::make_pair(x, y + 2));
        }
    }
    std::pair<Piece, Piece> previousMove = tempBoard.getPreviousMove();
    if (previousMove.first.isPawn && previousMove.first.y == 6
        && previousMove.second.y == 4) {
        if (y == 4) {
            if ((x - 1 < 8 && x - 1 >= 0 && x - 1 == previousMove.second.x) ||
                (x + 1 < 8 && x + 1 >= 0 && x + 1 == previousMove.second.x)) {
                legalMoves.push_back(std::make_pair(previousMove.second.x, previousMove.second.y+1));
            }
        }
    }
    return legalMoves;
}