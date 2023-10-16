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

int scale{};
Board board;
Piece_Textures pieceTextures;
bool Turn = 0; // 0 - White, 1 - Black
bool wKingMoved = false;
bool bKingMoved = false;


int main() // dabar padaryti ->move() funkcija pawn klasei kad butu galima judeti
{


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
    
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            
            if (i == 7 && j == 4)
            {
                board.square[j][i] = std::make_shared<Empty_Square>(j, i, true, false, pieceTextures.w_king_text);
                //board.square[j][i]->empty_square = false;
            }
            else if (i == 0 && j == 4)
            {
                board.square[j][i] = std::make_shared<Empty_Square>(j, i, false, false, pieceTextures.b_king_text);
            }
            else
            {
                board.square[j][i] = std::make_shared<Empty_Square>(j, i, false, true, pieceTextures.b_knight_text); // pakeist kad nebutu false
            }
        }
    }
    std::shared_ptr<Piece> selected_square1 = nullptr; // square which piece to move
    std::shared_ptr<Piece> selected_square2 = nullptr; // square to which you want to move
    std::vector<std::shared_ptr<Piece>> legalMoves;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
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
                                            if (board.square[j][i]->isWhite == true)
                                            {
                                                selected_square1 = board.square[j][i];
                                            }
                                        }
                                    }
                                    else if (Turn == 1)
                                    {
                                        if (!board.square[j][i]->isEmpty)
                                        {
                                            if (board.square[j][i]->isWhite == false)
                                            {
                                                selected_square1 = board.square[j][i];
                                            }
                                        }
                                    }
                                }
                                else // jeigu turim pasirinke figura, galim pasirinkt destination langeli
                                {
                                    if (selected_square1 == board.square[j][i] || selected_square1->isWhite)
                                    {

                                    }
                                        bool Exists = false;
                                    for (auto legalMove : legalMoves)
                                    {
                                        if (board.square[j][i] == legalMove)
                                        {
                                            Exists = true;
                                            if ((board.square[j][i]->isWhite != selected_square1->isWhite)
                                                && !board.square[j][i]->isEmpty) // different colour
                                                selected_square1->move(board.square[j][i], true, Turn); // capture
                                            else selected_square1->move(board.square[j][i], false, Turn); // not capture  
                                            break;
                                            //logic for castling needed later
                                        }
                                        
                                    }
                                    if (!Exists)
                                    {
                                        std::cout << "Move doesn't exist\n";
                                        break;
                                    }
                                    /*
                                    * IF board[j][i] yra in legal_moves vector:
                                    *   IF(board[j][i]->isWhite != selected1->isWhite)
                                    *       selected1->move(board[j][i], capture=true, Turn)
                                    *   else selected1->move(board[j][i], capture=false, Turn)
                                    *
                                    */


                                    //if(board.square[j][i]->isWhite != selected_square1->isWhite)
                                       // selected_square2 = board.square[j][i];
                                        // reiks castling logic dar
                                    
                                    std::cout << "SELECTED2";
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
                                    }
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
           // std::cout << "selected_1: " << selected_square1->x + 1 << " " << selected_square1->y + 1 << std::endl;
            if (selected_square1->isWhite)
                legalMoves = selected_square1->legal_movesWhite();
            else  legalMoves = selected_square1->legal_movesBlack();
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
        for (int j = 0; j < 8; ++j)
        {
            if (board.square[i][j])
            {
                board.square[i][j]->sprite.setPosition(scale * board.square[i][j]->x, scale * board.square[i][j]->y);
                window.draw(board.square[i][j]->sprite);
                // if square[i][j]->highlighted:
                // highlightMove.setposition(j*scale + scale/4, i * scale + scale/4);
            }  
        }
    }
   // highlightMove.setPosition((5 * scale) + scale/4, 5 * scale + scale/4); // loop over every
   // window.draw(highlightMove);
    window.display();
    }
    return 0;
}
