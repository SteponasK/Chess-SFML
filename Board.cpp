#include <array>
#include <memory>
#include "Piece.h"
#include "Empty_Square.h"
#include "Piece_textures.h"
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
                    square[j][i] = std::make_shared<Empty_Square>(j, i, true, false, pieceTextures.w_king_text);
                    WKingX = j;
                    WKingY = i;
                    square[j][i]->isKing = true;
                    //board.square[j][i]->empty_square = false;
                }
                else if (i == 0 && j == 4)
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, false, false, pieceTextures.b_king_text);
                    BKingX = j;
                    BKingY = i;
                    square[j][i]->isKing = true;
                }
                else
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, false, true, pieceTextures.b_knight_text); // pakeist kad nebutu false
                }
            }
        }
    }

    const int numRows = 8;
    const int numCols = 8;
    std::array<std::array<std::shared_ptr<Piece>, 8>, 8 > square;
    bool check_move(Board &board, std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination)
    { // Function to check if move is legal
        Board tempBoard(board);
        std::shared_ptr<Piece> tempPiece = tempBoard.square[piece->x][piece->y];
        std::shared_ptr<Piece> tempDestination = tempBoard.square[destination->x][destination->y];
        
        std::vector<std::shared_ptr<Piece>> LEGALMOVES;
        std::vector<std::shared_ptr<Piece>> DANGEROUSMOVES;

        if (tempPiece->isWhite)
        {
            DANGEROUSMOVES = tempPiece->dangerous_movesWhite();
            LEGALMOVES = tempPiece->legal_movesWhite();
        }
        else
        {
            DANGEROUSMOVES = tempPiece->dangerous_movesBlack();
            LEGALMOVES = tempPiece->legal_movesBlack();
        }
        for (int i = 0; i < LEGALMOVES.size(); ++i)
        {
            for (int j = 0; j < DANGEROUSMOVES.size(); ++j)
            {
                if (LEGALMOVES.at(i) == DANGEROUSMOVES.at(j))
                {
                    LEGALMOVES.erase(LEGALMOVES.begin() + i);
                    // If the move is dangerous we erase it
                }
            }
        }
        bool capture = false; // sita reiks passint kaip parameter
        for (auto LEGALMOVE : LEGALMOVES)
        {
            if (LEGALMOVE == tempDestination)
            {
                tempBoard.move(piece,tempDestination, false, false); // en passant and castling to be done
                if (tempBoard.isKingInCheck(tempPiece->isWhite, WKingX, WKingY, BKingX, BKingY))
                    return 1;
                else return 0;
            }
            break;
        }
    }
    bool isKingInCheck(bool isWhite, int WkingX, int WkingY, int BkingX, int BkingY)
    {
        std::vector<std::shared_ptr <Piece>> all_dangerous_squares;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (square[j][i]->isWhite == true && isWhite == true)
                {
                    std::vector<std::shared_ptr<Piece>> dangerous_squares = square[j][j]->controlled_squareWhite();

                    for (auto square : dangerous_squares)
                    {
                        all_dangerous_squares.push_back(square);
                    }
                }
                else if (square[j][i]->isWhite == false && isWhite == false)
                {
                    std::vector<std::shared_ptr<Piece>> dangerous_squares = square[j][j]->controlled_squareBlack();

                    for (auto square : dangerous_squares)
                    {
                        all_dangerous_squares.push_back(square);
                    }
                }
            }
        }
        if (isWhite)
        {
            for (auto square : all_dangerous_squares)
            {
                if (square->x == WkingX && square->y == WkingY)
                {
                    return 1;
                }
            }
        }
        else
        {
            for (auto square : all_dangerous_squares)
            {
                if (square->x == BkingX && square->y == BkingY)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    void move(std::shared_ptr<Piece> piece, std::shared_ptr<Piece> destination, bool castle, bool passant){
        // piece doesnt change in the array
            Piece temp(piece->x,piece->y,piece->isWhite, piece->isEmpty);
            piece->x = destination->x;
            piece->y = destination->y;
            destination = piece; // piece doesnt change in the array, bet sita line gal sutvarkys
            Piece_Textures text;
            destination = std::make_shared<Empty_Square>(temp.x, temp.y, false, true, text.b_knight_text);
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
    void initialise() // nereikalingas turbut, nes galim naudot constructors.
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {

                if (i == 7 && j == 4)
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, true, false, pieceTextures.w_king_text);
                    WKingX = j;
                    WKingY = i;
                    square[j][i]->isKing = true;
                    //board.square[j][i]->empty_square = false;
                }
                else if (i == 0 && j == 4)
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, false, false, pieceTextures.b_king_text);
                    BKingX = j;
                    BKingY = i;
                    square[j][i]->isKing = true;
                }
                else
                {
                    square[j][i] = std::make_shared<Empty_Square>(j, i, false, true, pieceTextures.b_knight_text); // pakeist kad nebutu false
                }
            }
        }
    }
}; extern Board board;