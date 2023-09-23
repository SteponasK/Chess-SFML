#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

class Piece_Textures {
public:
    Piece_Textures()
    {
        std::string path= "Resources/";
        std::string end = ".png";
        w_pawn_text->loadFromFile(path + "w_pawn" + end);
        b_pawn_text->loadFromFile(path + "b_pawn"+ end);
    }
    std::shared_ptr<sf::Texture> w_pawn_text = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> b_pawn_text = std::make_shared<sf::Texture>();
};
class Piece {
public:
    Piece(bool isWhite, int row, int col)
        : isWhite(isWhite), row(row), col(col) {
        // Initialize texture and sprite here
    }

    int row{};
    int col{};
   // sf::Texture* texture = new sf::Texture;
   // std::shared_ptr<sf::Texture> w_texture;
   // std::shared_ptr<sf::Texture> b_texture;
    sf::Sprite sprite;
    bool isWhite{};
};

class Pawn : public Piece {
public:
    // Call the base class constructor in the member initializer list
    Pawn(bool isWhite, int row, int col, std::shared_ptr<sf::Texture> texture)
        : Piece(isWhite, row, col) {
        //sf::Texture texture;
        sprite.setTexture(*texture);
        //sprite.setRotation(180);
        sprite.setPosition(sf::Vector2f(row*100, col*100));
    }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Resources/Board.png"))
    {
        std::cout << "error loading board texture";
        return 1;
    }
    sf::Sprite board(boardTexture);


    Piece_Textures pieceTextures;

    std::vector<Pawn> w_pawn;
    std::vector<Pawn> b_pawn;
    for (int i = 0; i < 8; ++i)
    {
        w_pawn.emplace_back(true, i, 6, pieceTextures.w_pawn_text);
        b_pawn.emplace_back(false, i, 1, pieceTextures.b_pawn_text);
    }
    


    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);
        window.draw(board);
        //window.draw(pawn_sprite);
        //window.draw(pawn.sprite);
        for (int i = 0; i < 8; i++)
        {
            window.draw((w_pawn[i].sprite));
            window.draw((b_pawn[i].sprite));
        }
        window.display();
    }

    return 0;
}