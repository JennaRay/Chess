/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    William Torman
 * Summary:
 *    The unit tests for the pawn
 * Time:
 *		1.5 hours
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      



 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board move forward one space: b4 --> b5
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8 
  * 7                     7
  * 6                     6
  * 5     .               5 4
  * 4    (p)              4 3
  * 3                     3
  * 2                     2
  * 1                     1 0
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  *     0 1            
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
	// SETUP
	BoardEmpty board;
	Pawn pawn(7, 7, false /*white*/);
	pawn.fWhite = true;
	pawn.position.set(1, 3);
	board.board[1][3] = &pawn;
	set <Move> moves;

	// EXERCISE
	pawn.getMoves(moves, board);

	// verify
	assertUnit(moves.size() == 1); // number of possible moves
	assertUnit(moves.find(Move("b4b5")) != moves.end());

	// TEARDOWN
	board.board[1][3] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board move forward one space: b4 --> b3
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4 3
 * 3     .               3 2
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 *       1
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
	// SETUP
	BoardEmpty board;
	Pawn pawn(7, 7, false /*white*/);
	pawn.fWhite = false; // black pawn
	pawn.position.set(1, 3);
	board.board[1][3] = &pawn;
	set <Move> moves;

	// EXERCISE
	pawn.getMoves(moves, board);

	// verify
	assertUnit(moves.size() == 1); // number of possible moves
	assertUnit(moves.find(Move("b4b3")) != moves.end());

	// TEARDOWN
	board.board[1][3] = nullptr; // black pawn
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance: b2 --> b4 as well as b2 --> b3
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
	// SETUP
	BoardEmpty board;
	Pawn pawn(7, 7, false /*white*/);
	pawn.fWhite = true;
	pawn.position.set(1, 1);
	board.board[1][1] = &pawn;
	set <Move> moves;

	// EXERCISE
	pawn.getMoves(moves, board);

	// verify
	assertUnit(moves.size() == 2); // number of possible moves
	assertUnit(moves.find(Move("b2b3")) != moves.end());
	assertUnit(moves.find(Move("b2b4")) != moves.end());

	// TEARDOWN
	board.board[1][1] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance: c7 --> c5 as well as c7 --> c5
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7 8
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 *         2
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
	// SETUP
	BoardEmpty board;
	Pawn pawn(7, 7, false /*white*/);
	pawn.fWhite = false; // black pawn
	pawn.position.set(2, 8);
	board.board[2][8] = &pawn;
	set <Move> moves;

	// EXERCISE
	pawn.getMoves(moves, board);

	// verify
	assertUnit(moves.size() == 2); // number of possible moves
	assertUnit(moves.find(Move("c7c6")) != moves.end());
	assertUnit(moves.find(Move("c7c5")) != moves.end());

	// TEARDOWN
	board.board[2][8] = nullptr; // black pawn
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move white pawn b6 and capture two: a7 and c7. b7 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7 6
 * 6    (p)              6 5
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 *     0 1 2
 **************************************/
void TestPawn::getMoves_captureWhite()
{
	// SETUP
	BoardEmpty board;
	Pawn pawn(7, 7, false);
	pawn.fWhite = true; // white pawn
	pawn.position.set(1, 2);
	board.board[1][5] = &pawn;
	Black black(PAWN);
	board.board[0][6] = &black;
	board.board[1][6] = &black;
	board.board[2][6] = &black;
	set <Move> moves;

	// EXERCISE
	pawn.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 2);// 9 possible moves
	assertUnit(moves.find(Move("b6a5p")) != moves.end());
	assertUnit(moves.find(Move("b6c7p")) != moves.end());


	// TEARDOWN
	board.board[1][5] = nullptr; // white pawn
	board.board[0][6] = nullptr; // black pawn
	board.board[1][6] = nullptr; // black pawn
	board.board[2][6] = nullptr; // black pawn
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move black pawn b6 and capture two: a5 and c5. b5 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6 5
 * 5   p p p             5 4
 * 4                     4 
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 *     0 1 2
 **************************************/
void TestPawn::getMoves_captureBlack()
{
	// SETUP
	BoardEmpty board;
	Pawn pawn(7, 7, false);
	pawn.fWhite = false; // black pawn
	pawn.position.set(1, 2);
	board.board[1][5] = &pawn;
	White white(PAWN);
	board.board[0][4] = &white;
	board.board[1][4] = &white;
	board.board[2][4] = &white;
	set <Move> moves;

	// EXERCISE
	pawn.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 2); // 2 possible moves
	assertUnit(moves.find(Move("b6a5p")) != moves.end());
	assertUnit(moves.find(Move("b6c5p")) != moves.end());


	// TEARDOWN
	board.board[1][5] = nullptr; // black pawn
	board.board[0][4] = nullptr; // white pawn
	board.board[1][4] = nullptr; // white pawn
	board.board[2][4] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant: white b5 can capture a5 and c5. Note that b6 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant black f4 can capture e4 and g4. Note that f3 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: white pawn b7 can capture two pawns: a8 and c8. 
 *            It can also move into b8. All three are promoted to queen
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   P . P             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: black pawn e2 can capture two rooks: d1 and f1.
 *            It can also move into e1. All three are promoted to queen
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r   r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

