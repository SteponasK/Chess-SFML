#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <memory>
class Piece {
public:
    Piece(int x, int y, bool isWhite, bool isEmpty);
    virtual void move(std::shared_ptr<Piece>& destination_square, bool Capture, bool& Turn); // sita padaryt kkiekvienos vaiko class .cpp faile
    virtual std::vector<std::shared_ptr<Piece>> legal_movesWhite();
    virtual std::vector<std::shared_ptr<Piece>> legal_movesBlack();
    /*
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
    int x;
    int y;
    bool isEmpty;
    bool isWhite;
    sf::Sprite sprite;
};

#endif // !PIECE_H

