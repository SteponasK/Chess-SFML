#include "Piece.h"
    Piece::Piece(int x, int y, bool isWhite, bool isEmpty)
        : x(x), y(y), isWhite(isWhite),  isEmpty(isEmpty){
    }
    //void Piece::move(std::shared_ptr<Piece> destination_square);
    /*{

    }*/
    void Piece::move(std::shared_ptr<Piece>& destination, bool Capture, bool& Turn)
    {
    }
    std::vector<std::shared_ptr<Piece>> Piece::legal_movesWhite()
    {
        return std::vector<std::shared_ptr<Piece>>();
    }
    std::vector<std::shared_ptr<Piece>> Piece::legal_movesBlack()
    {
        return std::vector<std::shared_ptr<Piece>>();
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
