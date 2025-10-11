#pragma once

#include "position.h"
#include <cstdint>
#include <vector>

namespace move {

enum Direction {
  North,
  South,
  West,
  East,
  NorthWest,
  NorthEast,
  SouthWest,
  SouthEast,
};

const uint64_t notAFile = 0xfefefefefefefefe; // ~0x0101010101010101
const uint64_t notHFile = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080

uint64_t shiftNorth(uint64_t b);
uint64_t shiftSouth(uint64_t b);
uint64_t shiftWest(uint64_t b);
uint64_t shiftEast(uint64_t b);
uint64_t shiftNorthWest(uint64_t b);
uint64_t shiftNorthEast(uint64_t b);
uint64_t shiftSouthWest(uint64_t b);
uint64_t shiftSouthEast(uint64_t b);

uint64_t applyDirections(uint64_t piece, std::vector<Direction> directions);

uint64_t generateAttacks(position::Piece piece, uint64_t pieceB,
                         position::Color color, uint64_t colorB);

} // namespace move
