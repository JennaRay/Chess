/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    Jenna Ray
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
   //setup
   BoardEmpty board;
   Queen queen(1, 2, false /*white*/);
   queen.fWhite = true;
   queen.position.set(1, 2);
   board.board[1][2] = &queen;
   White white(PAWN);
   board.board[1][1] = &white;
   board.board[2][1] = &white;
   board.board[2][2] = &white;
   board.board[2][3] = &white;
   board.board[1][3] = &white;
   board.board[0][3] = &white;
   board.board[0][2] = &white;
   board.board[0][1] = &white;
   set <Move> moves;
   //exercise
   queen.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 0); // no moves
   //teardown
   board.board[1][1] = nullptr;
   board.board[2][1] = nullptr;
   board.board[2][2] = nullptr;
   board.board[2][3] = nullptr;
   board.board[1][3] = nullptr;
   board.board[0][3] = nullptr;
   board.board[0][2] = nullptr;
   board.board[0][1] = nullptr;
   board.board[1][2] = nullptr;

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
   //setup
   BoardEmpty board;
   Queen queen(1, 2, false /*white*/);
   queen.fWhite = true;
   queen.position.set(1, 2);
   board.board[1][2] = &queen;
   set <Move> moves;
   //exercise
   queen.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 23); // lots of moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2a2")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2h2")) != moves.end());
   assertUnit(moves.find(Move("c2c1")) != moves.end());
   assertUnit(moves.find(Move("c2h7")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   //teardown
   board.board[1][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
   //setup
   BoardEmpty board;
   Queen queen(1, 2, false /*white*/);
   queen.fWhite = true;
   queen.position.set(1, 2);
   board.board[1][2] = &queen;
   White white(PAWN);
   board.board[1][0] = &white;
   board.board[3][0] = &white;
   board.board[7][2] = &white;
   board.board[6][7] = &white;
   board.board[1][7] = &white;
   board.board[0][3] = &white;
   board.board[0][2] = &white;
   board.board[0][1] = &white;
   set <Move> moves;
   //exercise
   queen.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 15); // 15 possible moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   //teardown
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[7][2] = nullptr;
   board.board[6][7] = nullptr;
   board.board[1][7] = nullptr;
   board.board[0][3] = nullptr;
   board.board[0][2] = nullptr;
   board.board[0][1] = nullptr;
   board.board[1][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
   //setup
   BoardEmpty board;
   Queen queen(1, 2, false /*white*/);
   queen.fWhite = true;
   queen.position.set(1, 2);
   board.board[1][2] = &queen;
   Black black(PAWN);
   board.board[1][0] = &black;
   board.board[3][0] = &black;
   board.board[7][2] = &black;
   board.board[6][7] = &black;
   board.board[1][7] = &black;
   board.board[0][3] = &black;
   board.board[0][2] = &black;
   board.board[0][1] = &black;
   set <Move> moves;
   //exercise
   queen.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 23); // 23 possible moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2a2p")) != moves.end());
   assertUnit(moves.find(Move("c2a4p")) != moves.end());
   assertUnit(moves.find(Move("c2c8p")) != moves.end());
   assertUnit(moves.find(Move("c2h7p")) != moves.end());
   assertUnit(moves.find(Move("c2h2p")) != moves.end());
   assertUnit(moves.find(Move("c2d1p")) != moves.end());
   assertUnit(moves.find(Move("c2c1p")) != moves.end());
   assertUnit(moves.find(Move("c2b1p")) != moves.end());
   //teardown
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[7][2] = nullptr;
   board.board[6][7] = nullptr;
   board.board[1][7] = nullptr;
   board.board[0][3] = nullptr;
   board.board[0][2] = nullptr;
   board.board[0][1] = nullptr;
   board.board[1][2] = nullptr;

}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   //setup
   Queen queen(7, 7, true);
   //exercise
   PieceType type = queen.getType();
   //verify
   assertUnit(type == QUEEN);
   //teardown
}
