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
#include <Windows.h>

// bugas, nes kiekvienoje legalmoves fnc naudoja board, o ne tempboardus
// tsg i kiekvina funkcija pluggint boarda ir tada pakeist is board i ta board
class Board {
public:
    //std::shared_ptr<Board> boardPointer = nullptr;
    int WKingX;
    int WKingY;
    int BKingX;
    int BKingY;
    //std::shared_ptr<Board> currentBoard;
   /* Board(const Board& other, bool isWhite, int KingX, int newKingX) {

    }*/
    Board(const Board& other) { // sita constructor padaryt private
       // boardPointer = std::shared_ptr<Board>(this);
        // deep copy
        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < numRows; j++) {
                if (other.square[i][j]) {
                    this->square[i][j] = other.square[i][j]->clone();
                   // this->square[i][j]->boardPointer = boardPointer;
                   
                   // std::cout << "called";
                   /* if (other.square[i][j]->isKing) {
                        this->square[i][j] = std::make_shared<King>(*other.square[i][j]);*/
                    /*else if (other.square[i][j]->isQueen)
                        this->square[i][j] = std::make_shared<Queen>(*other.square[i][j]);
                    else if (other.square[i][j]->isBishop)
                        this->square[i][j] = std::make_shared<Bishop>(*other.square[i][j]);
                    else if (other.square[i][j]->isKnight)
                        this->square[i][j] = std::make_shared<Knight>(*other.square[i][j]);
                    else if (other.square[i][j]->isRook)
                        this->square[i][j] = std::make_shared<Rook>(*other.square[i][j]);
                    else if (other.square[i][j]->isPawn)
                        this->square[i][j] = std::make_shared<Pawn>(*other.square[i][j]);
                    else
                        this->square[i][j] = std::make_shared<Empty_Square>(*other.square[i][j]);*/
                    
                }
                else {
                    this->square[i][j] = nullptr;
                    std::cout << "BOARD CONSTRUCTOR BUGAS";
                }
            }
        }
    }
    Board() {
      //  boardPointer = std::shared_ptr<Board>(this);
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
                   // square[j][i]->boardPointer = boardPointer;
                   // board.square[j][i]->empty_square = false;
                }
                else if (i == 0 && j == 4) // Black king
                {
                    square[j][i] = std::make_shared<King>(j, i, false, false, pieceTextures.b_king_text);
                    BKingX = j;
                    BKingY = i;
                    square[j][i]->isKing = true;
                   // square[j][i]->boardPointer = boardPointer;
                  
                }
                else if (i == 7 && j == 3)
                {
                    square[j][i] = std::make_shared<Queen>(j, i, true, false, pieceTextures.w_queen_text);
                    square[j][i]->isQueen = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 0 && j == 3)
                {
                    square[j][i] = std::make_shared<Queen>(j, i, false, false, pieceTextures.b_queen_text);
                    square[j][i]->isQueen = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
                else if ( i == 7 && (j == 0 || j == 7) )
                {
                    square[j][i] = std::make_shared<Rook>(j, i, true, false, pieceTextures.w_rook_text);
                    square[j][i]->isRook = true;
                    //square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 0 && (j == 0 || j == 7))
                {
                    square[j][i] = std::make_shared<Rook>(j, i, false, false, pieceTextures.b_rook_text);
                    square[j][i]->isRook = true;
                    //square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 0 && (j == 2 || j == 5))
                {
                    square[j][i] = std::make_shared<Bishop>(j, i, false, false, pieceTextures.b_bishop_text);
                    square[j][i]->isBishop = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 7 && (j == 2 || j == 5))
                {
                    square[j][i] = std::make_shared<Bishop>(j, i, true, false, pieceTextures.w_bishop_text);
                    square[j][i]->isBishop = true;
                    //square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 0 && (j == 1 || j == 6))
                {
                    square[j][i] = std::make_shared<Knight>(j, i, false, false, pieceTextures.b_knight_text);
                    square[j][i]->isKnight = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 7 && (j == 1 || j == 6))
                {
                    square[j][i] = std::make_shared<Knight>(j, i, true, false, pieceTextures.w_knight_text);
                    square[j][i]->isKnight = true;
                    //square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 1)
                {
                    square[j][i] = std::make_shared<Pawn>(j, i, false, false, pieceTextures.b_pawn_text);
                    square[j][i]->isPawn = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
                else if (i == 6)
                {
                    square[j][i] = std::make_shared<Pawn>(j, i, true, false, pieceTextures.w_pawn_text);
                    square[j][i]->isPawn = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
                else
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, false, true, pieceTextures.b_knight_text);
                    square[j][i]->isEmpty = true;
                   // square[j][i]->boardPointer = boardPointer;
                }
            }
        }
    }
    
    const int numRows = 8;
    const int numCols = 8;
    std::array<std::array<std::shared_ptr<Piece>, 8>, 8 > square;
    bool checkmate = false;
    bool getCheckmate() const {
        
        return checkmate;
    }

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
            
            if (isKingInCheck(tempBoard, isWhite, tempBoard.checkmate)){

                return false;

            }
        }
        

        return true;
    }
    bool check_moveALL(Board &tempBOARD, bool colour) {
        Board temp(tempBOARD);
        bool flag = false;
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if ((square[j][i]->isWhite != colour) && !square[j][i]->isEmpty) {
                    temp.calculate_legal_moves(square[j][i], temp);
                    if (check_move(temp, square[j][i])) {
                        flag = check_move(temp, square[j][i]);
                            if (flag) {
                                std::cout << "flag = good";
                                return true;
                        }
                    }// turi  moves
                      
                }
                

            }
        }
        std::cout << "returning false";
       // std::cout << "\ncount is: " << count << std::endl;
        return flag;
    }
    bool check_move(Board &board, std::shared_ptr<Piece> piece/*, std::shared_ptr<Piece> destination*/)
    { // Function to check if move is legal
        
     
        std::vector<std::shared_ptr<Piece>> legalMoves_copy;
        system("CLS");
        for (auto destination : board.legalMOVES)
        {
            
            std::cout << "checking the move\n";
            Board tempBoard(board);
            std::shared_ptr<Piece> tempPiece = tempBoard.square[piece->x][piece->y];
            std::shared_ptr<Piece> tempDestination = tempBoard.square[destination->x][destination->y];
           
            if (tempPiece->isKing && tempPiece->isFirstMove && // jeigu skiriasi per 2 (castling)
                std::abs( std::abs(tempDestination->x) - std::abs(tempPiece->x)) == 2) {
                if (can_castle(tempBoard,tempPiece->x, tempDestination->x, tempPiece->isWhite)) {
                    legalMoves_copy.push_back(destination);
                }
                continue;
                std::cout << "CONTINUOED";
            }
            tempBoard.calculate_legal_moves(tempPiece, tempBoard);
           // std::cout << "check_move fnc tmepboard legal move size: " << tempBoard.legalMOVES.size() << std::endl;
            tempBoard.move(tempPiece, tempDestination, false, false);
            std::cout << "\nMOVE COORDS\n";
            std::cout << ' ' << tempBoard.getPreviousMove().first.x << tempBoard.getPreviousMove().first.y << "\n";
            std::cout << ' ' << tempBoard.getPreviousMove().second.x << tempBoard.getPreviousMove().second.y << "\n";
            std::cout << "\nMOVE COORDS\n";
            // if (tempPiece->isWhite) {
              //  tempBoard.WKingX = 
           // }
            if (!isKingInCheck(tempBoard, tempPiece->isWhite, tempBoard.checkmate))
            {
                std::cout << "NOT IN CHECK";
                legalMoves_copy.push_back(destination);
            }
            else {
                std::cout << "King in check!\n";
            }

            //legalMoves_copy.push_back(destination);
        }
        
        board.legalMOVES = legalMoves_copy;
        if (!legalMoves_copy.empty()) {
            std::cout << "\nMove yra, returniname true\n";
            return true;
        }
        else {
            return false;
        }
          //  std::cout << "DEJA YRA MOVES\n";
        // paejus reiktu padaryti funckija ar yra legalmoves, taip pat kaip cia.
        // dabar surandame ar checkmate, tik paspaudus ant checkmated spalvos figureles.

       // return true; // do smth with this
    }
    void controlledSquaresBlack() {}
    void controlledSquaresWhite() {}
    bool isKingInCheck(Board board, bool king_color, bool& mate) // kazkas blogai su currentpiece, neduoda legal moves
    {// Check implementation needed
        Board tempBoard(board);
        bool check = false;
         mate = false;
      //  std::cout << "\n\n\n\n\n\n\n\niskingincheck called\n";
     //  std::cout << "FUNCTION CALLED\n";
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                std::shared_ptr<Piece> currentPiece = tempBoard.square[j][i];
                if (!tempBoard.square[j][i]) {;
                }
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
                auto currentPiece = tempBoard.square[j][i];

                if (currentPiece->isWhite != king_color && !currentPiece->isEmpty) // randam enemy pieces
                { // jeigu piece yra juoda, 
                    std::vector<std::pair<int, int>>  opponentMoves;

                    tempBoard.calculate_legal_moves(currentPiece, tempBoard);
                    for (auto move : tempBoard.legalMOVES)
                    {
                        if (currentPiece->isWhite)
                        {
                            if (move->x == tempBoard.BKingX && move->y == tempBoard.BKingY)
                                check = true;
                            else
                                mate = false;
                        }
                        else
                        {
                            if (move->x == tempBoard.WKingX && move->y == tempBoard.WKingY)
                                check = true;
                            else
                                mate = false;
                        }
                        if (check && !checkmate)
                            break;
                        tempBoard.removeLegal_moves();
                    }
                }
            }
        }
        return check;
    }
    std::vector<std::pair<Piece, Piece>> Moves;
    std::pair<Piece, Piece> getPreviousMove() const {
        
        if (Moves.empty()) {
            Piece piece(0, 0, false, false, pieceTextures.empty_square);
            return std::make_pair(piece, piece);
        }
        return Moves.back();
    }
    std::pair<Piece, Piece> getMove(const int index) const {

        if (Moves.empty()) {
           
        }
        if(Moves.size() > index)
            return Moves.at(index);

        Piece piece(0, 0, false, false, pieceTextures.empty_square);
        return std::make_pair(piece, piece);
    }
    int getMoveSize() const {

    int size = Moves.size();
        return size;
    }
    // 
    // 
    // 
    // 
    void HASLEGALMOVES(Board &currboard) {
        // problema: paskaiciuoja pseudo legal moves, ir tada galvoja kad yra ejimas good.
        std::cout << "\nFNC CALLED\n";
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (square[j][i]->isWhite) {
                    auto moves = square[j][i]->legal_movesWhite(currboard);
                    if (!moves.empty()) {
                       /* std::cout << "LEGAL MOVES HAS THIS PIECE: \n";
                        std::cout << square[j][i]->x << ' ' << square[j][i]->y <<
                            "LEGAL MOVES PIECE END \n";*/
                    }
                }
                else {
                    
                        auto moves = square[j][i]->legal_movesBlack(currboard);
                        if (!moves.empty()) {
                            std::cout << "LEGAL MOVES HAS THIS PIECE: \n";
                            std::cout << square[j][i]->x << ' ' << square[j][i]->y <<
                                "LEGAL MOVES PIECE END \n";
                        }
                    
                }
                
            }
        }
    }
    bool Checkmate(const Board& currentBoard,bool kingColour, bool &mate)  {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                auto currentPiece = currentBoard.square[j][i];
                if ((currentPiece->isWhite == kingColour) && !currentPiece->isEmpty) {
                    int isWhite = currentPiece->isWhite;
                   // std::vector<std::pair<Piece, Piece>> currentLegalMoves;
                    if (isWhite) {
                       //
                        auto  currentLegalMoves = currentPiece->legal_movesBlack(currentBoard);
                        if (!currentLegalMoves.empty())
                        {
                            std::cout << "WHIET THERE IS NO CHECKMATE";
                            return false;
                        }
                           
                    }
                    else {
                       auto  currentLegalMoves = currentPiece->legal_movesBlack(currentBoard);
                       if (!currentLegalMoves.empty())
                       {
                           std::cout << "BLACK THERE IS NO CHECKMATE";
                           return false;
                       }
                       
                    }
                    
                }       
                
            }
        }
        return true;
    }
    bool move(std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination, bool castle, bool passant){ // castle passant sutvarkyt dar 
        // piece doesnt change in the array
        for (auto move : legalMOVES)
        {
            if (move == destination)
            {
                // SITA PADARYT I FNC addMove();
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
               if (finalSquare->isPawn) {
                   //std::cout << "IT IS A APAWNH";
                   auto size = getMoveSize();
                   //auto size = 0;
                   //std::pair<Piece, Piece> move;
                   std::cout << "\nget move SIZE:" << size << std::endl;
                   if (size >= 2) {
                       auto move = getMove(size - 2); // Move that we played before this one
                       std::cout << "x1:" << move.first.x << "x2:" << move.second.x;
                       std::cout << "y1:" << move.first.y << "y2:" << move.second.y;
                       //  move->x
                       
                       if (finalSquare->isWhite) {
                           if ((finalSquare->y + 1 == move.second.y) && finalSquare->x == move.second.x) {
                               if (move.first.y == 1 && move.second.y == 3) {
                                   square[move.second.x][move.second.y] = std::make_shared<Empty_Square>(move.second.x, move.second.y, false, true, pieceTextures.w_knight_text);
                                   std::cout << "IT WORKDS";
                               }
                           }
                           std::cout << "NOT WHITE";
                           
                       }
                       else {
                           std::cout << "WHITE";
                           if ((finalSquare->y - 1 == move.second.y) && finalSquare->x == move.second.x) {
                               if (move.first.y == 6 && move.second.y == 4) {
                                   square[move.second.x][move.second.y] = std::make_shared<Empty_Square>(move.second.x, move.second.y, false, true, pieceTextures.w_knight_text);
                                   // sitie abu same tai gali but same fnc bet skaiciai nu zodziu idk db
                                   std::cout << "IT WORKDS";
                               }
                           }
                            
                       }
                   }
               }
                      // break;
                     
              // if(finalSquare->isPawn && ) is pawn and capture kreivai and tam langeli nebuvo prieso
               destination->isFirstMove = false;

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
                return true;
            }
        }
        
        return false;
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
   void calculate_legal_moves(std::shared_ptr<Piece> piece, const Board& tempBoard) // surandam legal moves
   {
     //  std::cout << piece->x << ' ' << piece->y << ' ' << piece->isKing << '\n';
     //  printf("function calculate_legal_moves called\n");
       std::vector<std::pair<int, int>> legalMoves_pair;
     //  std::cout << "calculating legal moves ";
       if (piece->isWhite)
       {
           legalMoves_pair = piece->legal_movesWhite(tempBoard);
          // std::cout << " calculate_legal_moves fnc called white\n";
       }
       else
       {
           legalMoves_pair = piece->legal_movesBlack(tempBoard);
          // std::cout << " calculate_legal_moves fnc called black\n";
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