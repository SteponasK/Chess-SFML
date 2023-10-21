#include "Constants.h"
#include <iostream>
#include <memory>
#include "Empty_Square.h"
#include "Piece_Textures.h"
#include "Bishop.h"
#include "Board.cpp"


Bishop::Bishop(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture) { // Constructor
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::pair<int, int>>  Bishop::legal_movesWhite() {
    std::vector<std::pair<int, int>> legalMoves;
    std::cout << "white version called\n";
    // Moves to the right down
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
    //for (int i = y + 1; i < 8; ++i)
    //{
    //    for (int j = y + 1; j < 8; ++j)
    //    {
    //        // if(square[x][i]->isEmpty)
    //        legalMoves.push_back(std::make_pair(j, i));

    //        if (!board.square[j][i]->isEmpty)
    //        {
    //            if (board.square[j][i]->isWhite)
    //                legalMoves.pop_back();
    //            break;
    //        }
    //        

    //    }
    //}


    //// Moves to the left down
    //for (int i = y + 1; i > 8; ++i)
    //{
    //    for (int j = x - 1; j > 0; --j)
    //    {
    //        // if(square[x][i]->isEmpty)
    //        legalMoves.push_back(std::make_pair(j, i));

    //        if (!board.square[j][i]->isEmpty)
    //        {
    //            if (board.square[j][i]->isWhite)
    //                legalMoves.pop_back();
    //            break;
    //        }
    //        break;
    //    }
    //}
    //// Moves to up left
    //for (int i = y + 1; i < 8; ++i)
    //{
    //    for (int j = x - 1; j > 0; --j)
    //    {
    //        // if(square[x][i]->isEmpty)
    //        legalMoves.push_back(std::make_pair(j, i));

    //        if (!board.square[j][i]->isEmpty)
    //        {
    //            if (board.square[j][i]->isWhite)
    //                legalMoves.pop_back();
    //            break;
    //        }
    //        break;
    //    }
    //}
    //// Moves up right
    //for (int i = y - 1; i > 0; --i)
    //{
    //    for (int j = x + 1; j < 8; ++j)
    //    {
    //        // if(square[x][i]->isEmpty)
    //        legalMoves.push_back(std::make_pair(j, i));


    //        if (!board.square[j][i]->isEmpty)
    //        {
    //            if (board.square[j][i]->isWhite)
    //                legalMoves.pop_back();
    //            break;
    //        }
    //        break;
    //    }
    //}

    // Moves up
    //for (int i = y - 1; i >= 0; --i)
    //{
    //    legalMoves.push_back(std::make_pair(x, i));
    //    if (!board.square[x][i]->isEmpty)
    //    {
    //        if (!board.square[x][i]->isWhite)
    //            legalMoves.pop_back();
    //        break;
    //    }
    //}


}
std::vector<std::pair<int, int>> Bishop::legal_movesBlack() {
    std::vector<std::pair<int, int>> legalMoves;

    // Moves to the right down
    for (int i = y + 1; i < 8; ++i)
    {
        for (int j = x + 1; j < 8; ++j)
        {
            // if(square[x][i]->isEmpty)
            legalMoves.push_back(std::make_pair(j, i));

            if (!board.square[j][i]->isEmpty)
            {
                if (!board.square[j][i]->isWhite)
                    legalMoves.pop_back();
                break;
            }

        }
    }
    

    // Moves to the left down
    for (int i = y + 1; i < 8; ++i)
    {
        for (int j = x - 1; j < 8; --j)
        {
            // if(square[x][i]->isEmpty)
            legalMoves.push_back(std::make_pair(j, i));

            if (!board.square[j][i]->isEmpty)
            {
                if (!board.square[j][i]->isWhite)
                    legalMoves.pop_back();
                break;
            }

        }
    }
    // Moves to up left
    for (int i = y + 1; i < 8; ++i)
    {
        for (int j = x - 1; j < 8; --j)
        {
            // if(square[x][i]->isEmpty)
            legalMoves.push_back(std::make_pair(j, i));

            if (!board.square[j][i]->isEmpty)
            {
                if (!board.square[j][i]->isWhite)
                    legalMoves.pop_back();
                break;
            }

        }
    }
    // Moves up right
    for (int i = y - 1; i < 8; --i)
    {
        for (int j = x + 1; j < 8; ++j)
        {
            // if(square[x][i]->isEmpty)
            legalMoves.push_back(std::make_pair(j, i));
           

            if (!board.square[j][i]->isEmpty)
            {
                if (!board.square[j][i]->isWhite)
                    legalMoves.pop_back();
                break;
            }

        }
    }

    // Moves up
    //for (int i = y - 1; i >= 0; --i)
    //{
    //    legalMoves.push_back(std::make_pair(x, i));
    //    if (!board.square[x][i]->isEmpty)
    //    {
    //        if (!board.square[x][i]->isWhite)
    //            legalMoves.pop_back();
    //        break;
    //    }
    //}

    return legalMoves;
}