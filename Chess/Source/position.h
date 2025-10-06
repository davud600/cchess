#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <utility>

namespace position {

const std::map<char, unsigned short int> PIECE_INDEXES{
    {'p', 0}, {'k', 1}, {'q', 2}, {'b', 3}, {'n', 4}, {'r', 5}};

enum Piece {
  Pawn = 'p',
  King = 'k',
  Queen = 'q',
  Bishop = 'b',
  Knight = 'n',
  Rook = 'r',
};

enum Color {
  White = 0,
  Black = 6,
};

using ColoredPiece = std::pair<Piece, Color>;

// arr of 12 64 bit boards (for each piece type and color).
using Board = std::array<uint64_t, 12>;

// arr of 2 64 bit boards (for each color).
using Colors = std::array<uint64_t, 2>;

struct Position {
  Board board;
  Colors colors;
  Color active;
  std::string castling;   // castling availability
  std::string ep;         // en passant target square
  uint16_t halfmoveClock; // num of halfmoves since last capture or pawn advance
  uint16_t fullmoves;
};

Colors getColorBoards(Board board);

} // namespace position
