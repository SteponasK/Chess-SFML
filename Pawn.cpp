//#include "Pawn.h"
//#include "Constants.h"
//#include <iostream>
//#include "Board.cpp"
//#include <memory>
//#include "Empty_Square.h"
//#include "Piece_Textures.h"
//
//Pawn::Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture)
//    : Piece(isWhite, row, col, figure), first_Move(false) { // Constructor
//    sprite.setTexture(*texture);
//    sprite.setPosition(sf::Vector2f(row * scale, col * scale));
//}
//
//void Pawn::move(std::shared_ptr<Piece>& piece_to_move,std::shared_ptr<Piece>& destination_square, bool& Turn) {
//    std::vector<std::shared_ptr<Piece>>legal_moves;
//    if (!Turn) {
//        
//        if (col == 6) // reiskiasi default vietoje (pirmas ejimas)
//        {
//            if (board.square[row][col-1]->empty_square)
//            {
//                std::cout << "EMOTY SQUARE";
//                legal_moves.push_back(board.square[row][col - 1]);
//
//                if (board.square[row][col - 2]->empty_square)
//                    legal_moves.push_back(board.square[row][col - 2]);
//            }
//        }
//        else if(board.square[row][col - 1]->empty_square)
//            legal_moves.push_back(board.square[row][col - 1]);
//        if (board.square[row + 1][col - 1]->isWhite == false)
//        {
//            std::cout <<"selecetd";
//            legal_moves.push_back(board.square[row + 1][col - 1]);
//        }
//            
//        if (board.square[row - 1][col - 1]->isWhite == false)
//            legal_moves.push_back(board.square[row - 1][col - 1]);
//    }
//    else
//    {
//        if (col == 1) // reiskiasi default vietoje (pirmas ejimas)
//        {
//            if (board.square[row][col + 1]->empty_square)
//            {
//                std::cout << "EMOTY SQUARE";
//                legal_moves.push_back(board.square[row][col + 1]);
//
//                if (board.square[row][col + 2]->empty_square)
//                    legal_moves.push_back(board.square[row][col + 2]);
//            }
//        }
//        else if (board.square[row][col + 1]->empty_square)
//            legal_moves.push_back(board.square[row][col + 1]);
//        if (!board.square[row + 1][col + 1]->empty_square == false && board.square[row + 1][col + 1]->isWhite)
//            legal_moves.push_back(board.square[row + 1][col - 1]);
//        if (!board.square[row - 1][col + 1]->empty_square == false && board.square[row - 1][col + 1]->isWhite)
//            legal_moves.push_back(board.square[row - 1][col - 1]);
//    }
//    if (legal_moves.empty())
//    {
//        std::cout << "WTFEMPTY";
//    }
//    for (auto legal_move : legal_moves)
//    {
//        if (legal_move->col == destination_square->col && legal_move->row == destination_square->row)
//        {
//            std::cout << "TRYING TO CHANGE";
//            int temp_col = col;
//            int temp_row = row;
//             col = destination_square->col;
//             row = destination_square->row;
//             destination_square->col = temp_col;
//             destination_square->row = temp_row;
//            Turn = (Turn == 1) ? 0 : 1;
//            break;
//        }
//    }
//}
//bool Pawn::legal_move() {
//    if (isWhite)
//    {
//        if (first_Move)
//        {
//
//        }
//    }
//    return true;
//}