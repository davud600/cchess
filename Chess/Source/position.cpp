#include "position.h"

namespace position {

// returns 2 bit boards, unions of pieces for each col.
Colors getColorBoards(Board board) {
  Colors colors = {0, 0};

  for (int i = 0; i < 6; i++) {
    colors[0] = colors[0] | board[i];
  }

  for (int i = 6; i < 12; i++) {
    colors[1] = colors[1] | board[i];
  }

  return colors;
};

} // namespace position
