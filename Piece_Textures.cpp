#include "Piece_Textures.h"

Piece_Textures::Piece_Textures()
{
    std::string path = "Resources/";
    std::string end = ".png";

    w_pawn_text = std::make_shared<sf::Texture>();
    b_pawn_text = std::make_shared<sf::Texture>();
    w_knight_text = std::make_shared<sf::Texture>();
    b_knight_text = std::make_shared<sf::Texture>();
    w_bishop_text = std::make_shared<sf::Texture>();
    b_bishop_text = std::make_shared<sf::Texture>();
    w_rook_text = std::make_shared<sf::Texture>();
    b_rook_text = std::make_shared<sf::Texture>();
    w_queen_text = std::make_shared<sf::Texture>();
    b_queen_text = std::make_shared<sf::Texture>();

    // Texture loading
    w_pawn_text->loadFromFile(path + "w_pawn" + end);
    b_pawn_text->loadFromFile(path + "b_pawn" + end);
    w_knight_text->loadFromFile(path + "w_knight" + end);
    b_knight_text->loadFromFile(path + "b_knight" + end);
    w_bishop_text->loadFromFile(path + "w_bishop" + end);
    b_bishop_text->loadFromFile(path + "b_bishop" + end);
    w_rook_text->loadFromFile(path + "w_rook" + end);
    b_rook_text->loadFromFile(path + "b_rook" + end);
    w_queen_text->loadFromFile(path + "w_queen" + end);
    b_queen_text->loadFromFile(path + "b_queen" + end);
}
