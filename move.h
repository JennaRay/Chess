/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
   Move();
   Move(const string& rhs) { read(rhs); }

  
   //void read(const string & rhs) {}
   void read(string text)
   {
      // set all the attributes of the move
      this->text = text;
      moveType = MOVE;

      string::const_iterator it = text.cbegin();

      // get the source
      int row = *it - 'a';
      it++;
      int col = *it - '1';
      it++;
      source = Position();
      source.setRow(row);
      source.setCol(col);

      // get the destination
      row = *it - 'a';
      it++;
      col = *it - '1';
      it++;
      dest = Position();
      dest.setRow(row);
      dest.setCol(col);

      // capture and promotion information
      for (; it != text.end(); ++it)
      {
         switch (*it)
         {
         case 'p':
            // capture a pawn
            capture = PAWN;
            moveType = MOVE;
            break;
         case 'n':
            // capture a knight
            capture = KNIGHT;
            moveType = MOVE;
            break;
         case 'b':
            // capture a bishop
            capture = BISHOP;
            moveType = MOVE;
            break;
         case 'r':
            // capture a rook
            capture = ROOK;
            moveType = MOVE;
            break;
         case 'q':
            // capture a queen
            capture = QUEEN;
            moveType = MOVE;
            break;
         case 'k':
            // !! you can't capture a king you silly!
            capture = KING;
            moveType = MOVE;
            break;

         case 'c':  // short castling or king's castle
            moveType = CASTLE_KING;
            break;
         case 'C':  // long castling or queen's castle
            moveType = CASTLE_QUEEN;
            break;
         case 'E':  // En-passant
            moveType = ENPASSANT;
            break;

         case 'N':
            // Promote to knight
            promote = KNIGHT;
            moveType = MOVE;
            break;
         case 'B':
            // Promote to Bishop
            promote = BISHOP;
            moveType = MOVE;
            break;
         case 'R':
            // Promote to Rook
            promote = ROOK;
            moveType = MOVE;
            break;
         case 'Q':
            // Promote to Queen
            promote = QUEEN;
            moveType = MOVE;
            break;
         }
      }

      // error checking
      if (source.getLocation() < 0 || source.getLocation() >= 64 ||
         dest.getLocation() < 0 || dest.getLocation() >= 64)
         source = dest = 0xff;
   };
   //string getText() const { return std::string(""); }
   string& getText()
   {
      if (text == "")
         createText();
      return text;
   }

   void createText()
   {
      // create the text version of the move
      text = "";
      text += source.getRow() + 'a';
      text += source.getCol() + '1';
      text += dest.getRow() + 'a';
      text += dest.getCol() + '1';

      // capture and promotion information
      if (moveType != MOVE)
      {
         switch (moveType)
         {
         case CASTLE_KING:
            text += 'c';
            break;
         case CASTLE_QUEEN:
            text += 'C';
            break;
         case ENPASSANT:
            text += 'E';
            break;
         }
      }
      else if (capture != SPACE || promote != SPACE)
         if (capture != SPACE)
            text += letterFromPieceType(capture);
      if (promote != SPACE)
         text += letterFromPieceType(promote);
   }

   // operator overloads
   const Move& operator = (const Move& rhs)
   {
      source = rhs.source;
      dest = rhs.dest;
      promote = rhs.promote;
      capture = rhs.capture;
      moveType = MOVE;
      moveType = rhs.moveType;
      isWhite = rhs.isWhite;
      text = rhs.text;
      return *this;
   };
   bool operator == (const Move& rhs) const
   {
      if (text == rhs.text)
         return true;
      else return false;
   };
   bool operator != (const Move& rhs) const
   {
      if (text != rhs.text)
         return true;
      else return false;
   };
   bool operator <  (const Move& rhs) const
   {
      if (dest < rhs.dest)
         return true;
      else return false;
   };

private:
   char letterFromPieceType(PieceType pt)     const
   {
      switch (pt)
      {
      case PAWN:
         return 'p';
         break;
      case KNIGHT:
         return 'n';
         break;
      case BISHOP:
         return 'b';
         break;
      case ROOK:
         return 'r';
         break;
      case QUEEN:
         return 'q';
         break;
      case KING:
         return 'k';
         break;
      case SPACE:
         return ' ';
         break;
      }
   }
   PieceType pieceTypeFromLetter(char letter) const
   {
      switch (letter)
      {
      case 'p':
         return PAWN;
         break;
      case 'n':
         return KNIGHT;
         break;
      case 'b':
         return BISHOP;
         break;
      case 'r':
         return ROOK;
         break;
      case 'q':
         return QUEEN;
         break;
      case 'k':
         return KING;
         break;
      case ' ':
         return SPACE;
         break;
      default:
         return INVALID;
      }
   }



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


