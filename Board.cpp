#include <array>
#include <memory>
#include "Piece.h"
class Board {

public:
    const int numRows = 8;
    const int numCols = 8;
    std::array<std::array<std::shared_ptr<Piece>, 8>, 8 > square;
}; extern Board board;