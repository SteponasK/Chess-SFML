#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <memory>
//#include "Board.cpp"
class Board; // Forward declaration (circular dependancy workaround)
class Piece {
public:
    Piece(int x, int y, bool isWhite, bool isEmpty, std::shared_ptr<sf::Texture> texture);
    Piece();
    virtual ~Piece() {}
    virtual std::shared_ptr<Piece> clone() const {
        return std::make_shared<Piece>(*this);
    }
    virtual void move(std::shared_ptr<Piece>& destination_square, bool Capture, bool& Turn); // sita padaryt kkiekvienos vaiko class .cpp faile
    // move() function i think will not be needed for each piece.
    virtual std::vector<std::pair<int, int>> legal_movesWhite(const Board& tempBoard);
    virtual std::vector<std::pair<int, int>> legal_movesBlack(const Board& tempBoard);
    virtual std::vector<std::shared_ptr<Piece>> dangerous_movesWhite(); // moves that can not be played (king would be put in check)
    virtual std::vector<std::shared_ptr<Piece>> dangerous_movesBlack();
    virtual std::vector<std::shared_ptr<Piece>> controlled_squareWhite();
    virtual std::vector<std::shared_ptr<Piece>> controlled_squareBlack();

    /*0
    for(everypiece): piece.legal_moves(isWhite) controlledSquares.push_back
    /*
    * 
    * TO DO:
    * create logic for: highlight legal moves:
    * ( drawina rutuliukus. bet tada reikia padaryti:
     1.kai selected1 == true, tada calculate legal moves.
     2. Highlight legal moves
     3. Jeigu paspausta ant legal move, tada move
    * 
    * 
    * 
    */
   // std::shared_ptr<Board> boardPointer;
    int x;
    int y;
    bool isEmpty;
    bool isWhite;
    bool highlight = false; // Highlight the field if it's legal.
    bool isKing = false;
    bool isQueen = false;
    bool isBishop = false;
    bool isKnight = false;
    bool isPawn = false;
    bool isRook = false;
    bool isFirstMove = true;
    sf::Sprite sprite;
    std::vector<std::shared_ptr<Piece>> controlledSquares;
};

#endif // !PIECE_H

