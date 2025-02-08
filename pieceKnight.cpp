/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Jenna Ray
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>
using namespace std;
 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
	// needs "!"
	pgout->drawKnight(position, !fWhite);

}

set <Move> Knight::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
{
   set <Move> moves;
   for (int i = 0; i < numDelta; i++)
   {
      Position posMove(position, deltas[i]);
      // capture if there is a piece at the end of the slide
      if (posMove.isValid() && (board[posMove].isWhite() != fWhite || board[posMove] == SPACE))
      {
         Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
         moves.insert(move);
      }
   }
   return moves;
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{

   const Delta delta[] =
   {
            {-1,  2}, { 1,  2},
   {-2,  1},                    { 2,  1},
   {-2, -1},                    { 2, -1},
            {-1, -2}, { 1, -2}
   };

   moves = getMovesNoslide(board, delta, sizeof(delta) / sizeof(delta[0]));

 
}