#include "fen.h"
#include "move.h"
#include "position.h"
#include "utils.h"
#include <cstdint>
#include <iostream>
#include <string>

int main() {
  // std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0
  // 1";

  std::string fen = "8/8/4Q3/3NKP2/4B3/8/8/8 w - - 0 1";
  std::cout << "FEN: " << fen << "\n\n";
  position::Position position = fen::parse(fen);

  // move::applyMove(&position, move::Move{0, 0});
  // utils::printPosition(position);

  uint64_t kingAttacks = move::generateAttacks(position, position::Piece::King);
  utils::printBitBoard(position.colors[0]);
  utils::printBitBoard(kingAttacks);
}
