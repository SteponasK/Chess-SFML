#include "Knight.h"
#include "Constants.h"
#include <memory>
#include "Board.cpp"
#include <iostream>

Knight::Knight(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture) {
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::pair<int, int>>  Knight::legal_movesWhite(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;
    std::vector<std::pair<int, int>> moveDirections = {
        {-1, -2},   {1, -2},
    {-2, -1},           {2, -1},

    {-2, 1},            {2, 1},
        {-1, 2},    {1, 2}
    };
    for (const auto& direction : moveDirections) {
        int newX = x + direction.first;
        int newY = y + direction.second;

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            legalMoves.push_back(std::make_pair(newX, newY));
            if (tempBoard.square[newX][newY]->isWhite && !tempBoard.square[newX][newY]->isEmpty)
                legalMoves.pop_back();
        }
    }
    return legalMoves;
}
std::vector<std::pair<int, int>>  Knight::legal_movesBlack(const Board& tempBoard) {
    std::vector<std::pair<int, int>> legalMoves;
    std::vector<std::pair<int, int>> moveDirections = {
        {-1, -2},   {1, -2},
    {-2, -1},           {2, -1},

    {-2, 1},            {2, 1},
        {-1, 2},    {1, 2}
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
    //std::cout << "knight move fnc called black\n";
    return legalMoves;
}