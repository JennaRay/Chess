/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>
using namespace std;
/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Bishop::display(ogstream* pgout) const
{
   // needs "!"
   pgout->drawBishop(position, !fWhite);

}

//set <Move> Bishop::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
//{
//   set <Move> moves;
//   for (int i = 0; i < numDelta; i++)
//   {
//      Position posMove(position, deltas[i]);
//      // capture if there is a piece at the end of the slide
//      if (posMove.isValid() && (board[posMove].isWhite() != fWhite || board[posMove] == SPACE))
//      {
//         Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
//         moves.insert(move);
//      }
//   }
//   return moves;
//}

set <Move> Bishop::getMovesSlide(const Board& board, const Delta deltas[], int numDelta) const
{
   set <Move> moves;
   for (int i = 0; i < numDelta; i++)
   {
      Position posMove(position, deltas[i]);
      // capture if there is a piece at the end of the slide
      while (posMove.isValid() && board[posMove] == SPACE)
      {
         Move move(position, posMove);
         moves.insert(move);
         posMove += deltas[i];
      }
      if (posMove.isValid() && (board[posMove].isWhite() != fWhite))
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
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{

   const Delta delta[] =
   {
         { -1,  1 }, {1,  1},
         {-1, -1}, {1, -1}
   };

   moves = getMovesSlide(board, delta, sizeof(delta) / sizeof(delta[0]));



}