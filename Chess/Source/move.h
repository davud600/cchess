#pragma once

#include "position.h"
#include <cstdint>

namespace move {

const uint64_t notAFile = 0xfefefefefefefefe; // ~0x0101010101010101
const uint64_t notHFile = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080

struct Move {
  uint8_t from; // 0...63
  uint8_t to;   // 0...63
};

uint64_t shiftNorth(uint64_t b);
uint64_t shiftSouth(uint64_t b);
uint64_t shiftWest(uint64_t b);
uint64_t shiftEast(uint64_t b);
uint64_t shiftNorthWest(uint64_t b);
uint64_t shiftNorthEast(uint64_t b);
uint64_t shiftSouthWest(uint64_t b);
uint64_t shiftSouthEast(uint64_t b);

uint64_t generateAttacks(position::Position position, position::Piece piece);

void applyMove(position::Position *position, Move move);

} // namespace move
