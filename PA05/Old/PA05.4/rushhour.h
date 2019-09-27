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
    int carNum;
    int size;
    int dir;
    int row;
    int col;
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
