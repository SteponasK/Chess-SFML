#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include "Piece_Textures.h"
#include "Piece.h"
#include "Pawn.h"
#include "Constants.h"

int scale{};

class Board {
/*public:
    Board()
    {
        for (int i = 0; i < numCols; ++i)
        {
            for (int j = 0; j < numRows; ++j)
            {
                if (i == 1)
                {
                    square[i][j] = std::make_shared<Pawn>(false, i, 6, Piece_Textures::w_pawn_text);
                }
                if (i == 6)
                {
                    square[i][j] = std::make_shared<Pawn>(true, i, 6, Piece_Textures::w_pawn_text);
                }
            }
        }
    }*/

public:
    const int numRows = 8;
    const int numCols = 8;
    std::array<std::array<std::shared_ptr<Piece>, 8>, 8 > square;
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    scale = window.getSize().x / 8;
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Resources/Board.png"))
    {
        std::cout << "error loading board texture";
        return 1;
    }
    sf::Sprite board_sprite(boardTexture);

    Piece_Textures pieceTextures;

 /*   std::vector<Pawn> w_pawn;
    std::vector<Pawn> b_pawn;
    for (int i = 0; i < 8; ++i)
    {
        w_pawn.emplace_back(true, i, 6, pieceTextures.w_pawn_text);
        b_pawn.emplace_back(false, i, 1, pieceTextures.b_pawn_text);
    }*/

    Board board;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j) 
        {
            if (i == 1)
            {
                board.square[i][j] = std::make_shared<Pawn>(false, j, i, pieceTextures.b_pawn_text);
            }
            else if (i == 6)
            {
                board.square[i][j] = std::make_shared<Pawn>(true, j, i, pieceTextures.w_pawn_text);
            }
            else
            {
                board.square[i][j] = nullptr;
            }
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Other events
        }

        // Game logic

        window.clear(sf::Color::Black);
        window.draw(board_sprite);
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board.square[i][j])
                {
                    window.draw(board.square[i][j]->sprite);
                }
            }
        }
        window.display();
    }

    return 0;
}
