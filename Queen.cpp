#include "Constants.h"
#include <memory>
#include "Queen.h"
#include "Board.cpp"

Queen::Queen(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture) {
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::pair<int, int>>  Queen::legal_movesWhite(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;

    std::vector<std::pair<int, int>> moveDirections = {
    {-1, -1}, {0, -1}, {1, -1},
    {-1, 0},           {1, 0},
    {-1, 1}, {0, 1}, {1, 1}
    };
    for (const auto& direction : moveDirections) {
        int newX = x + direction.first;
        int newY = y + direction.second;

        while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));

            if (!tempBoard.square[newX][newY]->isEmpty) {
                if (tempBoard.square[newX][newY]->isWhite)
                    legalMoves.pop_back();
                break;
            }
            newX += direction.first;
            newY += direction.second;
        }
    }
    return legalMoves;
}
std::vector<std::pair<int, int>>  Queen::legal_movesBlack(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;
    std::vector<std::pair<int, int>> moveDirections = {
    {-1, -1}, {0, -1}, {1, -1},
    {-1, 0},           {1, 0},
    {-1, 1}, {0, 1}, {1, 1}
    };
    for (const auto& direction : moveDirections) {
        int newX = x + direction.first;
        int newY = y + direction.second;

        while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));

            if (!tempBoard.square[newX][newY]->isEmpty) {
                if (!tempBoard.square[newX][newY]->isWhite)
                    legalMoves.pop_back();
                break;
            }
            newX += direction.first;
            newY += direction.second;
        }
    }
    return legalMoves;
}