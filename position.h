/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0 };
const Delta ADD_C = { 0,  1 };
const Delta SUB_R = { -1,  0 };
const Delta SUB_C = { 0, -1 };


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs) { colRow = rhs.colRow; }
   Position() : colRow(0x99) {              }
   bool isInvalid() const
   {
      // if the row or column is invalid, then the position is invalid
      if (colRow == 0xff || getRow() == -1 || getCol() == -1)
         return true;
      else
         return false;
   }
   bool isValid()   const
   {
      // if the row and column are valid, then the position is valid
      if (colRow != 0xff && getRow() != -1 && getCol() != -1)
         return true;
      else
         return false;
   }
   void setValid() {              }
   void setInvalid() {              }
   //Operation overloading
   bool operator <  (const Position& rhs) const
   {
      if (colRow < rhs.colRow)
         return true;
      else return false;
   }
   bool operator == (const Position& rhs) const
   {
      if (rhs.colRow == colRow)
         return true;
      else return false;
   }
   bool operator != (const Position& rhs) const
   {
      if (colRow != rhs.colRow)
         return true;
      else return false;
   }
   const Position& operator =  (const Position& rhs)
   {
      colRow = rhs.colRow;
      return *this;
   }
   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(location) { }
   int getLocation() const { return getRow() * 8 + getCol(); }
   void setLocation(int location)
   {
      int col = location % 8;
      int row = (location - col) / 8;
      colRow = col * 16 + row;
   }


   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow(c * 16 + r) {           }
   virtual int getCol() const
   {
      //if col is to high or too low, return -1
      int col = (colRow - getRow()) / 16;
      if (col < 0 || col > 7)
         return -1;
      if (colRow % 16 > 7 || colRow % 16 < 0)
         return -1;
      return col;
   }
   virtual int getRow() const
   {
      //if row is to high or too low, return -1
      if (colRow > 16 * 7 + 7 || colRow < 0)
         return -1;
      if (colRow % 16 > 7 || colRow % 16 < 0)
         return -1;
      return colRow % 16;
   }
   void setRow(int r) { colRow -= (colRow % 16); colRow = +r; }
   void setCol(int c) { colRow -= getCol(); colRow += c * 16; }
   void set(int c, int r)
   {
      //if col is too high or too low set both to invalid
      if (c < 0 || c > 7)
         colRow = 0xff;
      //if row is too high or too low set row to invalid
      else if (r < 0 || r > 7)
         colRow = 0x3f;
      else
         colRow = c * 16 + r;
   }

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x99)
   {
      colRow = (s[0] - 'a') * 16 + (s[1] - '1');
   }
   const Position& operator =  (const char* rhs)
   {
      colRow = (rhs[0] - 'a') * 16 + (rhs[1] - '1');
      return *this;
   }
   const Position& operator =  (const string& rhs)
   {
      colRow = (rhs[0] - 'a') * 16 + (rhs[1] - '1');
      return *this;
   }


   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.

   int getX()   const
   {
      return (int)((double)getCol() * getSquareWidth() + getSquareWidth());
   }
   int getY()   const
   {
      return (int)((double)getRow() * getSquareHeight() + getSquareHeight());
   }
   void setXY(double x, double y)
   {
      set((int)(x / getSquareWidth()) - 1,
         8 - (int)(y / getSquareHeight()));
   }
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setBoardWidthHeight(int widthBoard, int heightBoard)
   {
      if (widthBoard < 0 || heightBoard < 0)
         return;
      squareWidth = (double)widthBoard / 10.0; // 8 squares + 2 spaces
      squareHeight = (double)heightBoard / 10.0;
   }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(rhs.colRow) { colRow += delta.dCol * 16 + delta.dRow; }
   void adjustRow(int dRow) { colRow += dRow; }
   void adjustCol(int dCol) { colRow += dCol * 16; }
   const Position& operator += (const Delta& rhs)
   {
      // check for going off the bottom or top of board
      if ((rhs.dRow < 0 && getRow() == 0) || (rhs.dRow > 0 && getRow() == 7))
         colRow = 0xff;
      // check for going off the left or right of board
      if ((rhs.dCol < 0 && getCol() == 0) || (rhs.dCol > 0 && getCol() == 7))
         colRow = 0xff;
      if (colRow != 0xff)
      {
         colRow += rhs.dCol * 16 + rhs.dRow;
      }

      return *this;
   }
   Position operator + (const Delta& rhs) const
   {
      Position pos(*this);
      pos += rhs;
      return pos;
   }
private:
   void set(uint8_t colRowNew) { colRow = colRowNew; }

   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream& operator << (ostream& out, const Position& pos);
istream& operator >> (istream& in, Position& pos);

