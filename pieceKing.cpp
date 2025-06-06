/***********************************************************************
 * Source File:
 *    KING
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>
using namespace std;
/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void King::display(ogstream* pgout) const
{
   // needs "!"
   pgout->drawKing(position, !fWhite);

}

set <Move> King::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
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

set <Move> King::getMovesCastle(set <Move>& moves, const Board& board) const
{
   if (fWhite)
   {
      Position posMove(0, 0);
      Position between1(1, 0);
      Position between2(2, 0);
      Position between3(3, 0);
      if (board[posMove].getType() == ROOK && board[posMove].isWhite() == fWhite && board[between1].getType() == SPACE && board[between2].getType() == SPACE && board[between3].getType() == SPACE)
      {
         if (nMoves == 0 && board[posMove].getNMoves() == 0)
         {
            Move move(position, Position(2, 0), SPACE, SPACE, fWhite, Move::CASTLE_QUEEN);
            moves.insert(move);
         }
      }

      posMove.set(7, 0);
      between1.set(6, 0);
      between2.set(5, 0);
      if (board[posMove].getType() == ROOK && board[posMove].isWhite() == fWhite && board[between1].getType() == SPACE && board[between2].getType() == SPACE)
      {
         if (board[posMove].getNMoves() == 0)
         {
            Move move(position, Position(6, 0), SPACE, SPACE, fWhite, Move::CASTLE_KING);
            moves.insert(move);
         }
      }
   }
   else
   {
      Position posMove(0, 7);
      Position between1(1, 7);
      Position between2(2, 7);
      Position between3(3, 7);
      if (board[posMove].getType() == ROOK && board[posMove].isWhite() == fWhite && board[between1].getType() == SPACE && board[between2].getType() == SPACE && board[between3].getType() == SPACE)
      {
         if (nMoves == 0 && board[posMove].getNMoves() == 0)
         {
            Move move(position, Position(2, 7), SPACE, SPACE, fWhite, Move::CASTLE_QUEEN);
            moves.insert(move);
         }
      }

      posMove.set(7, 7);
      between1.set(6, 7);
      between2.set(5, 7);
      if (board[posMove].getType() == ROOK && board[posMove].isWhite() == fWhite && board[between1].getType() == SPACE && board[between2].getType() == SPACE)
      {
         if (board[posMove].getNMoves() == 0)
         {
            Move move(position, Position(6, 7), SPACE, SPACE, fWhite, Move::CASTLE_KING);
            moves.insert(move);
         }
      }
   }
   return moves;
}


/**********************************************
 * KING : GET POSITIONS
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{

   const Delta delta[] =
   {
// add king moves here
      {0,0},
      { 0, 1 },
      { 1, 0 },
      { 0, -1 },
      { -1, 0 },
      { 1, 1 }, // this brings us to 22.2%
      { -1, -1 },
      { -1, 1 },
      { 1, -1 }
   };

   moves = getMovesNoslide(board, delta, sizeof(delta) / sizeof(delta[0]));
   if (nMoves == 0)
      getMovesCastle(moves, board);

   //add stuff for casteling somewhere??
}