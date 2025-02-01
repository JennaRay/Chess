/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
   //setup
   Move move;
   Position source = Position(move.source);
   Position dest = Position(move.dest);
   //verify
   assertUnit(source.isInvalid());
   assertUnit(dest.isInvalid());
}

/*************************************
 * CONSTRUCTOR : standard string move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::constructString_simple()
{
   //setup
   Move move("e5e6");

   //verify
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.dest.getRow() == 4);
   assertUnit(move.dest.getCol() == 5);
   assertUnit(move.moveType == Move::MOVE);
}

/*************************************
 * READ simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::read_simple()
{
   //setup
   Move move;

   //exercise
   move.read("e5e6");

   //verify
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.dest.getRow() == 4);
   assertUnit(move.dest.getCol() == 5);
   assertUnit(move.moveType == Move::MOVE);
}

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{
   //setup
   Move move;

   //exercise
   move.read("e5d6r");

   //verify
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.dest.getRow() == 3);
   assertUnit(move.dest.getCol() == 5);
   assertUnit(move.moveType == Move::MOVE);
   assertUnit(move.capture == ROOK);
}

/*************************************
 * READ enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::read_enpassant()
{
   //setup
   Move move;

   //exercise
   move.read("e5f6E");

   //verify
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.dest.getRow() == 5);
   assertUnit(move.dest.getCol() == 5);
   assertUnit(move.moveType == Move::ENPASSANT);
}

/*************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::read_castleKing()
{
   //setup
   Move move;

   //exercise
   move.read("e1g1c");

   //verify
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.source.getCol() == 0);
   assertUnit(move.dest.getRow() == 6);
   assertUnit(move.dest.getCol() == 0);
   assertUnit(move.moveType == Move::CASTLE_KING);
}

/*************************************
 * READ queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::read_castleQueen()
{
   //setup
   Move move;

   //exercise
   move.read("e1c1C");

   //verify
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.source.getCol() == 0);
   assertUnit(move.dest.getRow() == 2);
   assertUnit(move.dest.getCol() == 0);
   assertUnit(move.moveType == Move::CASTLE_QUEEN);
}

/*************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::assign_simple()
{
   //setup
   Move move("e5e6");
   Move newMove;

   //exercise
   newMove = move;

   //verify
   assertUnit(newMove.source.getRow() == 4);
   assertUnit(newMove.source.getCol() == 4);
   assertUnit(newMove.dest.getRow() == 4);
   assertUnit(newMove.dest.getCol() == 5);
   assertUnit(newMove.moveType == Move::MOVE);
}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
   //setup
   Move move("e5d6r");
   Move newMove;

   //exercise
   newMove = move;

   //verify
   assertUnit(newMove.source.getRow() == 4);
   assertUnit(newMove.source.getCol() == 4);
   assertUnit(newMove.dest.getRow() == 3);
   assertUnit(newMove.dest.getCol() == 5);
   assertUnit(newMove.moveType == Move::MOVE);
   assertUnit(newMove.capture == ROOK);
}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
   //setup
   Move move("e5f6E");
   Move newMove;

   //exercise
   newMove = move;

   //verify
   assertUnit(newMove.source.getRow() == 4);
   assertUnit(newMove.source.getCol() == 4);
   assertUnit(newMove.dest.getRow() == 5);
   assertUnit(newMove.dest.getCol() == 5);
   assertUnit(newMove.moveType == Move::ENPASSANT);
}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
   //setup
   Move move("e1g1c");
   Move newMove;

   //exercise
   newMove = move;

   //verify
   assertUnit(newMove.source.getRow() == 4);
   assertUnit(newMove.source.getCol() == 0);
   assertUnit(newMove.dest.getRow() == 6);
   assertUnit(newMove.dest.getCol() == 0);
   assertUnit(newMove.moveType == Move::CASTLE_KING);
}

/*************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
   //setup
   Move move("e1c1C");
   Move newMove;

   //exercise
   newMove = move;

   //verify
   assertUnit(newMove.source.getRow() == 4);
   assertUnit(newMove.source.getCol() == 0);
   assertUnit(newMove.dest.getRow() == 2);
   assertUnit(newMove.dest.getCol() == 0);
   assertUnit(newMove.moveType == Move::CASTLE_QUEEN);
}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output:  e5e6
 **************************************/
void TestMove::getText_simple()
{
   //setup
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 4);
   move.moveType = Move::MOVE;

   //exercise
   string text = move.getText();
   string text2 = "e5e6";

   //verify
   assertUnit(text.compare(text2) == 1);
}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output:  e5e6r
 **************************************/
void TestMove::getText_capture()
{
   //setup
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 4);
   move.moveType = Move::MOVE;
   move.capture = ROOK;

   //exercise
   string text = move.getText();
   string text2 = "e5e6r";
   //verify
   assertUnit(text.compare(text2) == 1);
}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
   //setup
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(5, 5);
   move.moveType = Move::ENPASSANT;
   move.capture = PAWN;

   //exercise
   string text = move.getText();
   string text2 = "e5f6E";

   //verify
   assertUnit(text.compare(text2) == 1);
}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
   //setup 
   Move move;
   move.source = Position(0, 4);
   move.dest = Position(0, 6);
   move.moveType = Move::CASTLE_KING;

   //exercise
   string text = move.getText();
   string text2 = "e1g1c";

   //verify
   assertUnit(text.compare(text2) == 1);
}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
   //setup
   Move move;
   move.source = Position(0, 4);
   move.dest = Position(0, 2);
   move.moveType = Move::CASTLE_QUEEN;

   //exercise
   string text = move.getText();
   string text2 = "e1c1C";

   //verify
   assertUnit(text.compare(text2) == 1);
}

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(SPACE);

   //verify
   assertUnit(letter == ' ');
}

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(PAWN);

   //verify
   assertUnit(letter == 'p');
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(BISHOP);

   //verify
   assertUnit(letter == 'b');
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(KNIGHT);

   //verify
   assertUnit(letter == 'n');
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(ROOK);

   //verify
   assertUnit(letter == 'r');
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(QUEEN);

   //verify
   assertUnit(letter == 'q');
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
   //setup
   Move move;

   //exercise
   char letter = move.letterFromPieceType(KING);

   //verify
   assertUnit(letter == 'k');
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   //setup
   Move move;

   //exercise
   PieceType pt = move.pieceTypeFromLetter('p');

   //verify
   assertUnit(pt == PAWN);
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   //setup
   Move move;

   //exercise
   PieceType pt = move.pieceTypeFromLetter('b');

   //verify
   assertUnit(pt == BISHOP);
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Output:  KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   //setup
   Move move;

   //exercise
   PieceType pt = move.pieceTypeFromLetter('n');

   //verify
   assertUnit(pt == KNIGHT);
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Output:  ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   //setup
   Move move;

   //exercise
   PieceType pt = move.pieceTypeFromLetter('r');

   //verify
   assertUnit(pt == ROOK);
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Output:  QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   //setup
   Move move;

   //exercise
   PieceType pt = move.pieceTypeFromLetter('q');

   //verify
   assertUnit(pt == QUEEN);
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Output:  KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   //setup
   Move move;

   //exercise
   PieceType pt = move.pieceTypeFromLetter('k');

   //verify
   assertUnit(pt == KING);
}


/*************************************
 * EQUAL - NOT
 * Input : b2b4 == b2b5
 * Output: false
 **************************************/
void TestMove::equal_not()
{
   //setup
   Move move1("b2b4");
   Move move2("b2b5");

   //verify
   assertUnit((move1 == move2) == false);
}

/*************************************
 * EQUAL - EQUALS
 * Input : b2b4 == b2b4
 * Output: true
 **************************************/
void TestMove::equal_equals()
{
   //setup
   Move move1("b2b4");
   Move move2("b2b4");

   //verify
   assertUnit(move1 == move2);
}

/*************************************
 * LESS THAN - LESS THAN
 * Input : b2b2 < b2b4
 * Output: false
 *    Note that the less-than operator is needed
 *    so std::set<T> can sort the elements. Thus,
 *    any T in a set must define less-than. In this
 *    case, I defined it according to the
 *     destination's Position's location.
 **************************************/
void TestMove::lessthan_lessthan()
{
   //setup
   Move move1("b2b2");
   Move move2("b2b4");

   //verify
   assertUnit(move1 < move2);
}

/*************************************
 * LESS THAN - EQUALS
 * Input : b2b4 < b2b4
 * Output: false
 **************************************/
void TestMove::lessthan_equals()
{
   //setup
   Move move1("b2b4");
   Move move2("b2b4");

   //verify
   assertUnit((move1 < move2) == false);
}

/*************************************
 * LESS THAN - GREATAER THAN
 * Input : b2b4 < b2b2
 * Output: false
 **************************************/
void TestMove::lessthan_greaterthan()
{
   //setup
   Move move1("b2b4");
   Move move2("b2b2");

   //verify
   assertUnit((move1 < move2) == false);
}

