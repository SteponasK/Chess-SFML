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
     bool Piece::legal_movesWhite(std::shared_ptr<Piece>& destination_square)
    {
         return 1;
    }
     bool Piece::legal_movesBlack(std::shared_ptr<Piece>& destination_square)
    {
         return 1;
    }
