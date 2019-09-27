#include <iostream>

using namespace std;

class RushHour{
  public:
    RushHour();

    void loadBoard(Car carNum); //Create board from terminal input
    bool moveForward(int carNum); //Move forward if possible
    bool moveBack(int carNum); //Move back if possible
    bool winCheck(); //Check if car 0 is at the east edge
    void solve(int numMoves, int numCars); //Branch in bound tree search
    bool empty(int row, int col, int carSize, char carDir); //checks if spaces for potential move is empty
    void print(); //Debugging purposes

  private:
    class Car{
      Car();

      carArr[10]; //Holds car objects
      int carNum;
      int size;
      int dir;
      int row;
      int col;
    }

    int numMoves;
    int bestMoves;
    int maxMoves;
    bool solved;
    int boardArr[7][7];
    //int carArr[5][5];
};
