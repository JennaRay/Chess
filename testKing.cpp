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
	king.position.set(4, 3);
	board.board[4][3] = &king;
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
	BoardEmpty board;
   King king(7, 7, false);
   king.fWhite = true;
   king.position.set(0, 4);
	king.nMoves = 0;
   board.board[0][4] = &king;
   White white(PAWN);
   board.board[1][3] = &white;
   board.board[1][4] = &white;
   board.board[1][5] = &white;
	Rook rook1(0, 0, true);
	rook1.nMoves = 0;
	Rook rook2(0, 7, true);
	rook2.nMoves = 0;
   board.board[0][0] = &rook1;
   board.board[0][7] = &rook2;
   set <Move> moves;

	// EXCERCISE
   king.getMoves(moves, board);
	// VERIFY
   assertUnit(moves.size() == 4);
   assertUnit(moves.find(Move("e1f1")) != moves.end());
   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1g1c")) != moves.end());
	assertUnit(moves.find(Move("e1c1c")) != moves.end());
	// TEARDOWN
   board.board[0][4] = nullptr;
   board.board[1][3] = nullptr;
   board.board[1][4] = nullptr;
   board.board[1][5] = nullptr;
   board.board[0][0] = nullptr;
   board.board[0][7] = nullptr;
   delete board.board[0][0];
   delete board.board[0][7];
	delete board.board[0][4];
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
   BoardEmpty board;
   King king(7, 7, false);
   king.fWhite = false;
   king.position.set(7, 4);
   board.board[7][4] = &king;
   Black black(PAWN);
   board.board[6][3] = &black;
   board.board[6][4] = &black;
   board.board[6][5] = &black;
   board.board[7][0] = new Rook(0, 0, false);
   board.board[7][7] = new Rook(0, 7, false);
   set <Move> moves;
	// EXCERCISE
   king.getMoves(moves, board);
	// VERIFY
   assertUnit(moves.size() == 4);
   assertUnit(moves.find(Move("e8f8")) != moves.end());
   assertUnit(moves.find(Move("e8d8")) != moves.end());
   assertUnit(moves.find(Move("e8g8c")) != moves.end());
   assertUnit(moves.find(Move("e8c8c")) != moves.end());
	// TEARDOWN
   board.board[7][4] = nullptr;
   board.board[6][3] = nullptr;
   board.board[6][4] = nullptr;
   board.board[6][5] = nullptr;
   board.board[7][0] = nullptr;
   board.board[7][7] = nullptr;
   delete board.board[7][0];
   delete board.board[7][7];
   delete board.board[7][4];
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
	BoardEmpty board;
   King king(7, 7, false);
   king.fWhite = true;
	king.nMoves = 2;
   king.position.set(0, 4);
   board.board[0][4] = &king;
   White white(PAWN);
   board.board[1][3] = &white;
   board.board[1][4] = &white;
   board.board[1][5] = &white;
   board.board[0][0] = new Rook(0, 0, true);
   board.board[0][7] = new Rook(0, 7, true);
   set <Move> moves;
	// EXCERCISE
   king.getMoves(moves, board);
	// VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("e1f1")) != moves.end());
   assertUnit(moves.find(Move("e1d1")) != moves.end());
	// TEARDOWN
   board.board[0][4] = nullptr;
   board.board[1][3] = nullptr;
   board.board[1][4] = nullptr;
   board.board[1][5] = nullptr;
   board.board[0][0] = nullptr;
   board.board[0][7] = nullptr;
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
	BoardEmpty board;
   King king(7, 7, false);
   king.fWhite = true;
   king.position.set(0, 4);
   board.board[0][4] = &king;
   White white(PAWN);
   board.board[1][3] = &white;
   board.board[1][4] = &white;
   board.board[1][5] = &white;
   board.board[0][0] = new Rook(0, 0, true);
	board.board[0][0]->nMoves = 2;
   board.board[0][7] = new Rook(0, 7, true);
   board.board[0][7]->nMoves = 2;
   set <Move> moves;
	// EXCERCISE
   king.getMoves(moves, board);
	// VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("e1f1")) != moves.end());
   assertUnit(moves.find(Move("e1d1")) != moves.end());
	// TEARDOWN
   board.board[0][4] = nullptr;
   board.board[1][3] = nullptr;
   board.board[1][4] = nullptr;
   board.board[1][5] = nullptr;
   board.board[0][0] = nullptr;
   board.board[0][7] = nullptr;
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
	//setup
   King king(7, 7, false);
   //exercise
   PieceType type = king.getType();
   //verify
   assertUnit(type == KING);
   //teardown
   //none

}


