/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(3, 4);
	board.board[3][4] = &king;
	White white(PAWN);
	board.board[2][5] = &white;
	board.board[2][4] = &white;
	board.board[2][3] = &white;
	board.board[3][5] = &white;
	board.board[3][3] = &white;
	board.board[4][5] = &white;
	board.board[4][4] = &white;
	board.board[4][3] = &white;
	set <Move> moves;

	// EXCERCISE
	king.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 0);

	// TEARDOWN
	board.board[4][3] = nullptr;
	board.board[2][5] = nullptr;
	board.board[2][4] = nullptr;
	board.board[2][3] = nullptr;
	board.board[3][5] = nullptr;
	board.board[3][3] = nullptr;
	board.board[4][5] = nullptr;
	board.board[4][4] = nullptr;
	board.board[4][3] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = false;
	king.position.set(4, 3);
	board.board[4][3] = &king;
	White white(PAWN);
	board.board[5][2] = &white;
	board.board[4][2] = &white;
	board.board[3][2] = &white;
	board.board[5][3] = &white;
	board.board[3][3] = &white;
	board.board[5][4] = &white;
	board.board[4][4] = &white;
	board.board[3][4] = &white;
	set <Move> moves;

	// EXCERCISE
	king.getMoves(moves, board);
	std::cout << moves.size() << std::endl;
	// VERIFY
	assertUnit(moves.size() == 8);
	assertUnit(moves.find(Move("d5c6p")) != moves.end());
	assertUnit(moves.find(Move("d5d6p")) != moves.end());
	assertUnit(moves.find(Move("d5e6p")) != moves.end());
	assertUnit(moves.find(Move("d5e4p")) != moves.end());
	assertUnit(moves.find(Move("d5c4p")) != moves.end());

	// TEARDOWN
	board.board[4][3] = nullptr;
	board.board[5][2] = nullptr;
	board.board[4][2] = nullptr;
	board.board[3][2] = nullptr;
	board.board[5][3] = nullptr;
	board.board[3][3] = nullptr;
	board.board[5][4] = nullptr;
	board.board[4][4] = nullptr;
	board.board[3][4] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(3, 4);
	board.board[3][4] = &king;
	set <Move> moves;

	// EXCERCISE
	king.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 8);
	assertUnit(moves.find(Move("d5c6")) != moves.end());
	assertUnit(moves.find(Move("d5d6")) != moves.end());
	assertUnit(moves.find(Move("d5e6")) != moves.end());
	assertUnit(moves.find(Move("d5c4")) != moves.end());
	assertUnit(moves.find(Move("d5d4")) != moves.end());
	assertUnit(moves.find(Move("d5e4")) != moves.end());
	assertUnit(moves.find(Move("d5c5")) != moves.end());
	assertUnit(moves.find(Move("d5e5")) != moves.end());

	// TEARDOWN
	board.board[4][3] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
	// SETUP
	BoardEmpty board;
	King king(7, 7, false);
	king.fWhite = true;
	king.position.set(0, 0);
	board.board[0][0] = &king;
	set <Move> moves;

	// EXCERCISE
	king.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 3);
	assertUnit(moves.find(Move("a1a2")) != moves.end());
	assertUnit(moves.find(Move("a1b1")) != moves.end());
	assertUnit(moves.find(Move("a1b2")) != moves.end());


	// TEARDOWN
	board.board[0][0] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
	// SETUP

	// EXCERCISE

	// VERIFY

	// TEARDOWN
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
	// SETUP

	// EXCERCISE

	// VERIFY

	// TEARDOWN
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
	// SETUP

	// EXCERCISE

	// VERIFY

	// TEARDOWN
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
	// SETUP

	// EXCERCISE

	// VERIFY

	// TEARDOWN
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
	// SETUP

	// EXCERCISE

	// VERIFY

	// TEARDOWN
   assertUnit(NOT_YET_IMPLEMENTED);
}


