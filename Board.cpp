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



class Board {
public:
    int WKingX;
    int WKingY;
    int BKingX;
    int BKingY;
    Board(const Board& other) { // sita constructor padaryt private
        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < numRows; j++) {
                if (other.square[i][j]) {
                    this->square[i][j] = std::make_shared<Piece>(*other.square[i][j]);
                }
                else {
                    this->square[i][j] = nullptr;
                }
            }
        }
    }
    Board() {
        for (int i = 0; i < 8; ++i) // pakeist i x ir y
        {
            for (int j = 0; j < 8; ++j)
            {
                // bool White = true
                // bool black = false
                // ir tada vietoj true/false tu dalyku padaryt, cleaner bus
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
                }
                else if (i == 0 && (j == 0 || j == 7))
                {
                    square[j][i] = std::make_shared<Rook>(j, i, false, false, pieceTextures.b_rook_text);
                }
                else if (i == 0 && (j == 2 || j == 5))
                {
                    square[j][i] = std::make_shared<Bishop>(j, i, false, false, pieceTextures.b_bishop_text);
                }
                else if (i == 7 && (j == 2 || j == 5))
                {
                    square[j][i] = std::make_shared<Bishop>(j, i, true, false, pieceTextures.w_bishop_text);
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


    bool check_move(Board &board, std::shared_ptr<Piece> piece/*, std::shared_ptr<Piece> destination*/)
    { // Function to check if move is legal
        
        // reikia dar check ar dabartyje king nera in check

            // Moves to the right
        
        for (int i = piece->x + 1; i < 8; ++i)
        {
            //legalMoves.push_back(std::make_pair(i, y));
            int x = piece->x;
            int y = piece->y;
           /* if (!square[i][y]->isEmpty)
            {
                i =
            }*/
        }

        // Moves to the left
        for (int i = piece->x - 1; i >= 0; --i)
        {
           // legalMoves.push_back(std::make_pair(i, y));
        }

        // Moves down
        for (int i = piece->y + 1; i < 8; ++i)
        {
          //  legalMoves.push_back(std::make_pair(x, i));
        }

        // Moves up
        for (int i = piece->y - 1; i >= 0; --i)
        {
            //legalMoves.push_back(std::make_pair(x, i));
        }
        //for (int i = 0; i < legalMOVES.size(); ++i)
        //{
        //    //padaryti bool isKnight (galima sokineti per pieces)
        //    // jeigu isKnight tada break
        //    
        //    //ir dabar mes removinam moves (kitos pieces negali sokinet)
        //    
        //    //edge case castling ir en passant
        //    if (piece->y - legalMOVES.at(i)->y > 0) // kertam i virsu
        //    {
        //        if (!legalMOVES.at(i)->isEmpty) // sitas uzimtas langelis
        //        { // tai remove visus moves uz jo
        //            for (int j = i; j >= 0; --j)
        //            {
        //                for (int k = 0; k < legalMOVES.size(); ++k)
        //                {
        //                    if (legalMOVES.at(k) == legalMOVES.at(j))
        //                        legalMOVES.erase(legalMOVES.begin() + k);
        //                }
        //            }
        //        }
        //     }
                 // else if i same eile
                 // 
           // if(square[legalMOVES[i]->x][])
      //  }
        std::vector<std::shared_ptr<Piece>> legalMoves_copy;
        for (auto destination : legalMOVES)
        {
            Board tempBoard(board);
            std::shared_ptr<Piece> tempPiece = tempBoard.square[piece->x][piece->y];
            std::shared_ptr<Piece> tempDestination = tempBoard.square[destination->x][destination->y];
            tempBoard.move(tempPiece, tempDestination, false, false);
            if (!isKingInCheck(tempBoard, tempPiece->isWhite))
            {
                legalMoves_copy.push_back(destination);
            }
        }
        legalMOVES = legalMoves_copy;

        return true; // do smth with this
        //std::vector<std::shared_ptr<Piece>> LEGALMOVES;
        //std::vector<std::shared_ptr<Piece>> DANGEROUSMOVES;

        //if (tempPiece->isWhite)
        //{
        //    DANGEROUSMOVES = tempPiece->dangerous_movesWhite();
        //    LEGALMOVES = tempPiece->legal_movesWhite();
        //}
        //else
        //{
        //    DANGEROUSMOVES = tempPiece->dangerous_movesBlack();
        //    LEGALMOVES = tempPiece->legal_movesBlack();
        //}
        //for (int i = 0; i < LEGALMOVES.size(); ++i)
        //{
        //    for (int j = 0; j < DANGEROUSMOVES.size(); ++j)
        //    {
        //        if (LEGALMOVES.at(i) == DANGEROUSMOVES.at(j))
        //        {
        //            LEGALMOVES.erase(LEGALMOVES.begin() + i);
        //            // If the move is dangerous we erase it
        //        }
        //    }
        //}
        //bool capture = false; // sita reiks passint kaip parameter
        //for (auto LEGALMOVE : LEGALMOVES) // durna logika
        //{
        //    if (LEGALMOVE == tempDestination)
        //    {
        //        tempBoard.move(piece,tempDestination, false, false); // en passant and castling to be done
        //        if (tempBoard.isKingInCheck(tempPiece->isWhite, WKingX, WKingY, BKingX, BKingY))
        //        {
        //            return 0;
        //            //create maybe destructors to delete this mess.
        //        }
        //            
        //        else return 1;
        //    }
        //    break;
        //}
    }
    void controlledSquaresBlack() {}
    void controlledSquaresWhite() {}
    bool isKingInCheck(Board& board, bool king_color)
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                std::shared_ptr<Piece> currentPiece = board.square[j][i];
                if (currentPiece->isWhite != king_color) // randam enemy pieces
                {
                    std::vector<std::pair<int, int>>  opponentMoves;
                    if (currentPiece->isWhite)
                    {
                        opponentMoves = currentPiece->legal_movesBlack();
                    }
                    else
                    {
                        opponentMoves = currentPiece->legal_movesWhite();
                    }
                    for (auto move : opponentMoves)
                    {
                        if (currentPiece->isWhite)
                        {
                            if (move.first == WKingX && move.second == WKingY)
                                return true;
                        }
                        else
                        {
                            if (move.first == BKingX && move.second == BKingY)
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    void move(std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination, bool castle, bool passant){ // castle passant sutvarkyt dar 
        // piece doesnt change in the array
        for (auto move : legalMOVES)
        {
            if (move == destination)
            {
                if (castle)
                {
                    // do casling
                    break;
                }
                if (passant)
                {
                    //do the move
                    break;
                }
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
                destination->isEmpty = false;
               square[pieceX][pieceY] = std::make_shared<Empty_Square>(pieceX, pieceY, false, true, pieceTextures.w_knight_text);
                std::cout << "WWUWUW";
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
                std::cout << std::endl << WKingX << WKingY << std::endl;
                std::cout << square[WKingX][WKingY]->isWhite;
                std::cout << square[WKingX][WKingY]->isKing;
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

           std::cout << "move legal\n";
       }
       std::cout << "pabaiga funkcijos highlightmoves update\n"; 
       std::cout << legalMOVES.size();
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
       std::cout << piece->x << ' ' << piece->y << ' ' << piece->isKing << '\n';
       printf("function calculate_legal_moves called\n");
       std::vector<std::pair<int, int>> legalMoves_pair;
        
       if (piece->isWhite)
       {
           legalMoves_pair = piece->legal_movesWhite();
           std::cout << "WHITE PIECE\n";
       }
       else
       {
           legalMoves_pair = piece->legal_movesBlack();
           std::cout << "BLACK PIECE\n";
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