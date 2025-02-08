#pragma once

/***********************************************************************
 * Header File:
 *    BISHOP
 * Author:
*    Jenna and William
 * Summary:
 *    The BISHOP class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * BISHOP
  * The bishop
  ***************************************************/
class Bishop : public Piece
{
public:
   Bishop(const Position& pos, bool isWhite) : Piece(pos.getCol(), pos.getRow(), isWhite) {}
   Bishop(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   ~Bishop() {                }
   PieceType getType()            const { return BISHOP; }
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
   set <Move> getMovesSlide(const Board& board, const Delta deltas[], int numDelta) const;
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
