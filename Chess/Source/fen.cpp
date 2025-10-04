#include "fen.h"
#include <cctype>
#include <cmath>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace fen {

const std::map<char, unsigned short int> board_pieces{
    {'p', 0}, {'k', 1}, {'q', 2}, {'b', 3}, {'n', 4}, {'r', 5}};

colored_piece_t parse_char(char ch) {
  colored_piece_t parsed;
  parsed.second = tolower(ch) == ch ? color::black : color::white;

  switch (std::tolower(ch)) {
  case piece::bishop:
    parsed.first = piece::bishop;
    break;
  case piece::king:
    parsed.first = piece::king;
    break;
  case piece::knight:
    parsed.first = piece::knight;
    break;
  case piece::queen:
    parsed.first = piece::queen;
    break;
  case piece::rook:
    parsed.first = piece::rook;
    break;
  default:
    parsed.first = piece::pawn;
    break;
  }

  return parsed;
};

/**
 *
 * bit boards are created right left bottom down.
 * bit board = 2^(file + (rank * 8))
 *
 */
board_t parse_board(std::string fen_board) {
  unsigned short int rank = 7;
  unsigned short int file = 0;
  board_t board = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (char c : fen_board) {
    if (c == '/') {
      file = 0;
      rank -= 1;
      continue;
    } else if (std::isdigit(c)) {
      file += c - '0';
      continue;
    };

    colored_piece_t piece = parse_char(c);
    unsigned short int board_idx = board_pieces.at(piece.first) + piece.second;

    board[board_idx] += std::pow(2, file + (rank * 8));
    file += 1;
  }

  return board;
}

color parse_active(std::string fen_active) {
  return fen_active == "w" ? color::white : color::black;
};

std::string parse_castling(std::string fen_castling) { return fen_castling; };

std::string parse_enps(std::string fen_enps) { return fen_enps; };

unsigned int parse_halfmove_clock(std::string fen_halfmove_clock) {
  char c = fen_halfmove_clock[0];

  if (std::isdigit(c)) {
    return c - '0';
  };

  return 0;
};

unsigned int parse_fullmoves(std::string fen_fullmoves) {
  char c = fen_fullmoves[0];

  if (std::isdigit(c)) {
    return int(c);
  };

  return 0;
};

GameState parse(std::string fen) {
  std::vector<std::string> parts;
  std::istringstream iss(fen);
  std::string part;
  GameState gs;

  while (iss >> part) {
    parts.push_back(part);
  }

  gs.board = parse_board(parts[0]);
  gs.active = parse_active(parts[1]);
  gs.castling = parse_castling(parts[2]);
  gs.enps = parse_enps(parts[3]);
  gs.halfmove_clock = parse_halfmove_clock(parts[4]);
  gs.fullmoves = parse_fullmoves(parts[5]);

  return gs;
};

} // namespace fen
