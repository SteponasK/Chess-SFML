#include "Constants.h"
#include <iostream>
#include <memory>
#include "Empty_Square.h"
#include "Piece_Textures.h"
#include "Queen.h"
#include "Board.cpp"


Queen::Queen(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture) { // Constructor
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::pair<int, int>>  Queen::legal_movesWhite() {
    std::vector<std::pair<int, int>> legalMoves;

    // Moves to the right
    for (int i = x + 1; i < 8; ++i)
    {
        // if(square[x][i]->isEmpty)
        legalMoves.push_back(std::make_pair(i, y));

        if (!board.square[i][y]->isEmpty)
        {
            if (board.square[i][y]->isWhite)
                legalMoves.pop_back();
            break;
        }

    }

    // Moves to the left
    for (int i = x - 1; i >= 0; --i)
    {
        legalMoves.push_back(std::make_pair(i, y));
        if (!board.square[i][y]->isEmpty)
        {
            if (board.square[i][y]->isWhite)
                legalMoves.pop_back();
            break;
        }
    }

    //  Moves down
    for (int i = y + 1; i < 8; ++i)
    {
        legalMoves.push_back(std::make_pair(x, i));
        if (!board.square[x][i]->isEmpty)
        {
            if (board.square[x][i]->isWhite)
                legalMoves.pop_back();
            break;
        }
    }

    // Moves up
    for (int i = y - 1; i >= 0; --i)
    {
        legalMoves.push_back(std::make_pair(x, i));
        if (!board.square[x][i]->isEmpty)
        {
            if (board.square[x][i]->isWhite)
                legalMoves.pop_back();
            break;
        }
    }
    for (int i = 1; x + i < 8 && y + i < 8; ++i)
    {

        legalMoves.push_back(std::make_pair(x + i, y + i));
        if (!board.square[x + i][y + i]->isEmpty)
        {
            if (board.square[x + i][y + i]->isWhite)
            {
                legalMoves.pop_back();
            }
            break;
        }
    }
    // Moves to the left down
    for (int i = 1; x - i >= 0 && y + i < 8; ++i)
    {
        legalMoves.push_back(std::make_pair(x - i, y + i));
        if (!board.square[x - i][y + i]->isEmpty)
        {
            std::cout << "\n\nnot empty\n\n\n\n";
            if (board.square[x - i][y + i]->isWhite)
            {
                legalMoves.pop_back();
                std::cout << "\n\nPOPPED\n\n\n\n";
            }
            break;
        }
    }
    // Moves to the left up
    for (int i = 1; x - i >= 0 && y - i >= 0; ++i)
    {
        legalMoves.push_back(std::make_pair(x - i, y - i));
        if (!board.square[x - i][y - i]->isEmpty)
        {
            if (board.square[x - i][y - i]->isWhite)
                legalMoves.pop_back();

            break;
        }
    }
    // Moves to the right up
    for (int i = 1; x + i < 8 && y - i >= 0; ++i)
    {
        legalMoves.push_back(std::make_pair(x + i, y - i));
        if (!board.square[x + i][y - i]->isEmpty)
        {
            if (board.square[x + i][y - i]->isWhite)
            {
                legalMoves.pop_back();
            }
            break;
        }
    }


    return legalMoves;
}
std::vector<std::pair<int, int>> Queen::legal_movesBlack() {
    std::vector<std::pair<int, int>> legalMoves;

    // Moves to the right
    for (int i = x + 1; i < 8; ++i)
    {
        // if(square[x][i]->isEmpty)
        legalMoves.push_back(std::make_pair(i, y));

        if (!board.square[i][y]->isEmpty)
        {
            if (!board.square[i][y]->isWhite)
                legalMoves.pop_back();
            break;
        }

    }

    // Moves to the left
    for (int i = x - 1; i >= 0; --i)
    {
        legalMoves.push_back(std::make_pair(i, y));
        if (!board.square[i][y]->isEmpty)
        {
            if (!board.square[i][y]->isWhite)
                legalMoves.pop_back();
            break;
        }
    }

    // Moves down
    for (int i = y + 1; i < 8; ++i)
    {
        legalMoves.push_back(std::make_pair(x, i));
        if (!board.square[x][i]->isEmpty)
        {
            if (!board.square[x][i]->isWhite)
                legalMoves.pop_back();
            break;
        }
    }

    // Moves up
    for (int i = y - 1; i >= 0; --i)
    {
        legalMoves.push_back(std::make_pair(x, i));
        if (!board.square[x][i]->isEmpty)
        {
            if (!board.square[x][i]->isWhite)
                legalMoves.pop_back();
            break;
        }
    }

    return legalMoves;
}