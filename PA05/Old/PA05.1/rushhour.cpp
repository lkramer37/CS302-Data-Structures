#include <iostream>
#include "rushhour.h"

using namespace std;

int main()
{
  //int bestMoves = -1; //Sets it to a bad number. Might not need this.
  int cap = 10;
  int carNum = 0, numCars = 0, carSize = 0, row=0, col = 0;
  char carDir = 0;
  //Solved = false;
  RushHour board;

  board.print(); //Test board initialization
  //LOAD BOARD from terminal input
  cin >> numCars;
  cout << "test numCars: " << numCars << endl;
  while(carNum<numCars)
  {
    cin >> carSize >> carDir >> row >> col;
    cout << "carNum: " << carNum << endl;
    cout << "carSize: " << carSize << endl;
    cout << "carDir: " << carDir << endl;
    cout << "row: " << row << endl;
    cout << "col: " << col << endl;
    board.loadBoard(carNum, carSize, carDir, row, col);
    board.print();
    carNum++;
  }
  //Setup stuff
  //Solve_It(0, …);
}

void RushHour::loadBoard(int carNum, int carSize, char carDir, int row, int col)
{
  //Check if spot is available

  if (!empty(row, col, carSize, carDir))
  {
    cout << "Space is not empty" << endl;
    print();
    return;
  }

  int i=0;

  if((carDir == 'H') || (carDir == 'h')) //if horizontal H=72, h=104
  {

  }

  if((carDir == 'V') || (carDir == 'v')) //if vertical V=86, v=118
  {
    cout << "TEST" << endl;
    while(i<carSize){
      boardArr[row][col]=carNum;
      //print();
      row++;
      i++;
    }
  }
  cout << "Car #" << carNum << " has been placed on the board" << endl;
  //print();
}

RushHour::RushHour()
{
  //numMoves = 11;
  bestMoves = -1;
  maxMoves = 10;
  solved = false;

  for(int i=0; i<6; i++)
  {
    cout << " "; //To appease the compiler warning gods
    for(int j=0; j<6; j++)
    {
      boardArr[j][i]=-1;
    }
  }
  cout << endl;
}

bool RushHour::moveForward(int carNum){ }

bool RushHour::moveBack(int carNum){ }

bool RushHour::winCheck(){ }//check if car 0 is at the east edge

void RushHour::solve( int numMoves, int numCars)
{
  //Recursive function - "Branch in bound tree search"
  //Use array - two data structures that you keep in concert
  //6x6 Board Array
  //6x6 Car - Array
  //c/t
  //pos x, y
  //direction (up/dn)
  //direction (left/right)
  if(winCheck()) //stopping condition
  {
    if (numMoves < bestMoves) //variable to keep track of lease amount of moves
    {
      maxMoves>=numMoves;
      solved = true;
      //return ?
    }
    if (numMoves > maxMoves) //stopping condition
    {
      //return …
    }
  }

  for(int i=0; i<numCars; i++)
  {
    if(moveForward(i))
    {
      solve(numMoves++, numCars); //increments move and calls function again
      moveBack(i); //undoing the move
    }
    if(moveBack(i))
    {
      solve(numMoves++, numCars); //increments move and calls function again
      moveForward(i); //undoing the move
    }
  }
}

bool RushHour::empty(int row, int col, int carSize, char carDir)
{
  //Returns true if space is empty
  for(int i =0; i<carSize; i++)
  {
    if(boardArr[row][col] != -1){return false;}
    if((carDir == 72) || (carDir == 104)) {++col;} //if horizontal
    if((carDir == 86) || (carDir == 118)) {++row;} //if vertical
  }
  return true;
}

void RushHour::print()
{
  for(int i=0; i<6; i++)
  {
    cout << endl;
    for(int j=0; j<6; j++)
    {
      cout << boardArr[i][j] << "\t";
    }
  }
  cout << endl << endl;
}
