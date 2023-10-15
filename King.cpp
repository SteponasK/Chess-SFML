//#include "King.h"
//#include "Constants.h"
//#include <iostream>
//#include "Board.cpp"
//#include <memory>
//#include "Empty_Square.h"
//#include "Piece_Textures.h"
//
//King::King(int x, int y, bool isWhite,  std::shared_ptr<sf::Texture> texture)
//    : Piece(x, y, isWhite, figure){ // Constructor
//    sprite.setTexture(*texture);
//    sprite.setPosition(sf::Vector2f(row * scale, col * scale));
//}
//
//void King::move(std::shared_ptr<Piece>& piece_to_move, std::shared_ptr<Piece>& destination_square, bool& Turn) {
//    if (isWhite) legal_movesW();
//    else legal_movesB();
//    
//    /*for (auto legal_move : legal_moves)
//    {
//
//    }*/
//
//}
//std::vector<std::shared_ptr<Piece>> King::legal_movesWhite(/*int row, int col, bool isWhite, bool first_move*/) {
//    int delta_x;
//}
//std::vector<std::shared_ptr<Piece>> King::legal_movesBlack(/*int row, int col, bool isWhite, bool first_move*/) {
//
//}