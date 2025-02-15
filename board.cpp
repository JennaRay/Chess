/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "pieceBishop.h"
#include "pieceRook.h"
#include "pieceKing.h"
#include "pieceQueen.h"
#include "piecePawn.h"
#include <cassert>
#include <iostream> // for debugging
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     K B     B K     8 9
 *   7                     7 6
 *   6                     6 5
 *   5                     5 4
 *   4                     4 3
 *   3                     3 2
 *   2                     2 1
 *   1     k b     b k     1 0
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 *       0 1 2 3 4 5 6 7
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
}

// we really REALLY need to delete this.
Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   Piece* pSpace = new Space(pos.getCol(), pos.getRow());

   // Get board x, y
   //return *board[pos.getCol()][pos.getRow()];
   if (board[pos.getCol()][pos.getRow()])
      return *(board[pos.getCol()][pos.getRow()]);
   else
      return *pSpace;
}
Piece& Board::operator [] (const Position& pos)
{
   return *board[pos.getCol()][pos.getRow()];
}

/***********************************************
* BOARD : GETPOSSIBLEMOVES
*         Get all the possible moves for a given piece
*
***********************************************/
set <Move> Board::getPossibleMoves(const Position& pos) const
{
   if (pos.isValid())
   {
      Piece* pPiece = board[pos.getCol()][pos.getRow()];
      //assert(pPiece != nullptr);
      set <Move> moves;
      if (pPiece != nullptr)
         pPiece->getMoves(moves, *this);
      return moves;
   }
   else
   {
      return set<Move>();
   }
}
 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect, set <Move>& moves) const
{
    // Draw board
    pgout->drawBoard();

    //draw hover
    if (posHover.isValid()) {
       pgout->drawHover(posHover);
    }
    // Draw selected piece
    if (posSelect.isValid()) {
       pgout->drawSelected(posSelect);
    }
    // Draw possible moves
    
   for (set<Move>::iterator it = moves.begin(); it != moves.end(); it++) {
      Position posDest(it->getDest());
      // Draw all possible moves
      pgout->drawPossible(posDest);
    }

    // Draw all pieces
    for (int row = 0; row < 8; row++)
        for (int col = 0; col < 8; col++)
            if (board[col][row] != nullptr) {
                // Draw all pieces whereever they are
                board[col][row]->display(pgout);
            }
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
    reset(true);
    if (!noreset) {
        // Knights
        board[1][0] = new Knight(1, 0, true);
        board[6][0] = new Knight(6, 0, true);
        board[1][7] = new Knight(1, 7, false);
        board[6][7] = new Knight(6, 7, false);
        // Bishops
        board[2][0] = new Bishop(2, 0, true);
        board[5][0] = new Bishop(5, 0, true);
        board[2][7] = new Bishop(2, 7, false);
        board[5][7] = new Bishop(5, 7, false);
        // Rooks
        board[0][0] = new Rook(0, 0, true);
        board[7][0] = new Rook(7, 0, true);
        board[0][7] = new Rook(0, 7, false);
        board[7][7] = new Rook(7, 7, false);
        // Kings
        board[4][0] = new King(4, 0, true);
        board[4][7] = new King(4, 7, false);
        // Queens
        board[3][0] = new Queen(3, 0, true);
        board[3][7] = new Queen(3, 7, false);
        // Pawns
        board[0][1] = new Pawn(0, 1, true); // whites
        board[1][1] = new Pawn(1, 1, true);
        board[2][1] = new Pawn(2, 1, true);
        board[3][1] = new Pawn(3, 1, true);
        board[4][1] = new Pawn(4, 1, true);
        board[5][1] = new Pawn(5, 1, true);
        board[6][1] = new Pawn(6, 1, true);
        board[7][1] = new Pawn(7, 1, true);
        board[0][6] = new Pawn(0, 6, false); // blacks
        board[1][6] = new Pawn(1, 6, false);
        board[2][6] = new Pawn(2, 6, false);
        board[3][6] = new Pawn(3, 6, false);
        board[4][6] = new Pawn(4, 6, false);
        board[5][6] = new Pawn(5, 6, false);
        board[6][6] = new Pawn(6, 6, false);
        board[7][6] = new Pawn(7, 6, false);
    }
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{

}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   // Get the source and destination
   Position posSource(move.getSource());
   Position posDest(move.getDest());
   int sCol = posSource.getCol();
   int sRow = posSource.getRow();
   int dCol = posDest.getCol();
   int dRow = posDest.getRow();
   // Get the piece
   Piece* pPiece = board[sCol][sRow];
   assert(pPiece != nullptr);

   // Move the piece
   board[dCol][dRow] = pPiece;
   pPiece->move(dCol, dRow);
   board[sCol][sRow] = new Space(sCol, sRow);
   if (move.getType() == Move::ENPASSANT)
   {
      board[sCol][dRow] = new Space(dCol, sRow);
   }
   if (move.getType() == Move::CASTLE_KING)
   {
      board[posDest.getCol()][5] = new Rook(5, posDest.getRow(), pPiece->isWhite());
      board[posDest.getCol()][7] = new Space(posDest.getCol(), posDest.getRow() - 1); // remove the rook from the board
      
   }
   if (move.getType() == Move::CASTLE_QUEEN)
   {
      board[posDest.getCol()][3] = new Rook(3, posDest.getRow(), pPiece->isWhite());
      board[posDest.getCol()][0] = new Space(posDest.getCol(), posDest.getRow() + 1); // remove the rook from the board
   }
   if (move.getPromote() == QUEEN) // need to add other promotion options
   {
      // promote the pawn
      board[posDest.getCol()][posDest.getRow()] = new Queen(posDest.getCol(), posDest.getRow(), pPiece->isWhite());

   }

   // Increment the move number
   numMoves++;
}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}