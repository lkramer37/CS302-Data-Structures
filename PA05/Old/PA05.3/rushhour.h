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

    void setNum(int carNum);
    void setSize(int size);
    void setDir(char dir);
    void setRow(int row);
    void setCol(int col);

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
    void solve(int numCars); //Branch in bound tree search
    void print(); //Debugging purposes
    void printCar(int CarNum);
    void loadcars(int carNum, int carSize, char carDir, int row, int col);

  private:
    int numMoves;
    int bestMoves;
    int maxMoves;
    bool solved;
    int boardArr[7][7];
    Car carArr[10]; //Holds car objects
};
