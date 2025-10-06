#include "fen.h"
#include "position.h"
#include <cctype>
#include <cmath>
#include <cstdint>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace fen {

position::ColoredPiece parseChar(char ch) {
  position::ColoredPiece parsed;
  parsed.second =
      tolower(ch) == ch ? position::Color::Black : position::Color::White;

  switch (std::tolower(ch)) {
  case position::Piece::Bishop:
    parsed.first = position::Piece::Bishop;
    break;
  case position::Piece::King:
    parsed.first = position::Piece::King;
    break;
  case position::Piece::Knight:
    parsed.first = position::Piece::Knight;
    break;
  case position::Piece::Queen:
    parsed.first = position::Piece::Queen;
    break;
  case position::Piece::Rook:
    parsed.first = position::Piece::Rook;
    break;
  default:
    parsed.first = position::Piece::Pawn;
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
position::Board parseBoard(std::string fen_board) {
  unsigned short int rank = 7;
  unsigned short int file = 0;
  position::Board board = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  for (char c : fen_board) {
    if (c == '/') {
      file = 0;
      rank -= 1;
      continue;
    } else if (std::isdigit(c)) {
      file += c - '0';
      continue;
    };

    position::ColoredPiece piece = parseChar(c);
    uint8_t board_idx = position::PIECE_INDEXES.at(piece.first) + piece.second;

    board[board_idx] += std::pow(2, file + (rank * 8));
    file += 1;
  }

  return board;
}

position::Color parseActive(std::string fenActive) {
  return fenActive == "w" ? position::Color::White : position::Color::Black;
};

std::string parseCastling(std::string fen_castling) { return fen_castling; };

// en passant
std::string parseEp(std::string fen_enps) { return fen_enps; };

uint16_t parseHalfmoveClock(std::string fen_halfmove_clock) {
  char c = fen_halfmove_clock[0];

  if (std::isdigit(c)) {
    return c - '0';
  };

  return 0;
};

uint16_t parseFullmoves(std::string fen_fullmoves) {
  char c = fen_fullmoves[0];

  if (std::isdigit(c)) {
    return c - '0';
  };

  return 0;
};

position::Position parse(std::string fen) {
  std::vector<std::string> parts;
  std::istringstream iss(fen);
  std::string part;
  position::Position p;

  while (iss >> part) {
    parts.push_back(part);
  }

  p.board = parseBoard(parts[0]);
  p.colors = position::getColorBoards(p.board);
  p.active = parseActive(parts[1]);
  p.castling = parseCastling(parts[2]);
  p.ep = parseEp(parts[3]);
  p.halfmoveClock = parseHalfmoveClock(parts[4]);
  p.fullmoves = parseFullmoves(parts[5]);

  return p;
};

// TODO: position to fen.
std::string getFen(position::Position position) { return ""; };

} // namespace fen
