#include "King.h"
#include "Constants.h"
#include <iostream>
//#include "Board.cpp"
#include <memory>
#include "Empty_Square.h"
#include "Piece_Textures.h"


King::King(int x, int y, bool isWhite, bool isEmpty,  std::shared_ptr<sf::Texture> texture)
    : Piece(x, y, isWhite, isEmpty, texture ){ // Constructor
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}

std::vector<std::pair<int, int>>  King::legal_movesWhite() {
    std::vector<std::pair<int, int>> legalMoves;
    //legalMoves.push_back(board.square[0][0]);

    if (x > 0 && x < 7 && y > 0 && y < 7)
    {
        legalMoves.push_back(std::make_pair(x + 1, y + 1));
        legalMoves.push_back(std::make_pair(x + 1, y + 0));
        legalMoves.push_back(std::make_pair(x + 1, y - 1));
        legalMoves.push_back(std::make_pair(x + 0, y + 1));
        legalMoves.push_back(std::make_pair(x - 1, y + 0));
        legalMoves.push_back(std::make_pair(x - 1, y - 1));
        legalMoves.push_back(std::make_pair(x - 1, y + 1));
        legalMoves.push_back(std::make_pair(x + 0, y - 1));
        //BUG:
        // Nejuda karalius, nes negauna legal moves
        // TODO:
        // padaryti, kad visos legal_moves fnc returnina structa arba kazkoki containeri
        // kuris turi x ir y, visu legal moves
        // board.cpp pakeist funkcija, kad is gautu x ir y, appendintu legal moves;
    }
    if (y == 7)
    {
        if (x == 0)
        {
            legalMoves.push_back(std::make_pair(x + 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y - 1));
            legalMoves.push_back(std::make_pair(x + 0, y - 1));
            
        }
        else if (x == 7)
        {
            legalMoves.push_back(std::make_pair(x - 1, y - 1));
            legalMoves.push_back(std::make_pair(x - 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 0, y - 1));
        }
        else
        {
            legalMoves.push_back(std::make_pair(x + 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y - 1));
            legalMoves.push_back(std::make_pair(x + 0, y - 1));
            legalMoves.push_back(std::make_pair(x - 1, y - 1));
            legalMoves.push_back(std::make_pair(x - 1, y + 0));
        }
            
    }
    if (y == 7)
    {
        if (x == 0)
        {
            legalMoves.push_back(std::make_pair(x + 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y - 1));
            legalMoves.push_back(std::make_pair(x + 0, y - 1));
            
        }
        else if (x == 7)
        {
            legalMoves.push_back(std::make_pair(x - 1, y - 1));
            legalMoves.push_back(std::make_pair(x - 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 0, y - 1));
        }
        else
        {
            legalMoves.push_back(std::make_pair(x + 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y - 1));
            legalMoves.push_back(std::make_pair(x + 0, y - 1));
            legalMoves.push_back(std::make_pair(x - 1, y - 1));
            legalMoves.push_back(std::make_pair(x - 1, y + 0));
        }
            
    }
    if (y == 0)
    {
        if (x == 0)
        {
            legalMoves.push_back(std::make_pair(x + 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y + 1));
            legalMoves.push_back(std::make_pair(x + 0, y + 1));
        }
        if (x == 7)
        {
            legalMoves.push_back(std::make_pair(x  - 1, y + 0));
            legalMoves.push_back(std::make_pair(x - 1, y + 1));
            legalMoves.push_back(std::make_pair(x + 0, y + 1));
        }
        else
        {
            legalMoves.push_back(std::make_pair(x - 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 0, y + 1));
            legalMoves.push_back(std::make_pair(x - 1, y + 0));
            legalMoves.push_back(std::make_pair(x + 1, y + 1));
        }
    }
    printf("legal_movesWhite KING fnc called\n");
    

    return legalMoves;
}
std::vector<std::pair<int, int>> King::legal_movesBlack() {
    std::vector<std::pair<int, int>> pieces;

    return pieces;
}
std::vector<std::shared_ptr<Piece>> King::dangerous_movesWhite()
{
    return std::vector<std::shared_ptr<Piece>>();
}
std::vector<std::shared_ptr<Piece>> King::dangerous_movesBlack()
{
    return std::vector<std::shared_ptr<Piece>>();
}