#pragma once
/***********************************************************************
 * Header File:
 *    KING
 * Author:
*    <your name here>
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KING
  ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos.getCol(), pos.getRow(), isWhite) {}
   King(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~King() {                }
   PieceType getType()            const { return KING; }
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};