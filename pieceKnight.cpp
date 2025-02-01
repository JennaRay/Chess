/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
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


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   struct CR
   {
      int col;
      int row;
   };

   int row = position.getRow();
   int col = position.getCol();
   int r;
   int c;
   CR m[8] =
   {
            {-1,  2}, { 1,  2},
   {-2,  1},                    { 2,  1},
   {-2, -1},                    { 2, -1},
            {-1, -2}, { 1, -2}
   };

   for (int i = 0; i < 8; i++)
   {
      r = row + m[i].row;
      c = col + m[i].col;
      Position test(c, r);
      if (test.isValid())
      {
         if (!isWhite() && (board[test.getLocation()].isWhite() || board[test.getLocation()].getType() == SPACE))
         {
            Move move(Position(col, row), test, SPACE, board[test].getType(), false);
            string text = move.getText();
            moves.insert(Move(text));
         }
         if (isWhite() && (!board[test.getLocation()].isWhite() || board[test.getLocation()].getType() == SPACE))
         {
            Move move(position, test, SPACE, board[test].getType(), true);
            string text = move.getText();
            moves.insert(Move(text));
         }
      }
   }
 
}