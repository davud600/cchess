#pragma once

#include "position.h"
#include <array>
#include <cstdint>
#include <string>
#include <utility>

namespace fen {

position::ColoredPiece parseChar(char ch);

position::Board parseBoard(std::string fenBoard);

position::Color parseActive(std::string fenActive);

std::string parseCastling(std::string fenCastling);

std::string parseEp(std::string fenEp);

uint16_t parseHalfmoveclock(std::string fenHalfmoveClock);

uint16_t parseFullmoves(std::string fenFullmoves);

position::Position parse(std::string fen);

std::string getFen(position::Position position);

} // namespace fen
