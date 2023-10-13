#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include "Piece_Textures.h"
#include "Piece.h"
#include "Pawn.h"
#include "Constants.h"
#include "Square.h"
#include "Board.cpp" //board declared in this file:

int scale{};
Board board;
Piece_Textures pieceTextures;
bool Turn = 0; // 0 - White, 1 - Black

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
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    scale = window.getSize().x / 8;
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Resources/Board.png"))
    {
        std::cout << "error loading board texture";
        return 1;
    }
    sf::Sprite board_sprite(boardTexture);



    
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (i == 1)
            {
               /* board.square[j][i] = std::make_shared<Pawn>(false, j, i, pieceTextures.b_pawn_text);
                board.square[j][i]->empty_square = false;*/
                board.square[j][i] = std::make_shared<Square>(false, j, i, pieceTextures.b_knight_text); // pakeist kad nebutu false
                board.square[j][i]->empty_square = true;
            }
            else if (i == 6)
            {
                /*board.square[j][i] = std::make_shared<Pawn>(true, j, i, pieceTextures.w_pawn_text);
                board.square[j][i]->empty_square = false;*/
                board.square[j][i] = std::make_shared<Square>(false, j, i, pieceTextures.b_knight_text); // pakeist kad nebutu false
                board.square[j][i]->empty_square = true;
            }
            else
            {
                board.square[j][i] = std::make_shared<Square>(false, j, i, pieceTextures.b_knight_text); // pakeist kad nebutu false
                board.square[j][i]->empty_square = true;                   // pieceTextures.empty_square
                // kazka su bool isWhite Piece Class constructor padaryt
            }
            if (i == 7 && j == 4)
            {
                board.square[j][i] = std::make_shared<Pawn>(true, j, i, pieceTextures.w_king_text);
                board.square[j][i]->empty_square = false;
            }
            else if (i == 0 && j == 4)
            {
                board.square[j][i] = std::make_shared<Pawn>(false, j, i, pieceTextures.b_king_text);
                board.square[j][i]->empty_square = false;
            }
        }
    }
    std::shared_ptr<Piece> selected_square1 = nullptr; // square which piece to move
    std::shared_ptr<Piece> selected_square2 = nullptr; // square to which you want to move

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
                                        if (!board.square[j][i]->empty_square)
                                        {
                                            if (board.square[j][i]->isWhite == true)
                                            {
                                                selected_square1 = board.square[j][i];
                                            }
                                        }
                                    }
                                    else if (Turn == 1)
                                    {
                                        if (!board.square[j][i]->empty_square)
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
                                    selected_square2 = board.square[j][i];
                                    std::cout << "SELECTED2";
                                }
                                if (selected_square1 && selected_square2)
                                {
                                    if ((selected_square1->isWhite && selected_square2->isWhite)
                                        || (!selected_square1->isWhite && !selected_square2->isWhite &&
                                            !selected_square2->empty_square))
                                    {
                                        std::cout << "pasikeicia";
                                        selected_square1 = selected_square2;
                                        selected_square2 = nullptr;
                                    }
                                }
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
            std::cout << "selected_1: " << selected_square1->row + 1 << " " << selected_square1->col + 1 << std::endl;
        }
    if (selected_square1 && selected_square2)
    { 
   
        selected_square1->move(selected_square1, selected_square2, Turn);
        //std::cout << Turn;
      //  board.square[selected_square2->row][selected_square2->col] = selected_square1;
        selected_square1 = nullptr;
        selected_square2 = nullptr; // reikia padaryt kazka su nullptr kad galeciau pakeist values
      //  Turn = (Turn == 0) ? 1 : 0;
        std::cout << std::endl  << "uwu" << Turn;
    }


    window.clear(sf::Color::Black);
    window.draw(board_sprite);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            
            if (board.square[i][j])
            {
                board.square[i][j]->sprite.setPosition(scale * board.square[i][j]->row, scale * board.square[i][j]->col);
                window.draw(board.square[i][j]->sprite);
                //std::cout << board.square[i][j]->isWhite;
            }
            
        }
       // std::cout << std::endl;
    }
    
    window.display();
    }

    return 0;
}
