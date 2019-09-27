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
    //Create Car objects
    board.loadcars(carNum, carSize, carDir, row, col);
    board.loadBoard(carNum);
    board.print();
    carNum++;
  }

  cout << "Test MoveForward" << endl;
  //board.moveForward(4);
  board.moveForward(7);
  board.moveForward(7);
  board.moveBack(6);
  board.moveBack(6);
  board.print();

  board.printCar(0);
  board.printCar(1);
  board.printCar(2);
  board.printCar(3);
  board.printCar(4);
  board.printCar(5);
  board.printCar(6);
  board.printCar(7);

  //solve(numCars);
  //Solve_It(0, …);
}

bool RushHour::moveForward(int carNum) //increasing direction
{
  const int startRow = carArr[carNum].getRow();
  const int startCol = carArr[carNum].getCol();
  int testRow = carArr[carNum].getRow();
  int testCol = carArr[carNum].getCol();

  if((carArr[carNum].getDir() == 72) || (carArr[carNum].getDir() == 104)) //if horizontal
  {
    for(int i =0; i<(carArr[carNum].getSize()); i++){++testCol;}
    if((boardArr[testRow][testCol] = -1)&&(testCol<6)&&(testRow<6))
    {
      boardArr[testRow][testCol] = carNum;
      boardArr[startRow][startCol] = -1;
      int newCol = startCol + 1;
      cout << "Test newCol: " << newCol << endl;
      carArr[carNum].setCol(newCol);
      cout << "Test Col: " << carArr[carNum].getCol() << endl;
      return true;
    }
  }

  if((carArr[carNum].getDir() == 86) || (carArr[carNum].getDir() == 118)) //if vertical
  {
    for(int i =0; i<(carArr[carNum].getSize()); i++) {++testRow; }
    if((boardArr[testRow][testCol] = -1)&&(testCol<6)&&(testRow<6))
    {
      boardArr[testRow][testCol] = carNum;
      boardArr[startRow][startCol] = -1;
      carArr[carNum].setRow(startRow+1);
      return true;
    }
  }
  return false;
}

bool RushHour::moveBack(int carNum) //decreasing direction
{
  int c = carArr[carNum].getCol();
  int r = carArr[carNum].getRow();

  if((carArr[carNum].getDir() == 72) || (carArr[carNum].getDir() == 104)) //if horizontal
  {
    if(boardArr[r][c-1] == -1)
    {
      boardArr[r][--c] = carNum;
      boardArr[r][c+carArr[carNum].getSize()] = -1;
      carArr[carNum].setCol(c);
    }
  }

  if((carArr[carNum].getDir() == 86) || (carArr[carNum].getDir() == 118)) //if vertical
  {
    if(boardArr[r-1][c] == -1)
    {
      boardArr[--r][c] = carNum;
      boardArr[r+carArr[carNum].getSize()][c] = -1;
      carArr[carNum].setRow(r);
    }
  }
}

bool RushHour::winCheck() //check if car 0 is at the east edge
{
  if(carArr[0].getCol() == 5)
  {
    solved = true;
    return true;
  }
  return false;
}

void RushHour::solve(int numCars)
{
  //Recursive function - "Branch in bound tree search"
  if(winCheck()) //stopping condition
  {
    if (numMoves < bestMoves) //variable to keep track of least amount of moves
    {
      maxMoves>=numMoves;
      solved = true;
    }
    if (numMoves > maxMoves) //stopping condition
    {
      return;
    }
  }

  for(int i=0; i<numCars; i++)
  {
    if(moveForward(i))
    {
      solve(numCars); //increments move and calls function again
      moveBack(i); //undoing the move
    }
    if(moveBack(i))
    {
      solve(numCars); //increments move and calls function again
      moveForward(i); //undoing the move
    }
  }
}

void RushHour::loadBoard(int carNum)
{
  int row = carArr[carNum].getRow();
  int col = carArr[carNum].getCol();
  int i=0;

  if((carArr[carNum].dir == 'H') || (carArr[carNum].dir == 'h')) //if horizontal H=72, h=104
  {
    while(i<(carArr[carNum].size)){
      boardArr[row][col]=carNum;
      col++;
      i++;
    }
  }

  if((carArr[carNum].dir == 'V') || (carArr[carNum].dir == 'v')) //if vertical V=86, v=118
  {
    while(i<(carArr[carNum].size)){
      boardArr[row][col]=carNum;
      row++;
      i++;
    }
  }
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

Car::Car() //Default constructor
{
  int carNum = 0;
  int size = 0;
  char dir = 0;
  int row = 6;
  int col = 6;
}

void RushHour::loadcars(int carNum, int carSize, char carDir, int row, int col)
{
  Car carObject;
  carObject.carNum = carNum;
  carObject.size = carSize;
  carObject.dir = carDir;
  carObject.row = row;
  carObject.col = col;
  carArr[carNum] = carObject;
}

RushHour::RushHour()
{
  numMoves = 0;
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

int Car::getNum()
{
  return carNum;
}
int Car::getSize()
{
  return size;
}
int Car::getDir()
{
  return dir;
}
int Car::getRow()
{
  return row;
}
int Car::getCol()
{
  return col;
}

void Car::setNum(int carNum){
  carNum = carNum;
}
void Car::setSize(int size)
{
  size = size;
}
void Car::setDir(char dir)
{
  dir = dir;
}
void Car::setRow(int row)
{
  row = row;
}
void Car::setCol(int col)
{
  col = col;
}

void RushHour::printCar(int carNum)
{
  cout << "Car Object Test" << endl;
  cout << "Car #" << carArr[carNum].getNum() << endl;
  cout << carArr[carNum].getSize() << " ";
  cout << carArr[carNum].getDir() << " ";
  cout << carArr[carNum].getRow() << " ";
  cout << carArr[carNum].getCol() << " ";
}
