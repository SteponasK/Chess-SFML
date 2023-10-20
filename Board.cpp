#ifndef BOARD_CPP

#define BOARD_CPP
#include <array>
#include <memory>
#include "Piece.h"
#include "Empty_Square.h"
#include "Piece_textures.h"
#include "King.h"
#include <iostream>



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
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {

                if (i == 7 && j == 4)
                {
                    square[j][i] = std::make_shared<King>(j, i, true, false, pieceTextures.w_king_text);
                    WKingX = j;
                    WKingY = i; 
                    square[j][i]->isKing = true;
                    //board.square[j][i]->empty_square = false;
                }
                else if (i == 0 && j == 4)
                {
                    square[j][i] = std::make_shared<King>(j, i, false, false, pieceTextures.b_king_text);
                    BKingX = j;
                    BKingY = i;
                    square[j][i]->isKing = true;
                  
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
    //void move(std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination, bool castle, bool passant) {
    //    // Create a copy of the destination square
    //    std::shared_ptr<Piece> tempDestination = square[destination->x][destination->y];
    //    printf( "uwu");


    //    // Update the destination square with the piece being moved
    //    square[destination->x][destination->y] = piece;

    //    // Update the source square as empty
    //    square[piece->x][piece->y] = std::make_shared<Empty_Square>(piece->x, piece->y, false, true, Piece_Textures().b_knight_text);

    //    // Implement castling logic or any other specific move handling here

    //    // Update king positions if needed
    //    if (piece->isKing) {
    //        if (piece->isWhite) {
    //            WKingX = destination->x;
    //            WKingY = destination->y;
    //        }
    //        else {
    //            BKingX = destination->x;
    //            BKingY = destination->y;
    //        }
    //    }
    //}

    void move(std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination, bool castle, bool passant){ // castle passant sutvarkyt dar 
        // piece doesnt change in the array
        for (auto move : legalMOVES)
        {
            if (move == destination)
            {
                //Piece piece_temp(piece->x, piece->y, piece->isWhite, piece->isEmpty, pieceTextures.b_bishop_text);//b bishop text, because this is not needed, so it is random texture 
                //Piece destination_temp(destination->x, destination->y, destination->isWhite, destination->isEmpty, pieceTextures.b_bishop_text);//destination->sprite.getTexture()
                //square[destination->x][destination->y] = piece;
                //piece->x = destination_temp.x;
                //piece->y = destination_temp.y;

                // piece x y = destination x y
                // destination x y = piece x y
                // swap destyination su piece

                // sitas irgi neveikia (karalius pasivercia i white knight, o last langelis i juoda)
                std::swap(piece->x, destination->x);
                std::swap(piece->y, destination->y);
                std::swap(piece, destination);
                destination->isEmpty = true;
                destination->sprite.setTexture(*pieceTextures.w_knight_text);
                

                //square[piece_temp.x][piece_temp.y] = std::make_shared<Empty_Square>(piece_temp.x, piece_temp.y, false, true, pieceTextures.w_knight_text);
         
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
        
       // cia galiu padaryti, kad atgaunu structa, ir tada pushbackinu i legalmoves.
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
}; extern Board board;
//HIGHLIHT LEGAL MOVES

#endif // !BOARD_CPP