#ifndef BOARD_CPP

#define BOARD_CPP
#include <array>
#include <memory>
#include "Piece.h"
#include "Empty_Square.h"
#include "Piece_textures.h"
#include "King.h"
#include "Rook.h"
#include <iostream>
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Constants.h"


class Board {
public:
    int WKingX;
    int WKingY;
    int BKingX;
    int BKingY;
    //std::shared_ptr<Board> currentBoard;
   /* Board(const Board& other, bool isWhite, int KingX, int newKingX) {

    }*/
    Board(const Board& other) { // sita constructor padaryt private
        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < numRows; j++) {
                if (other.square[i][j]) {
                    this->square[i][j] = std::make_shared<Piece>(*other.square[i][j]);
                }
                else {
                    this->square[i][j] = nullptr;
                    std::cout << "BOARD CONSTRUCTOR BUGAS";
                }
            }
        }
    }
    //Board(const Board& other, int kingX, bool isWhite, bool kingX_default) {
    //    
    //    for (int i = 0; i < numCols; i++) {
    //        for (int j = 0; j < numRows; j++) {
    //            if (other.square[i][j]) {
    //                this->square[i][j] = std::make_shared<Piece>(*other.square[i][j]);
    //            }
    //            else {
    //                this->square[i][j] = nullptr;
    //            }
    //        }
    //    }
    //    

    //        //other.square[kingX_default][kingY];

    //}
    Board() {
        for (int i = 0; i < 8; ++i) // pakeist i x ir y
        {
            for (int j = 0; j < 8; ++j)
            {
                // bool White = true
                // bool black = false
                // ir tada vietoj true/false tu dalyku padaryt, cleaner bus
                //dar padaryt for loops be ifu, tiesiog kelis for loopsus gal idk dar.
                if (i == 7 && j == 4) // White king
                {
                    square[j][i] = std::make_shared<King>(j, i, true, false, pieceTextures.w_king_text);
                    WKingX = j;
                    WKingY = i; 
                    square[j][i]->isKing = true;
                    //board.square[j][i]->empty_square = false;
                }
                else if (i == 0 && j == 4) // Black king
                {
                    square[j][i] = std::make_shared<King>(j, i, false, false, pieceTextures.b_king_text);
                    BKingX = j;
                    BKingY = i;
                    square[j][i]->isKing = true;
                  
                }
                else if (i == 7 && j == 3)
                {
                    square[j][i] = std::make_shared<Queen>(j, i, true, false, pieceTextures.w_queen_text);
                }
                else if (i == 0 && j == 3)
                {
                    square[j][i] = std::make_shared<Queen>(j, i, false, false, pieceTextures.b_queen_text);
                }
                else if ( i == 7 && (j == 0 || j == 7) )
                {
                    square[j][i] = std::make_shared<Rook>(j, i, true, false, pieceTextures.w_rook_text);
                    square[j][i]->isRook = true;
                }
                else if (i == 0 && (j == 0 || j == 7))
                {
                    square[j][i] = std::make_shared<Rook>(j, i, false, false, pieceTextures.b_rook_text);
                    square[j][i]->isRook = true;
                }
                else if (i == 0 && (j == 2 || j == 5))
                {
                    square[j][i] = std::make_shared<Bishop>(j, i, false, false, pieceTextures.b_bishop_text);
                }
                else if (i == 7 && (j == 2 || j == 5))
                {
                    square[j][i] = std::make_shared<Bishop>(j, i, true, false, pieceTextures.w_bishop_text);
                }
                else if (i == 0 && (j == 1 || j == 6))
                {
                    square[j][i] = std::make_shared<Knight>(j, i, false, false, pieceTextures.b_knight_text);

                }
                else if (i == 7 && (j == 1 || j == 6))
                {
                    square[j][i] = std::make_shared<Knight>(j, i, true, false, pieceTextures.w_knight_text);
                }
                else if (i == 1)
                {
                    square[j][i] = std::make_shared<Pawn>(j, i, false, false, pieceTextures.b_pawn_text);
                    square[j][i]->isPawn = true;
                }
                else if (i == 6)
                {
                    square[j][i] = std::make_shared<Pawn>(j, i, true, false, pieceTextures.w_pawn_text);
                    square[j][i]->isPawn = true;
                }
                else
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, false, true, pieceTextures.b_knight_text);
                   
                }
            }
        }
    }

    const int numRows = 8;
    const int numCols = 8;
    std::array<std::array<std::shared_ptr<Piece>, 8>, 8 > square;

    bool can_castle(Board board,int kingX, int destinationX, bool isWhite) {
        int kingY = (isWhite ? 7 : 0);
        int kingX_default = 4;
        for (int x = kingX; x < kingX + 3; ++x) {
            Board tempBoard(board);
            if (isWhite) {
                tempBoard.WKingX = x;
                tempBoard.WKingY = kingY;
            }
            else {
                tempBoard.BKingX = x;
                tempBoard.BKingY = kingY;
            }
            tempBoard.square[kingX_default][kingY] = std::make_shared<King>(kingX_default, kingY, isWhite, false, pieceTextures.w_king_text);
            tempBoard.square[kingX][kingY] = std::make_shared<King>(kingX, kingY, isWhite, false, pieceTextures.w_king_text);
            if (isKingInCheck(tempBoard, isWhite)){
                return false;
            }
        }
        

        return true;
    }
    bool check_move(Board &board, std::shared_ptr<Piece> piece/*, std::shared_ptr<Piece> destination*/)
    { // Function to check if move is legal
        
     
        std::vector<std::shared_ptr<Piece>> legalMoves_copy;
        for (auto destination : legalMOVES)
        {
            Board tempBoard(board);
            std::shared_ptr<Piece> tempPiece = tempBoard.square[piece->x][piece->y];
            std::shared_ptr<Piece> tempDestination = tempBoard.square[destination->x][destination->y];
           
            if (tempPiece->isKing && tempPiece->isFirstMove && // jeigu skiriasi per 2 (castling)
                std::abs( std::abs(tempDestination->x) - std::abs(tempPiece->x)) == 2) {
                if (can_castle(tempBoard,tempPiece->x, tempDestination->x, tempPiece->isWhite)) {
                    legalMoves_copy.push_back(destination);
                }
                continue;
            }
            tempBoard.calculate_legal_moves(tempPiece);
            std::cout << "check_move fnc tmepboard legal move size: " << tempBoard.legalMOVES.size() << std::endl;
            tempBoard.move(tempPiece, tempDestination, false, false);
           // if (tempPiece->isWhite) {
              //  tempBoard.WKingX = 
           // }
            if (!isKingInCheck(tempBoard, tempPiece->isWhite))
            {
                legalMoves_copy.push_back(destination);
            }
        }
        
        legalMOVES = legalMoves_copy;

        return true; // do smth with this
    }
    void controlledSquaresBlack() {}
    void controlledSquaresWhite() {}
    bool isKingInCheck(Board board, bool king_color) // kazkas blogai su currentpiece, neduoda legal moves
    {// Check implementation needed
        Board tempBoard(board);
        std::cout << "\n\n\n\n\n\n\n\niskingincheck called\n";
     //  std::cout << "FUNCTION CALLED\n";
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                std::shared_ptr<Piece> currentPiece = tempBoard.square[j][i];
                
                if (currentPiece->isKing) {
                    if (currentPiece->isWhite) {
                        tempBoard.WKingX = currentPiece->x;
                        tempBoard.WKingY = currentPiece->y;
                    }
                    else {
                        
                        tempBoard.BKingX = currentPiece->x;
                        tempBoard.BKingY = currentPiece->y;
                        
                        // We can optimise, by breaking when both values are initialised.
                        // also we can check most common king spots first for more efficiency.
                    }
                }
            }
        }
       // std::cout << "white x: " << board.WKingX << " y: " << board.WKingY << std::endl;
       // std::cout << "black x: " << board.BKingX << " y: " << board.BKingY << std::endl;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                std::shared_ptr<Piece> currentPiece = tempBoard.square[j][i];

                if (currentPiece->isWhite != king_color && !currentPiece->isEmpty) // randam enemy pieces
                { // jeigu piece yra juoda, 
                    std::cout << "cords: " << currentPiece->x << currentPiece->y << std::endl;
                    std::vector<std::pair<int, int>>  opponentMoves;
                  //  std::cout << currentPiece->x <<" y: " << currentPiece->y << std::endl;
                    tempBoard.calculate_legal_moves(currentPiece);
                    std::cout << "legalmove size: " << tempBoard.legalMOVES.size() << std::endl;
                    if (!tempBoard.legalMOVES.empty()) {
                        for (int i = 0; i < 10; ++i) {
                            std::cout << std::endl;
                            std::cout << "LEGALMOVES TEMP IS NOT EMPTY";
                        }
                    }
                    for (auto move : tempBoard.legalMOVES)
                    {
                        std::cout << "GOING THRU THE MOVES\n";
                        if (currentPiece->isWhite)
                        {
                            if (move->x == board.BKingX && move->y == board.BKingY)
                                std::cout << "\n\n\n\n\nPRISILIETE\n\n\n\n";
                            return true;
                        }
                        else
                        {
                            std::cout << "COMPARING BLACK MOVES";
                            if (move->x == board.WKingX && move->y == board.WKingY)
                                std::cout << "\n\n\n\n\nPRISILIETE\n\n\n\n";
                            return true;
                        }
                        tempBoard.removeLegal_moves();
                    }
                    
                    
                    //if (currentPiece->isWhite)
                    //{
                    //  //  std::cout << "called white moves\n";
                    //    opponentMoves = currentPiece->legal_movesWhite();
                    //   
                    //   // std::cout << "white moves vector: " << opponentMoves.size() << std::endl;
                    //}
                    //else 
                    //{
                    //   // std::cout << "called black moves\n";
                    //    opponentMoves = currentPiece->legal_movesBlack();
                    //   // std::cout << "black moves vector: " << opponentMoves.size() << std::endl;
                    //}
                  //  std::cout << "size of opponen moves vector: " << opponentMoves.size() << std::endl;
                    /*for (auto move : opponentMoves)
                    {
                        std::cout << "GOING THRU THE MOVES\n";
                        if (currentPiece->isWhite)
                        {
                            if (move.first == board.BKingX && move.second == board.BKingY)
                                std::cout << "\n\n\n\n\nPRISILIETE\n\n\n\n";
                                return true;
                        }
                        else
                        {
                            std::cout << "COMPARING BLACK MOVES";
                            if (move.first == board.WKingX && move.second == board.WKingY)
                                std::cout << "\n\n\n\n\nPRISILIETE\n\n\n\n";
                                return true;
                        }
                    }*/
                }
            }
        }
        return false;
    }
    std::vector<std::pair<Piece, Piece>> Moves;
    std::pair<Piece, Piece> getPreviousMove() {
        
        if (Moves.empty()) {
            Piece piece(0, 0, false, false, pieceTextures.empty_square);
            return std::make_pair(piece, piece);
        }
        return Moves.back();
    }

    void move(std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination, bool castle, bool passant){ // castle passant sutvarkyt dar 
        // piece doesnt change in the array
        for (auto move : legalMOVES)
        {
            if (move == destination)
            {
                Turn = (Turn ? 0 : 1);
                Moves.push_back(std::make_pair(*piece, *destination)); // castling logic idk
                int pieceX = piece->x;
                int pieceY = piece->y;
                // swap pieces in square array
                square[piece->x][piece->y] = destination;
                square[destination->x][destination->y] = piece;

                // update the positions 
                std::swap(piece->x, destination->x);
                std::swap(piece->y, destination->y);

                // update the isEmpty 
               // piece->isEmpty = true;
               // 
                destination->isEmpty = false;
                std::shared_ptr<Piece> finalSquare = square[piece->x][piece->y];
               square[pieceX][pieceY] = std::make_shared<Empty_Square>(pieceX, pieceY, false, true, pieceTextures.w_knight_text);
               /*    std::cout << ("final square: ");
                   std::cout << finalSquare->x << ' ' << finalSquare->y <<
                       std::endl << " is a king?: " << finalSquare->isKing << std::endl <<
                       "is first move: " << finalSquare->isFirstMove << std::endl;*/
               
               if (finalSquare->isKing && finalSquare->isFirstMove &&
                   (finalSquare->x == 2 || finalSquare->x == 6))// jeigu skiriasi per 2 (castling)
               {
                   // change rooks location
                   if (piece->isWhite) {
                      //
                       if (piece->x == 2) { // king == piece, becuase they swapped
                           square[3][7] = std::make_shared<Rook>(3, 7, true, false, pieceTextures.w_rook_text);
                           square[0][7] = std::make_shared<Empty_Square>(0, 7, false, true, pieceTextures.w_knight_text);
                       }
                       else {
                           square[5][7] = std::make_shared<Rook>(5, 7, true, false, pieceTextures.w_rook_text);
                           square[7][7] = std::make_shared<Empty_Square>(7, 7, false, true, pieceTextures.w_knight_text);
                       }
                   }
                   else {
                       if (piece->x == 2) { // king == piece, becuase they swapped
                           square[3][0] = std::make_shared<Rook>(3, 0, false, false, pieceTextures.b_rook_text);
                           square[0][0] = std::make_shared<Empty_Square>(0, 0, false, true, pieceTextures.w_knight_text);
                       }
                       else {
                           square[5][0] = std::make_shared<Rook>(5, 0, false, false, pieceTextures.b_rook_text);
                           square[7][0] = std::make_shared<Empty_Square>(7, 0, false, true, pieceTextures.w_knight_text);
                       }
                   }
                   //W KNIGHT IS EMPTY SQUARE, CHANGE IT O EMPTY SQUARETEXTURE!
               }
              // if(finalSquare->isPawn && ) is pawn and capture kreivai and tam langeli nebuvo prieso
               destination->isFirstMove = false;
               //dar galima pazet jeigu last move buvo pawn move tt, tada cia paejus capture.
           //    std::cout << "WWUWUW";
                printf("NICE");

                 //Implement castling logic

                for (int i = 0; i < 8; ++i)
                {
                    for (int j = 0; j < 8; ++j) // Updating kings position
                    {
                        if (square[j][i]->isKing)
                        {
                            if (square[j][i]->isWhite)
                            {
                                WKingX = square[j][i]->x;
                                WKingY = square[j][i]->y; // cia gali but errors su x ir y / j ir i
                            }
                            else
                            {
                                BKingX = square[j][i]->x;
                                BKingY = square[j][i]->y;
                            }
                        }
                    }
                }
              //  std::cout << std::endl << WKingX << WKingY << std::endl;
              //  std::cout << square[WKingX][WKingY]->isWhite;
              //  std::cout << square[WKingX][WKingY]->isKing;
                break;
            }
        }
        
        
    }
   void highlightMoves_update()
    {
       for (int i = 0; i < 8; ++i) // sita pakeist, gal in main.cpp naudot removeHIghlighted moves, o tada sita callint
       {
           for (int j = 0; j < 8; ++j)
           {
               square[j][i]->highlight = false;
           }
       }
       for (auto move : legalMOVES)
       {
           move->highlight = true;

        //   std::cout << "move legal\n";
       }
     //  std::cout << "pabaiga funkcijos highlightmoves update\n"; 
     //  std::cout << legalMOVES.size();
    }
   void removeHighlighted_moves()
   {
       for (int i = 0; i < 8; ++i)
       {
           for (int j = 0; j < 8; ++j)
           {
               square[j][i]->highlight = false;
           }
       }
   }
   void calculate_legal_moves(std::shared_ptr<Piece> piece) // surandam legal moves
   {
     //  std::cout << piece->x << ' ' << piece->y << ' ' << piece->isKing << '\n';
     //  printf("function calculate_legal_moves called\n");
       std::vector<std::pair<int, int>> legalMoves_pair;
        
       if (piece->isWhite)
       {
           legalMoves_pair = piece->legal_movesWhite();
           std::cout << " calculate_legal_moves fnc called white\n";
       }
       else
       {
           legalMoves_pair = piece->legal_movesBlack();
           std::cout << " calculate_legal_moves fnc called black\n";
       }
       for (auto pair : legalMoves_pair)
       {
           legalMOVES.push_back(square[pair.first][pair.second]);
       }
   }
   void removeLegal_moves()
   {
       legalMOVES.clear();
   }

   std::vector<std::shared_ptr<Piece>> legalMOVES;
}; extern Board board; // sutvarkyti mess su public ir private stuff.

#endif // !BOARD_CPP