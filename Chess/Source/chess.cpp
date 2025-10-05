#include "fen.h"
#include "utils.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  // std::string fen =
  //     "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
  std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  std::cout << "FEN: " << fen << "\n\n";

  fen::GameState gs = fen::parse(fen);
  std::cout << "Active: " << (gs.active == fen::color::white ? "w" : "b")
            << "\n";
  std::cout << "Castling availability: " << gs.castling << "\n";
  std::cout << "En passant target square: " << gs.enps << "\n";
  std::cout << "Halfmove clock: " << gs.halfmove_clock << "\n";
  std::cout << "Fullmoves: " << gs.fullmoves << "\n";
  utils::printBoard(gs.board);

  return 0;
}
