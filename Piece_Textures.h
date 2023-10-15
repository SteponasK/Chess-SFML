#ifndef PIECE_TEXTURES_H
#define PIECE_TEXTURES_H

#include <memory>
#include <SFML/Graphics.hpp>

class Piece_Textures {
public:
    Piece_Textures();

    std::shared_ptr<sf::Texture> w_pawn_text;
    std::shared_ptr<sf::Texture> b_pawn_text;
    std::shared_ptr<sf::Texture> w_knight_text;
    std::shared_ptr<sf::Texture> b_knight_text;
    std::shared_ptr<sf::Texture> w_bishop_text;
    std::shared_ptr<sf::Texture> b_bishop_text;
    std::shared_ptr<sf::Texture> w_rook_text;
    std::shared_ptr<sf::Texture> b_rook_text;
    std::shared_ptr<sf::Texture> w_queen_text;
    std::shared_ptr<sf::Texture> b_queen_text;
    std::shared_ptr<sf::Texture> w_king_text;
    std::shared_ptr<sf::Texture> b_king_text;
    std::shared_ptr<sf::Texture> empty_square;
    // truksta w_king
}; extern Piece_Textures pieceTextures;

#endif // PIECE_TEXTURES_H
