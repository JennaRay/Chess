#pragma once
/***********************************************************************
 * Header File:
 *    ROOK
 * Author:
*    <your name here>
 * Summary:
 *    The ROOK class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * ROOK
  * The knight, aka the "Horse"
  ***************************************************/
class Rook : public Piece
{
public:
   Rook(const Position& pos, bool isWhite) : Piece(pos.getCol(), pos.getRow(), isWhite) {}
   Rook(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Rook() {                }
   PieceType getType()            const { return ROOK; }
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
   set <Move> getMovesSlide(const Board& board, const Delta deltas[], int numDelta) const;
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};