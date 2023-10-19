#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include "Piece_Textures.h"
#include "Piece.h"
#include "Pawn.h"
#include "Constants.h"
#include "Empty_Square.h"
#include "Board.cpp" //board declared in this file:
#include "King.h"
#include <Windows.h>

int scale{};
std::vector<std::shared_ptr<Piece>> controlledSquares;
//Board board;
Piece_Textures pieceTextures;
bool Turn = 0; // 0 - White, 1 - Black
bool wKingMoved = false;
bool bKingMoved = false;
Board board;


int main() // dabar padaryti ->move() funkcija pawn klasei kad butu galima judeti
{
    // galima padaryti kad butu global scope, bet tada reiktu .initialise funkcijos
   // board.initialise();
    /*
        TO DO:
        KAI PAJUDA PAWN, PADARYTI KAD TUSTI LANGELIAI CORRECTLY UZSIPILDYTU, NES DABAR NESAMONE // DONE
        KADANTI move() funkcija turi legal_moves in std::vector, tai tuos langelius butu galima highlight
        // Sutvarkyt markalyze visa


        10-09
        Kai darau pawn negali kirsti kito pawn, bet gali kirsti tuscia langeli.
        Padaryti logika jeigu row == 0 arba row == 7, kad kai skaiciuoja row+1 || row-1 neuzcrashintu
    
    */
    // Padaryti pieces values protected, jas gauti by getter function.
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    scale = window.getSize().x / 8;
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Resources/Board.png"))
    {
        std::cout << "error loading board texture";
        return 1;
    }
    sf::Sprite board_sprite(boardTexture);

    sf::Sprite highlightMove;
    sf::Texture hightlightMoveText;
    hightlightMoveText.loadFromFile("Resources/highlight_circle.png");
    highlightMove.setTexture(hightlightMoveText);
    highlightMove.setScale(0.22f, 0.22f);
    
    
    std::shared_ptr<Piece> selected_square1 = nullptr; // square which piece to move
    std::shared_ptr<Piece> selected_square2 = nullptr; // square to which you want to move
   //std::vector<std::shared_ptr<Piece>> legalMoves;
    //std::vector<std::shared_ptr<Piece>> dangerousMoves;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //////
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Loop through all the pieces
                // If a specific piece is selected, highlight legal moves
                for (int i = 0; i < 8; ++i)
                {
                    for (int j = 0; j < 8; ++j)
                    {
                        if (board.square[j][i])
                        {

                            if (board.square[j][i]->sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                            {
                                if (!selected_square1)
                                {
                                    if (Turn == 0)
                                    {
                                        if (!board.square[j][i]->isEmpty)
                                        {
                                            if (board.square[j][i]->isWhite == true) // galima i same spalva
                                            {
                                                selected_square1 = board.square[j][i];
                                                //board.updateHIghlightMoves();
                                                board.calculate_legal_moves(selected_square1);
                                                board.check_move(board, selected_square1);
                                                board.highlightMoves_update();
                                                ////h
                                            }
                                        }
                                    }
                                    else if (Turn == 1)
                                    {
                                        if (!board.square[j][i]->isEmpty)
                                        {
                                            if (board.square[j][i]->isWhite == false) // galima i same spalva
                                            {
                                                selected_square1 = board.square[j][i];
                                                board.calculate_legal_moves(selected_square1); // del sito
                                                board.check_move(board, selected_square1);
                                                board.highlightMoves_update();
                                                //board.updateMoves();
                                                /////
                                                
                                            }
                                        }
                                    }
                                }
                                else // jeigu turim pasirinke figura, galim pasirinkt destination langeli
                                {
                                    if ( (selected_square1 == board.square[j][i]))
                                    {
                                        selected_square1 = nullptr;
                                        board.removeHighlighted_moves();
                                        break;
                                    }
                                    else if ((selected_square1->isWhite == board.square[j][i]->isWhite) && !board.square[j][i]->isEmpty)
                                    {
                                        selected_square1 = board.square[j][i];
                                        board.calculate_legal_moves(board.square[j][i]); // isviso galima sita padet ne i loopa o veliau
                                        board.check_move(board, board.square[j][i]);
                                        board.highlightMoves_update();
                                        break;
                                    }
                                    else
                                    {
                                        selected_square2 = board.square[j][i];
                                        /*jeigu returnina false, tada nekeist turn*/board.move(selected_square1, selected_square2, false, false);
                                        board.removeHighlighted_moves();
                                        board.removeLegal_moves();
                                        selected_square1 = nullptr;
                                        selected_square2 = nullptr;
                                        // changge turn
                                    }
                                       /* bool Exists = false;*/
                                    // check_move board funkcija
                                    // move board funkcija
                                    // tada for each loopo nereik

                                    //for (auto legalMove : legalMoves)
                                    //{
                                    //    if (board.square[j][i] == legalMove)
                                    //    {
                                    //        Exists = true;
                                    //        if ((board.square[j][i]->isWhite != selected_square1->isWhite)
                                    //            && !board.square[j][i]->isEmpty) // different colour
                                    //            selected_square1->move(board.square[j][i], true, Turn); // capture
                                    //        else selected_square1->move(board.square[j][i], false, Turn); // not capture  
                                    //        break;
                                    //        //logic for castling needed later
                                    //    }
                                    //    
                                    //}
                                   /* if (!Exists)
                                    {
                                        std::cout << "Move doesn't exist\n";
                                        break;
                                    }*/
                                   /* std::cout << "SELECTED2";*/
                                }
                                /*if (selected_square1 && selected_square2)
                                {
                                    if ((selected_square1->isWhite && selected_square2->isWhite)
                                        || (!selected_square1->isWhite && !selected_square2->isWhite &&
                                            !selected_square2->isEmpty))
                                    {
                                        std::cout << "pasikeicia";
                                        selected_square1 = selected_square2;
                                        selected_square2 = nullptr;
                                    }///////
                                }*/
                            }
                            
                        }
                    }

                }

            }
        }

        // Other events
    
    // Game logic
    //check_legal_move(selected_square1, selected_square2); // sita fnc galima delete
        
        if (selected_square1)
        {
           // printf("Square1 is selected");
           
           
           // int dawdaw;






           //// std::cout << "selected_1: " << selected_square1->x + 1 << " " << selected_square1->y + 1 << std::endl;
           // if (selected_square1->isWhite){
           //     legalMoves = selected_square1->legal_movesWhite();
           //     dangerousMoves = selected_square1->dangerous_movesWhite();
           // }
           // else{
           //     legalMoves = selected_square1->legal_movesBlack();
           //     dangerousMoves = selected_square1->dangerous_movesBlack();
           // }
        }
        //for (int i = 0; i < legalMoves.size(); ++i)
        //{
        //    for (int j = 0; j < dangerousMoves.size(); ++j)
        //    {
        //        if (legalMoves.at(i) == dangerousMoves.at(j))
        //        {
        //            legalMoves.erase(legalMoves.begin() + i);
        //            // If the move is dangerous we erase it
        //        }
        //    }
        //}
        if (selected_square1)
        {
            //highlight legal moves.
        }
    //if (selected_square1 && selected_square2)
    //{ 
   
    //    selected_square1->move(selected_square2, true, Turn);
    //    selected_square1 = nullptr;
    //    selected_square2 = nullptr; // reikia padaryt kazka su nullptr kad galeciau pakeist values
   
    //    std::cout << std::endl  << "uwu" << Turn;
    //}
    window.clear(sf::Color::Black);
    window.draw(board_sprite);
    for (int i = 0; i < 8; ++i)
    {
        //shared ptr piece = currentpiece . ir tada graziau atrodys
        for (int j = 0; j < 8; ++j)
        {
            if (board.square[i][j])
            {
                board.square[i][j]->sprite.setPosition(scale * board.square[i][j]->x, scale * board.square[i][j]->y);
                window.draw(board.square[i][j]->sprite);

                if (board.square[j][i]->highlight)
                {
                    // galim sukurt sf vector ir taip cuter pakeist pos
                    highlightMove.setPosition(board.square[j][i]->x * scale, board.square[j][i]->y * scale);
                    window.draw(highlightMove);
                    std::cout << "DREW";
                }
            }  
        }
    }
   // std::cout << "WOAH, its updated";
    //window.draw(highlightMove);
    window.display();
    }
    return 0;
}
