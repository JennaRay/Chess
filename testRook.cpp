/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    Jenna Ray
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
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
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
   //setup
   BoardEmpty board;
   Rook rook(1, 2, false /*white*/);
   rook.fWhite = true;
   rook.position.set(1, 2);
   board.board[1][2] = &rook;
   White white(PAWN);
   board.board[1][1] = &white;
   board.board[2][2] = &white;
   board.board[1][3] = &white;
   board.board[0][2] = &white;
   set <Move> moves;
   //exercise
   rook.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 0); // no moves
   //teardown
   board.board[1][1] = nullptr;
   board.board[2][2] = nullptr;
   board.board[1][3] = nullptr;
   board.board[0][2] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   //setup
   BoardEmpty board;
   Rook rook(7, 7, false);
   rook.position.set(1, 2);
   rook.fWhite = true;
   board.board[1][2] = &rook;
   set <Move> moves;
   //exercise
   rook.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 14); // 14 possible moves
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
   //teardown
   board.board[1][2] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   //setup
   BoardEmpty board;
   Rook rook(7, 7, false);
   rook.position.set(1, 2);
   rook.fWhite = true;
   board.board[1][2] = &rook;
   White white(PAWN);
   board.board[1][0] = &white;
   board.board[7][2] = &white;
   board.board[1][7] = &white;
   board.board[0][2] = &white;
   set <Move> moves;
   //exercise
   rook.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 10); // 10 moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   //teardown
   board.board[1][0] = nullptr;
   board.board[7][2] = nullptr;
   board.board[1][7] = nullptr;
   board.board[0][2] = nullptr;
   board.board[1][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   //setup
   BoardEmpty board;
   Rook rook(7, 7, false);
   rook.position.set(1, 2);
   rook.fWhite = true;
   board.board[1][2] = &rook;
   Black black(PAWN);
   board.board[1][0] = &black;
   board.board[7][2] = &black;
   board.board[1][7] = &black;
   board.board[0][2] = &black;
   set <Move> moves;
   //exercise
   rook.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 14); // 14 moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2a2p")) != moves.end());
   assertUnit(moves.find(Move("c2c8p")) != moves.end());
   assertUnit(moves.find(Move("c2h2p")) != moves.end());
   assertUnit(moves.find(Move("c2c1p")) != moves.end());
   //teardown
   board.board[1][0] = nullptr;
   board.board[7][2] = nullptr;
   board.board[1][7] = nullptr;
   board.board[0][2] = nullptr;
   board.board[1][2] = nullptr;
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   //setup
   Rook rook(7,7,true);
   PieceType type = SPACE;
   //exercise
   type = rook.getType();
}
