/**
@file rushhour.h
@author Leah Kramer
@date 10-3-2017
*/

#include <iostream>

using namespace std;

class Car{
  friend class RushHour;
  public:
    Car();

    int getNum();
    int getSize();
    int getDir();
    int getRow();
    int getCol();

    void setNum(int car);
    void setSize(int s);
    void setDir(char d);
    void setRow(int r);
    void setCol(int c);

  private:
    int carNum; ///< Index of Car class object
    int size; ///< Size of Car class object. Can be 2 or 3
    int dir; ///< Orientation of Car class object. Can be H, h, V, or v
    int row; ///< Car class object reference point on board
    int col; ///< Car class object reference point on board
};

class RushHour{
  friend class Car;

  public:
    RushHour();

    void loadBoard(int carNum); //Create board from terminal input
    bool moveForward(int carNum); //Move forward if possible
    bool moveBack(int carNum); //Move back if possible
    bool winCheck(); //Check if car 0 is at the east edge
    void solveIt(int numCars); //Branch in bound tree search
    void print(); //Debugging purposes
    void printCar(int CarNum);
    void loadcars(int carNum, int carSize, char carDir, int row, int col);
    bool solved;
    int numMoves;
    int bestMoves;

  private:


    int maxMoves;
    int boardArr[7][7];
    Car carArr[10]; //Holds car objects
};
