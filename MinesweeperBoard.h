#ifndef MINESBOARD_H__
#define MINESBOARD_H__

#include <iostream>

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
bool hasMine;
bool hasFlag;
bool isRevealed; 
};


class MinesweeperBoard
{
 Field board[100][100];
 int width;
 int height;
 int mine;

public:
 MinesweeperBoard(); ///
 MinesweeperBoard(int width, int height, GameMode mode );///
  int getBoardWidth() const; ///
 int getBoardHeight() const; ///
 int getMineCount() const; ///

 int countMines(int x, int y) const; ///!

  bool hasFlag(int x, int y) const;///
   void toggleFlag(int x, int y);///
   void revealField(int x, int y);
 void debug_display() const;///
  bool isRevealed(int x, int y) const;
  char getFieldInfo(int x, int y) const;///
  GameState getGameState() const;//


};
#endif
