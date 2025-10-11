#include "move.h"
#include "position.h"
#include <cstdint>
#include <vector>

namespace move {

uint64_t shiftNorth(uint64_t b) { return b << 8; };
uint64_t shiftSouth(uint64_t b) { return b >> 8; };
uint64_t shiftWest(uint64_t b) { return (b >> 1) & notHFile; };
uint64_t shiftEast(uint64_t b) { return (b << 1) & notAFile; };
uint64_t shiftNorthWest(uint64_t b) { return (b << 7) & notHFile; };
uint64_t shiftNorthEast(uint64_t b) { return (b << 9) & notAFile; };
uint64_t shiftSouthWest(uint64_t b) { return (b >> 7) & notHFile; };
uint64_t shiftSouthEast(uint64_t b) { return (b >> 9) & notAFile; };

uint64_t applyDirections(uint64_t piece, std::vector<Direction> directions) {
  uint64_t attacks = 0; // init to piece if we want to include the piece

  for (Direction dir : directions) {
    switch (dir) {
    case Direction::North:
      attacks = attacks | shiftNorth(piece);
      break;
    case Direction::South:
      attacks = attacks | shiftSouth(piece);
      break;
    case Direction::West:
      attacks = attacks | shiftWest(piece);
      break;
    case Direction::East:
      attacks = attacks | shiftEast(piece);
      break;
    case Direction::NorthWest:
      attacks = attacks | shiftNorthWest(piece);
      break;
    case Direction::NorthEast:
      attacks = attacks | shiftNorthEast(piece);
      break;
    case Direction::SouthWest:
      attacks = attacks | shiftSouthWest(piece);
      break;
    case Direction::SouthEast:
      attacks = attacks | shiftSouthEast(piece);
      break;
    }
  }

  return attacks;
};

uint64_t generateAttacks(position::Piece piece, uint64_t pieceB,
                         position::Color color, uint64_t colorB) {
  std::vector<Direction> shifts;

  switch (piece) {
  case position::Piece::Pawn: {
    if (color == position::Color::White) {
      shifts = std::vector<Direction>{
          Direction::North,
          Direction::NorthWest,
          Direction::NorthEast,
      };
    } else {
      shifts = std::vector<Direction>{
          Direction::South,
          Direction::SouthWest,
          Direction::SouthEast,
      };
    }

    break;
  }
  case position::Piece::King: {
    shifts = std::vector<Direction>{Direction::North,     Direction::South,
                                    Direction::West,      Direction::East,
                                    Direction::NorthWest, Direction::NorthEast,
                                    Direction::SouthWest, Direction::SouthEast};
    break;
  }
  case position::Piece::Queen: {
    shifts = std::vector<Direction>{Direction::North,     Direction::South,
                                    Direction::West,      Direction::East,
                                    Direction::NorthWest, Direction::NorthEast,
                                    Direction::SouthWest, Direction::SouthEast};
    break;
  }
  case position::Piece::Bishop: {
    shifts = std::vector<Direction>{Direction::NorthWest, Direction::NorthEast,
                                    Direction::SouthWest, Direction::SouthEast};
    break;
  }
  case position::Piece::Knight: {
    break;
  }
  case position::Piece::Rook: {
    shifts = std::vector<Direction>{Direction::North, Direction::East,
                                    Direction::South, Direction::West};
    break;
  }
  default: {
    shifts = std::vector<Direction>{};
    break;
  }
  }

  uint64_t attacks = applyDirections(pieceB, shifts);
  return (attacks | colorB) - colorB;
};

} // namespace move
