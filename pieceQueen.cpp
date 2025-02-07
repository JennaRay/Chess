/***********************************************************************
 * Source File:
 *    QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>
using namespace std;
/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Queen::display(ogstream* pgout) const
{
   // needs "!"
   pgout->drawQueen(position, !fWhite);

}

set <Move> Queen::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
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
 * QUEEN : GET POSITIONS
 *********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{

   const Delta delta[] =
   {
//add queen moves here
      {0, 0}
   };

   moves = getMovesNoslide(board, delta, sizeof(delta) / sizeof(delta[0]));

   //add stuff for casteling somewhere??
}