#include "fen.h"
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace utils {

const std::vector<char> bit_board_pieces{'P', 'K', 'Q', 'B', 'N', 'R',
                                         'p', 'k', 'q', 'b', 'n', 'r'};

const std::map<char, std::string> pieces{
    {'k', "♔"}, {'q', "♕"}, {'r', "♖"}, {'b', "♗"}, {'n', "♘"}, {'p', "♙"},
    {'K', "♚"}, {'Q', "♛"}, {'R', "♜"}, {'B', "♝"}, {'N', "♞"}, {'P', "♟"}};

// from bit board to user readable chess board.
// NOTE: to be refactored...
void printBoard(fen::board_t board) {
  std::array<std::string, 64> board_with_pieces;
  unsigned short int i;

  for (i = 0; i < 12; i++) {
    unsigned short int j;
    fen::bit_board_t b = board[i];
    std::string binary = std::bitset<64>(b).to_string();
    std::cout << binary << "\n";

    for (j = 0; j < 64; j++) {
      if (binary.at(j) == '0') {
        continue;
      }

      // board_with_pieces[j] = pieces.at(bit_board_pieces[i]);
      board_with_pieces[j] = bit_board_pieces[i];
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
} // namespace utils
