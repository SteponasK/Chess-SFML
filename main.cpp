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
#include "Board.cpp" //board declared in this file:ddddd
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


int main() //sjk dabar padaryti ->move() funkcija pawn klasei kad butu galima judeti-
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

    sf::Sprite kinglocation;
    sf::Texture kinglocationTex;
    kinglocationTex.loadFromFile("Resources/kinglocation.png");
    kinglocation.setTexture(kinglocationTex);
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
                                            if (board.square[j][i]->isWhite == true) // galima i same spalva
                                            {
                                                selected_square1 = board.square[j][i];
                                                board.calculate_legal_moves(selected_square1);
                                                board.check_move(board, selected_square1);
                                                board.highlightMoves_update();
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
                                        board.removeLegal_moves();
                                        break;
                                    }
                                    else if ((selected_square1->isWhite == board.square[j][i]->isWhite) && !board.square[j][i]->isEmpty)
                                    {
                                        selected_square1 = board.square[j][i];
                                        board.removeHighlighted_moves();
                                        board.removeLegal_moves();
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
                                        // changge turn/
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
                if(!board.square[i][j]->isEmpty)
                window.draw(board.square[i][j]->sprite);
                if (board.square[j][i]->isKing)
                {
                    kinglocation.setPosition(board.square[j][i]->x * scale, board.square[j][i]->y * scale);
                    kinglocation.setScale(sf::Vector2f(0.25, 0.25));
                    window.draw(kinglocation);
                    //dd
                }
                if (board.square[j][i]->highlight)
                {
                    // galim sukurt sf vector ir taip cuter pakeist pos
                    highlightMove.setPosition(board.square[j][i]->x * scale, board.square[j][i]->y * scale);
                    window.draw(highlightMove);
                }
            }  
        }
    }
    window.display();
    }
    return 0;
}
