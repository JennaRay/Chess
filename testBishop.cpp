/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
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
 * 3     p   p           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_blocked()
{
   //setup
   BoardEmpty board;
   Bishop bishop(7,7, false);
   bishop.fWhite = true;
   bishop.position.set(1, 2);
   board.board[1][2] = &bishop;
   White white(PAWN);
   board.board[0][1] = &white;
   board.board[2][1] = &white;
   board.board[0][3] = &white;
   board.board[2][3] = &white;
   set <Move> moves;

   //exercise
   bishop.getMoves(moves, board);

   //verify
   assertUnit(moves.size() == 0); // no possible moves

   //teardown
   board.board[1][2] = nullptr; // white bishop
   board.board[0][1] = nullptr; // white pawn
   board.board[2][1] = nullptr; // white pawn
   board.board[0][3] = nullptr; // white pawn
   board.board[2][3] = nullptr; // white pawn

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   //setup
   BoardEmpty board;
   Bishop bishop(7, 7, false);
   bishop.fWhite = true;
   bishop.position.set(1, 2);
   board.board[1][2] = &bishop;

   set <Move> moves;
   //exercise
   bishop.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 9); // 9 possible moves
   assertUnit(moves.find(Move("c2h7")) != moves.end());
   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   //teardown
   board.board[1][2] = nullptr; // white bishop

}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   //setup
   BoardEmpty board;
   Bishop bishop(7, 7, false);
   bishop.fWhite = true;
   bishop.position.set(1, 2);
   board.board[1][2] = &bishop;
   White white(PAWN);
   board.board[0][1] = &white;
   board.board[0][3] = &white;
   board.board[3][0] = &white;
   board.board[6][7] = &white;
   set <Move> moves;
   //exercise
   bishop.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 5); // 5 possible moves
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   //teardown
   board.board[1][2] = nullptr; // white bishop
   board.board[0][1] = nullptr; // black pawn
   board.board[0][3] = nullptr; // black pawn
   board.board[3][0] = nullptr; // black pawn
   board.board[6][7] = nullptr; // black pawn
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   //setup
   BoardEmpty board;
   Bishop bishop(7, 7, false);
   bishop.fWhite = true;
   bishop.position.set(1, 2);
   board.board[1][2] = &bishop;
   Black black(PAWN);
   board.board[0][1] = &black;
   board.board[0][3] = &black;
   board.board[3][0] = &black;
   board.board[6][7] = &black;
   set <Move> moves;
   //exercise
   bishop.getMoves(moves, board);
   //verify
   assertUnit(moves.size() == 9);// 9 possible moves
   assertUnit(moves.find(Move("c2b1p")) != moves.end());
   assertUnit(moves.find(Move("c2d1p")) != moves.end());
   assertUnit(moves.find(Move("c2a4p")) != moves.end());
   assertUnit(moves.find(Move("c2h7p")) != moves.end());
   //teardown
   board.board[1][2] = nullptr; // white bishop
   board.board[0][1] = nullptr; // black pawn
   board.board[0][3] = nullptr; // black pawn
   board.board[3][0] = nullptr; // black pawn
   board.board[6][7] = nullptr; // black pawn
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   //setup
   Bishop bishop(7, 7, false);
   //exercise
   PieceType type = bishop.getType();
   //verify
   assertUnit(type == BISHOP);
}
