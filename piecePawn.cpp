/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Jenna Ray
 * Summary:
 *    The knight class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>
#include "move.h"
using namespace std;
/***************************************************
* PIECE DRAW
* Draw all the pieces.
***************************************************/
void Pawn::display(ogstream* pgout) const
{
   // needs "!"
   pgout->drawPawn(position, !fWhite);

}

//set <Move> Pawn::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
//{
//   set <Move> moves;
//   for (int i = 0; i < numDelta; i++)
//   {
//      Position posMove(position, deltas[i]);
//      // capture if there is a piece diagonal to pawn
//      if (posMove.isValid() && (deltas[i] == {1, 1} || deltas[i] == { -1, 1 }) && (board[posMove].isWhite() != fWhite && board[posMove] != SPACE))
//      {
//         Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
//      }
//      // move forward if there is no piece in front of pawn
//      if (deltas[i] == {0, 1} && posMove.isValid() && board[posMove] == SPACE)
//      {
//
//         Move move(position, posMove, SPACE, SPACE, board[posMove].isWhite());
//         moves.insert(move);
//      }
//      //if pawn is on starting row, it can move two spaces forward
//      if (deltas[i][0] == 0 && posMove.isValid() && board[posMove] == SPACE && board[Position(position.getRow(), position.getCol() + 1)] == SPACE && nMoves = 0)
//      {
//         Move move(position, posMove, SPACE, SPACE, board[posMove].isWhite());
//         moves.insert(move);
//      }
//   }
//   return moves;
//}


/**********************************************
 * PAWN : GET POSITIONS
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
   int row = position.getRow();
   int col = position.getCol();

   Position posMove;
   int colChange;
   //if pawn is white
   if (fWhite)
      colChange = 1;
   else
      colChange = -1;
   posMove.set(col + colChange, row);
   // move forward if there is no piece in front of pawn
   if (posMove.isValid() && board[posMove] == SPACE)
   {
      
      Move move(position, posMove, SPACE, SPACE, board[posMove].isWhite());
      if (posMove.getRow() == 7 || posMove.getRow() == 0)
         move = Move(position, posMove, QUEEN, SPACE, board[posMove].isWhite());
      moves.insert(move);
   }
   //if pawn is on starting row, it can move two spaces forward
   posMove.set(col + (2 * colChange), row);
   if (posMove.isValid() && board[posMove] == SPACE && board[Position(col + 1, row)] == SPACE && nMoves == 0)
   {
      Move move(position, posMove, SPACE, SPACE, board[posMove].isWhite());
      moves.insert(move);
   }
   // capture if there is a piece diagonal to pawn
   posMove.set(col + colChange, row + 1);
   if (board[posMove].isWhite() != fWhite && board[posMove] != SPACE)
   {
      Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
      if (posMove.getRow() == 7 || posMove.getRow() == 0)
         move = Move(position, posMove, QUEEN, board[posMove].getType(), board[posMove].isWhite());
      moves.insert(move);
   }
   //add stuff for enpassant
   if (board[posMove] == SPACE && board[Position(col, row + 1)] == PAWN && board[Position(col, row + 1)].isWhite() != fWhite)
   {
      Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
      string text = move.getText();
      text += 'E';
      Move newMove(text);
      moves.insert(newMove);
   }
   posMove.set(col + colChange, row - 1);
   if (board[posMove].isWhite() != fWhite && board[posMove] != SPACE)
   {
      Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
      if (posMove.getRow() == 7 || posMove.getRow() == 0)
         move = Move(position, posMove, QUEEN, board[posMove].getType(), board[posMove].isWhite());
      moves.insert(move);
   }
   //add stuff for enpassant
   if (board[posMove] == SPACE && board[Position(col, row - 1)] == PAWN && board[Position(col, row + 1)].isWhite() != fWhite)
   {
      Move move(position, posMove, SPACE, board[posMove].getType(), board[posMove].isWhite());
      string text = move.getText();
      text += 'E';
      Move newMove(text);
      moves.insert(newMove);
   }
}