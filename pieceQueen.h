#pragma once
/***********************************************************************
 * Header File:
 *    QUEEN
 * Author:
*    <your name here>
 * Summary:
 *    The QUEEN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * QUEEN
  * The knight, aka the "Horse"
  ***************************************************/
class Queen : public Piece
{
public:
   Queen(const Position& pos, bool isWhite) : Piece(pos.getCol(), pos.getRow(), isWhite) {}
   Queen(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Queen() {                }
   PieceType getType()            const { return QUEEN; }
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};