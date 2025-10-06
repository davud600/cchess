#pragma once

#include "fen.h"
#include "position.h"

namespace utils {

void printBitBoard(uint64_t b);

void printBoard(position::Board board);

void printPosition(position::Position position);

} // namespace utils
