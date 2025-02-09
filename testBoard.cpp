/***********************************************************************
 * Source File:
 *    TEST BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for board
 ************************************************************************/


#include "testBoard.h"
#include "position.h"
#include "piece.h"
#include "board.h"
#include <cassert>




/********************************************************
 *    e5c6
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6       .             6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_knightMove()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(2, 5);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);   
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}

 /********************************************************
 *    e5c6r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7       R             7       7                     7
 * 6                     6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_knightAttack()
{  // SETUP
   Move move;
   move.source.set(4, 4);
   move.dest.set(2, 5);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, ROOK);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(move);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}
/********************************************************
  *   a2a3
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  * |                     |       |                     |
  * 8                     8       8                     8
  * 7                     7       7                     7
  * 6                     6       6                     6
  * 5                     5       5                     5
  * 4                     4  -->  4                     4
  * 3   .                 3       3   p                 3
  * 2  (p)                2       2   .                 2
  * 1                     1       1                     1
  * |                     |       |                     |
  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_pawnSimple()
{
   // SETUP
   Move move;
   move.source.set(1, 0);
   move.dest.set(2, 0);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[1][0] = new PieceSpy(1, 0, true  /*isWhite*/, PAWN);
   board.board[2][0] = new PieceSpy(2, 0, false /*isWhite*/, SPACE);
   board.board[1][0]->nMoves = 17;
   PieceSpy::reset();
   // EXERCISE
   board.move(move);
   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(PAWN == (board.board[2][0])->getType());
   assertUnit(SPACE == (board.board[1][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   // TEARDOWN
   delete board.board[2][0];
   delete board.board[1][0];
   board.board[2][0] = board.board[1][0] = nullptr;
}


/********************************************************
 *     a6b7r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7     R               7       7    (p)              7
 * 6  (p)                6       6   .                 6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnCapture()
{
   // SETUP
   Move move;
   move.source.set(5, 0);
   move.dest.set(6, 1);
   move.capture = ROOK;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[5][0] = new PieceSpy(5, 0, true  /*isWhite*/, PAWN);
   board.board[6][1] = new PieceSpy(6, 1, false /*isWhite*/, ROOK);
   board.board[5][0]->nMoves = 17;
   PieceSpy::reset();
   // EXERCISE
   board.move(move);
   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[5][0])->getType());
   assertUnit(PAWN == (board.board[6][1])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   // TEARDOWN
   delete board.board[6][1];
   delete board.board[5][0];
   board.board[6][1] = board.board[5][0] = nullptr;
}


/********************************************************
 *    e2e4
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4           .         4  -->  4          (p)        4
 * 3                     3       3                     3
 * 2          (p)        2       2           .         2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnDouble()
{
   // SETUP
   Move move;
   move.source.set(1, 4);
   move.dest.set(3, 4);
   move.capture = SPACE;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[1][4] = new PieceSpy(1, 4, true  /*isWhite*/, PAWN);
   board.board[3][4] = new PieceSpy(3, 4, false /*isWhite*/, SPACE);
   board.board[1][4]->nMoves = 17;  
   PieceSpy::reset();
   // EXERCISE
   board.move(move);
   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(PAWN == (board.board[3][4])->getType());
   assertUnit(SPACE == (board.board[1][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   // TEARDOWN
   delete board.board[3][4];
   delete board.board[1][4];
   board.board[3][4] = board.board[1][4] = nullptr;
}


/********************************************************
*     a5b6E
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6     .               6       6     p               6
 * 5  (p)P               5       5   . .               5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnEnpassant()
{
   // SETUP
   Move move;
   move.source.set(4, 0);
   move.dest.set(5, 1);
   move.capture = PAWN;
   move.promote = SPACE;
   move.isWhite = true;
   move.moveType = Move::ENPASSANT;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, PAWN);
   board.board[5][1] = new PieceSpy(5, 1, false /*isWhite*/, PAWN);
   board.board[4][0]->nMoves = 17;
   PieceSpy::reset();
   // EXERCISE
   board.move(move);
   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(PAWN == (board.board[5][1])->getType());
   //assertUnit(SPACE == (board.board[4][1])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   // TEARDOWN
   delete board.board[5][1];
   delete board.board[4][0];
   board.board[5][1] = board.board[4][0] = nullptr;

}


/********************************************************
 *    a7a8Q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8   .                 8       8  (q)                8
 * 7  (p)                7       7   .                 7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnPromotion()
{
   // SETUP
   Move move;
   move.source.set(6, 0);
   move.dest.set(7, 0);
   move.capture = SPACE;
   move.promote = QUEEN;
   move.isWhite = true;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[6][0] = new PieceSpy(6, 0, true  /*isWhite*/, PAWN);
   board.board[7][0] = new PieceSpy(7, 0, false /*isWhite*/, SPACE);
   board.board[6][0]->nMoves = 17;
   PieceSpy::reset();
   // EXERCISE
   board.move(move);
   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(QUEEN == (board.board[7][0])->getType());
   assertUnit(SPACE == (board.board[6][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   // TEARDOWN
   delete board.board[7][0];
   delete board.board[6][0];
   board.board[7][0] = board.board[6][0] = nullptr;
}


/********************************************************
 *    e5a5
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   .      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookSlide()
{
   //setup
   Move move("e5a5");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, ROOK);
   board.board[4][0] = new PieceSpy(4, 0, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(ROOK == (board.board[4][0])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[4][0];
   delete board.board[4][4];
   board.board[4][0] = board.board[4][4] = nullptr;
}


/********************************************************
 *    e5a5b
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   B      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookAttack()
{
   //setup
   Move move("e5a5b");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, ROOK);
   board.board[4][0] = new PieceSpy(4, 0, false /*isWhite*/, BISHOP);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(ROOK == (board.board[4][0])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[4][0];
   delete board.board[4][4];
   board.board[4][0] = board.board[4][4] = nullptr;

}


/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               .     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopSlide()
{
   //setup
   Move move("e5g3");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, BISHOP);
   board.board[2][6] = new PieceSpy(2, 6, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(BISHOP == (board.board[2][6])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[2][6];
   delete board.board[4][4];
   board.board[2][6] = board.board[4][4] = nullptr;
}


/********************************************************
 *    e5g3q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               Q     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopAttack()
{
   //setup
   Move move("e5g3q");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, BISHOP);
   board.board[2][6] = new PieceSpy(2, 6, false /*isWhite*/, QUEEN);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(BISHOP == (board.board[2][6])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[2][6];
   delete board.board[4][4];
   board.board[2][6] = board.board[4][4] = nullptr;

}

/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (q)        5       5                     5
 * 4                     4  -->  4           .         4
 * 3                .    3       3               q     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_queenSlide()
{
   //setup
   Move move("e5g3");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, QUEEN);
   board.board[2][6] = new PieceSpy(2, 6, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(QUEEN == (board.board[2][6])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[2][6];
   delete board.board[4][4];
   board.board[2][6] = board.board[4][4] = nullptr;

}


/********************************************************
*    e5a5b
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
* |                     |       |                     |
* 8                     8       8                     8
* 7                     7       7                     7
* 6                     6       6                     6
* 5   B      (q)        5       5  (q)      .         5
* 4                     4  -->  4                     4
* 3                     3       3                     3
* 2                     2       2                     2
* 1                     1       1                     1
* |                     |       |                     |
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
********************************************************/
void TestBoard::move_queenAttack()
{
   //setup
   Move move("e5a5b");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, QUEEN);
   board.board[4][0] = new PieceSpy(4, 0, false /*isWhite*/, BISHOP);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(QUEEN == (board.board[4][0])->getType());
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[4][0];
   delete board.board[4][4];
   board.board[4][0] = board.board[4][4] = nullptr;

}


/********************************************************
 *  e1f1
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k).       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingMove()
{
   //setup
   Move move("e1f1");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[0][4] = new PieceSpy(0, 4, true  /*isWhite*/, KING);
   board.board[0][5] = new PieceSpy(0, 5, false /*isWhite*/, SPACE);
   board.board[0][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(KING == (board.board[0][5])->getType());
   assertUnit(SPACE == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[0][5];
   delete board.board[0][4];
   board.board[0][5] = board.board[0][4] = nullptr;

}


/********************************************************
 *    e1f1r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k)R       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingAttack()
{
   //setup
   Move move("e1f1r");
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[0][4] = new PieceSpy(0, 4, true  /*isWhite*/, KING);
   board.board[0][5] = new PieceSpy(0, 5, false /*isWhite*/, ROOK);
   board.board[0][4]->nMoves = 17;
   PieceSpy::reset();
   //exercise
   board.move(move);
   //verify
   assertUnit(18 == board.numMoves);
   assertUnit(KING == (board.board[0][5])->getType());
   assertUnit(SPACE == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);
   //teardown
   delete board.board[0][5];
   delete board.board[0][4];
   board.board[0][5] = board.board[0][4] = nullptr;
}

/********************************************************
 *    e1g1c
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k). . r   1       1           . r k .   1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingShortCastle()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}



/********************************************************
 *    e1c1C
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1   r . . .(k)        1       1   . . k r .         1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingLongCastle()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}




/********************************************************
 *        +---a-b-c-d-e-f-g-h---+
 *        |                     |
 *        8   R N B Q K B N R   8
 *        7   P P P P P P P P   7
 *        6                     6
 *        5                     5
 *   -->  4                     4
 *        3                     3
 *        2   p p p p p p p p   2
 *        1   r n b q k b n r   1
 *        |                     |
 *        +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::construct_default()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


