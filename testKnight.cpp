/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
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
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(6, 0);
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(Move("g1e2p")) != moves.end());
   assertUnit(moves.find(Move("g1h3")) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   //setup
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(3, 4);
   White white5(PAWN);
   White white6(PAWN);
   White white7(PAWN);
   White white8(PAWN);
   board.board[1][5] = &white6;
   board.board[2][6] = &white7;
   board.board[4][6] = &white8;
   board.board[5][5] = &white5;
   White white1(PAWN);
   White white2(PAWN);
   White white3(PAWN);
   White white4(PAWN);
   board.board[1][3] = &white1;
   board.board[2][2] = &white2;
   board.board[4][2] = &white3;
   board.board[5][3] = &white4;
   set <Move> moves;

   //exercise
   knight.getMoves(moves, board);

   //verify
   assertUnit(moves.size() == 0);  // no possible moves

   //teardown
   board.board[1][5] = nullptr; // black pawn
   board.board[2][6] = nullptr; // black pawn
   board.board[4][6] = nullptr; // black pawn
   board.board[5][5] = nullptr; // black pawn
   board.board[1][3] = nullptr; // white pawn
   board.board[2][2] = nullptr; // white pawn
   board.board[4][2] = nullptr; // white pawn
   board.board[5][3] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   //setup
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(3, 4);
   Black black1(PAWN);
   Black black2(PAWN);
   Black black3(PAWN);
   Black black4(PAWN);
   board.board[1][5] = &black1;
   board.board[2][6] = &black2;
   board.board[4][6] = &black3;
   board.board[5][5] = &black4;
   Black black5(PAWN);
   Black black6(PAWN);
   Black black7(PAWN);
   Black black8(PAWN);
   board.board[1][3] = &black5;
   board.board[2][2] = &black6;
   board.board[4][2] = &black7;
   board.board[5][3] = &black8;
   set <Move> moves;

   //exercise
   knight.getMoves(moves, board);

   //verify
   assertUnit(moves.size() == 8);  // many possible moves
   assertUnit(moves.find(Move("d5b6p")) != moves.end());
   assertUnit(moves.find(Move("d5c7p")) != moves.end());
   assertUnit(moves.find(Move("d5e7p")) != moves.end());
   assertUnit(moves.find(Move("d5f6p")) != moves.end());
   assertUnit(moves.find(Move("d5b4p")) != moves.end());
   assertUnit(moves.find(Move("d5c3p")) != moves.end());
   assertUnit(moves.find(Move("d5e3p")) != moves.end());
   assertUnit(moves.find(Move("d5f4p")) != moves.end());

   //teardown
   board.board[1][5] = nullptr; // black pawn
   board.board[2][6] = nullptr; // black pawn
   board.board[4][6] = nullptr; // black pawn
   board.board[5][5] = nullptr; // black pawn
   board.board[1][3] = nullptr; // black pawn
   board.board[2][2] = nullptr; // black pawn
   board.board[4][2] = nullptr; // black pawn
   board.board[5][3] = nullptr; // black pawn

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   //setup
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(3, 4);
   set <Move> moves;

   //exercise
   knight.getMoves(moves, board);

   //verify
   assertUnit(moves.size() == 8);  // many possible moves
   assertUnit(moves.find(Move("d5b6")) != moves.end());
   assertUnit(moves.find(Move("d5c7")) != moves.end());
   assertUnit(moves.find(Move("d5e7")) != moves.end());
   assertUnit(moves.find(Move("d5f6")) != moves.end());
   assertUnit(moves.find(Move("d5b4")) != moves.end());
   assertUnit(moves.find(Move("d5c3")) != moves.end());
   assertUnit(moves.find(Move("d5e3")) != moves.end());
   assertUnit(moves.find(Move("d5f4")) != moves.end());
}



/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP  
   const Knight knight(7, 7, false /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = knight.getType();

   // VERIFY
   assertUnit(pt == KNIGHT);
}  // TEARDOWN
