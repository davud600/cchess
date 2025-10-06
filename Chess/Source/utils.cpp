#include "position.h"
#include <array>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace utils {

const std::vector<char> BIT_BOARD_PIECES{'P', 'K', 'Q', 'B', 'N', 'R',
                                         'p', 'k', 'q', 'b', 'n', 'r'};

void printBitBoard(uint64_t b) {
  std::string binary = std::bitset<64>(b).to_string();
  unsigned short int r;
  unsigned short int f;

  for (r = 0; r < 8; r++) {
    for (f = 7; f < 65535; f--) {
      uint8_t idx = f + (r * 8);
      std::cout << binary[idx];
    }

    if (r == 7) {
      std::cout << "\n";
      continue;
    }

    std::cout << "\n";
  }
};

// from bit boards to user readable chess board.
// NOTE: to be refactored...
void printBoard(position::Board board) {
  std::array<std::string, 64> board_with_pieces;
  unsigned short int i;

  for (i = 0; i < 12; i++) {
    unsigned short int j;
    uint64_t b = board[i];
    std::string binary = std::bitset<64>(b).to_string();
    std::cout << binary << "\n";

    for (j = 0; j < 64; j++) {
      if (binary.at(j) == '0') {
        continue;
      }

      board_with_pieces[j] = BIT_BOARD_PIECES[i];
    }
  }

  unsigned short int r;
  unsigned short int f;
  std::cout << "|";
  for (r = 0; r < 8; r++) {
    for (f = 7; f < 65535; f--) {
      unsigned short int idx = f + (r * 8);
      if (board_with_pieces[idx] == "") {
        board_with_pieces[idx] = " ";
      }

      if (f == 0) {
        std::cout << board_with_pieces[idx];
        continue;
      }

      std::cout << board_with_pieces[idx] << "|";
    }

    if (r == 7) {
      std::cout << "|\n";
      continue;
    }

    std::cout << "|\n|";
  }
}

void printPosition(position::Position postition) {
  std::cout << "Active: "
            << (postition.active == position::Color::White ? "w" : "b") << "\n";
  std::cout << "Castling availability: " << postition.castling << "\n";
  std::cout << "En passant target square: " << postition.ep << "\n";
  std::cout << "Halfmove clock: " << postition.halfmoveClock << "\n";
  std::cout << "Fullmoves: " << postition.fullmoves << "\n";
  utils::printBoard(postition.board);
};

} // namespace utils
