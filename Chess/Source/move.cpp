#include "move.h"
#include "position.h"
#include <cstdint>
#include <map>

namespace move {

uint64_t shiftNorth(uint64_t b) { return b << 8; };
uint64_t shiftSouth(uint64_t b) { return b >> 8; };
uint64_t shiftWest(uint64_t b) { return (b >> 1) & notHFile; };
uint64_t shiftEast(uint64_t b) { return (b << 1) & notAFile; };
uint64_t shiftNorthWest(uint64_t b) { return (b << 7) & notHFile; };
uint64_t shiftNorthEast(uint64_t b) { return (b << 9) & notAFile; };
uint64_t shiftSouthWest(uint64_t b) { return (b >> 7) & notHFile; };
uint64_t shiftSouthEast(uint64_t b) { return (b >> 9) & notAFile; };

// TODO: modularize for colors.
uint64_t generateAttacks(position::Position position, position::Piece piece) {
  uint64_t initPiece =
      position.board[position::PIECE_INDEXES.at(position::Piece::King)];
  uint64_t attacks = 0; // init to initPiece if we want to include the piece
                        // itself in the attack board.
  uint64_t sameColorPieces = position.colors[0];

  switch (piece) {
  case position::Piece::Pawn:
    break;
  case position::Piece::King:
    attacks = attacks | shiftNorth(initPiece);
    attacks = attacks | shiftSouth(initPiece);
    attacks = attacks | shiftWest(initPiece);
    attacks = attacks | shiftEast(initPiece);
    attacks = attacks | shiftNorthWest(initPiece);
    attacks = attacks | shiftNorthEast(initPiece);
    attacks = attacks | shiftSouthWest(initPiece);
    attacks = attacks | shiftSouthEast(initPiece);
    break;
  case position::Piece::Queen:
    break;
  case position::Piece::Bishop:
    break;
  case position::Piece::Knight:
    break;
  case position::Piece::Rook:
    break;
  default:
    break;
  }

  return (attacks | sameColorPieces) - sameColorPieces;
};

void applyMove(position::Position *position, Move move) {
  // p->board[m.from] = m.to;
};

} // namespace move
