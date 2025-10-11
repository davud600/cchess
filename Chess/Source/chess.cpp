#include "fen.h"
#include "move.h"
#include "position.h"
#include "utils.h"
#include <cstdint>
#include <iostream>
#include <string>

int main() {
  std::string fen = "8/8/4Q3/3NKP2/4B3/8/8/8 w - - 0 1";
  std::cout << "FEN: " << fen << "\n\n";
  position::Position position = fen::parse(fen);

  position::Piece piece = position::Piece::King;
  position::Color color = position::Color::White;

  uint64_t pieceB =
      position.board[position::PIECE_INDEXES.at(position::Piece::King)];
  uint64_t colorB = position.colors[color];
  uint64_t kingAttacks = move::generateAttacks(piece, pieceB, color, colorB);
  utils::printBitBoard(kingAttacks);
}
