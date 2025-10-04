#pragma once

#include <array>
#include <string>
#include <utility>

namespace fen {

enum piece {
  pawn = 'p',
  king = 'k',
  queen = 'q',
  bishop = 'b',
  knight = 'n',
  rook = 'r',
};

enum color {
  white = 0,
  black = 6,
};

using colored_piece_t = std::pair<piece, color>;

using bit_board_t = unsigned long long int; // 64 bit board.

// arr of 12 64 bit boards (for each piece type and color).
using board_t = std::array<bit_board_t, 12>;

struct GameState {
  board_t board;
  color active;
  std::string castling; // castling availability
  std::string enps;     // en passant target square
  unsigned int
      halfmove_clock; // num of halfmoves since last capture or pawn advance
  unsigned int fullmoves;
};

colored_piece_t parse_char(char ch);

board_t parse_board(std::string fen_board);

color parse_active(std::string fen_active);

std::string parse_castling(std::string fen_castling);

std::string parse_enps(std::string fen_enps);

unsigned int parse_halfmove_clock(std::string fen_halfmove_clock);

unsigned int parse_fullmoves(std::string fen_fullmoves);

GameState parse(std::string fen);

} // namespace fen
