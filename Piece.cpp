#include "Piece.h"
    Piece::Piece(bool isWhite, int row, int col, char figure)
        : isWhite(isWhite), row(row), col(col), figure(figure), selected(false) {
    }
    //void Piece::move(std::shared_ptr<Piece> destination_square);
    /*{

    }*/
    void Piece::move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn)
    {
    }
