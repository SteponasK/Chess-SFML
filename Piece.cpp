#include "Piece.h"
#include "Constants.h"
#include <iostream>
#include "Board.cpp"
//#include "Board.cpp"
Piece::Piece(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture)
    : x(x), y(y), isWhite(isWhite), isEmpty(isEmpty) {
    sprite.setTexture(*texture);
    sprite.setPosition(sf::Vector2f(x * scale, y * scale));
}
Piece::Piece() {}

    //void Piece::move(std::shared_ptr<Piece> destination_square);
    /*{

    }*/
    void Piece::move(std::shared_ptr<Piece>& destination, bool Capture, bool& Turn)
    {
    }
    std::vector<std::pair<int, int>> Piece::legal_movesWhite(const Board& tempBoard)
    {
        std::vector<std::pair<int, int>> piece;
        return piece;
    }
    std::vector<std::pair<int, int>> Piece::legal_movesBlack(const Board& tempBoard)
    {
        std::cout << "BLET TU AUTISTE TUSCIA FNC JUK DARAI";
        std::vector<std::pair<int, int>> piece;
        return piece;
    }
    std::vector<std::shared_ptr<Piece>> Piece::dangerous_movesWhite()
    {
         return std::vector<std::shared_ptr<Piece>>();
    }
    std::vector<std::shared_ptr<Piece>> Piece::dangerous_movesBlack()
     {
         return std::vector<std::shared_ptr<Piece>>();
     }
    std::vector<std::shared_ptr<Piece>> Piece::controlled_squareWhite()
    {
        return std::vector<std::shared_ptr<Piece>>();
    }
    std::vector<std::shared_ptr<Piece>> Piece::controlled_squareBlack()
    {
        return std::vector<std::shared_ptr<Piece>>();
    }
