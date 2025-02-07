#pragma once
/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
*    <your name here>
 * Summary:
 *    The PAWN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * PAWN
  * The knight, aka the "Horse"
  ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos.getCol(), pos.getRow(), isWhite) {}
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Pawn() {                }
   PieceType getType()            const { return PAWN; }
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};