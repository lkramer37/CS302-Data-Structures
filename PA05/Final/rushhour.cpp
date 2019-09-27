#include <iostream>
#include "rushhour.h"

using namespace std;

int main()
{
  int scenario = 1;
  int carNum = 0, numCars = 0, carSize = 0, row=0, col = 0, cap = 10;
  char carDir = 0;

  cin >> numCars;

  while(numCars!=0)
  {
    carNum = 0;
    RushHour board;

    while(carNum<numCars)
    {
      cin >> carSize >> carDir >> row >> col;
      board.loadcars(carNum, carSize, carDir, row, col);
      board.loadBoard(carNum);
      carNum++;
    }
    //board.print();

    board.solveIt(numCars);

    if(board.solved)
    {
      cout << "Scenario " << scenario << " requires " << board.bestMoves << " moves" << endl;
    }

    cin >> numCars;
    ++scenario;
  }

}

/**
@brief <Recursive branch in bound tree search>
@param numCars - The amount of cars on the board
@ pre board is not empty
@ post Least amount of moves to solve board
@return void
*/
void RushHour::solveIt(int numCars)
{
  //Recursive function - "Branch in bound tree search"
  if(winCheck()) //stopping condition
  {
    if (numMoves < bestMoves) //variable to keep track of least amount of moves
    {
      bestMoves = numMoves;
    }
  }

  if (numMoves > maxMoves) //stopping condition
  {
    return;
  }

  for(int i=0; i<numCars; i++)
  {
    if(moveForward(i))
    {
      ++numMoves;
      solveIt(numCars); //increments move and calls function again
      moveBack(i); //undoing the move
      --numMoves; //undoing
    }
    if(moveBack(i))
    {
      ++numMoves;
      solveIt(numCars); //increments move and calls function again
      moveForward(i); //undoing the move
      --numMoves; //undooing
    }
  }
}

/**
@brief <moves car object forward one space>
@param carNum
@ pre Car Object is already on the board
@ post Car Object has been move one incremental space
@return True if car was succesfully moved
*/
bool RushHour::moveForward(int carNum) //increasing direction
{
  const int startRow = carArr[carNum].getRow();
  const int startCol = carArr[carNum].getCol();
  int testRow = carArr[carNum].getRow();
  int testCol = carArr[carNum].getCol();

  if((carArr[carNum].getDir() == 72) || (carArr[carNum].getDir() == 104)) //if horizontal
  {
    for(int i =0; i<(carArr[carNum].getSize()); i++){++testCol;}
    if((boardArr[testRow][testCol] == -1)&&(testCol<6)&&(testRow<6))
    {
      boardArr[testRow][testCol] = carNum;
      boardArr[startRow][startCol] = -1;
      int newCol = startCol + 1;
      carArr[carNum].setCol(newCol);
      return true;
    }
  }

  if((carArr[carNum].getDir() == 86) || (carArr[carNum].getDir() == 118)) //if vertical
  {
    for(int i =0; i<(carArr[carNum].getSize()); i++) {++testRow; }
    if((boardArr[testRow][testCol] == -1)&&(testCol<6)&&(testRow<6))
    {
      boardArr[testRow][testCol] = carNum;
      boardArr[startRow][startCol] = -1;
      carArr[carNum].setRow(startRow+1);
      return true;
    }
  }
  return false;
}

/**
@brief <moves car object back one space>
@param carNum
@ pre Car Object is already on the board
@ post Car Object has been moved one decremental space
@return True if car was succesfully moved
*/
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
      return true;
    }
  }

  if((carArr[carNum].getDir() == 86) || (carArr[carNum].getDir() == 118)) //if vertical
  {
    if(boardArr[r-1][c] == -1)
    {
      boardArr[--r][c] = carNum;
      boardArr[r+carArr[carNum].getSize()][c] = -1;
      carArr[carNum].setRow(r);
      return true;
    }
  }
  return false;
}

/**
@brief <Checks if board has been solved>

@param None
@ pre board Object exists
@ post board columns have been checked for the 0th car
@return True if 0 is found in the last column
*/
bool RushHour::winCheck() //check if car 0 is at the east edge
{
  for(int i=0; i<6; i++)
  {
    if (boardArr[i][5] == 0)
    {
      solved = true;
      return true;
    }
  }
  return false;
}

/**
@brief <puts car object on the board>
@param carNum
@ pre board object exists
@ post car is placed on board
@return None
*/
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

/**
@brief <Prints Board to terminal>
@brief <Only used for debugging purposes>
@ pre board object exists
@ post Contents of boardArr are printed to terminal
@return None
*/
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

/**
@brief <Default Constructor>
@param None
@ pre Car class onbject is created
@ post Car class object is initialized
@return None
*/
Car::Car() //Default constructor
{
  int carNum = 0;
  int size = 0;
  char dir = 0;
  int row = 6;
  int col = 6;
}

/**
@brief <Creates Car class objects>
@param carNum
@param carSize
@param carDir
@param row
@param col
@ pre User has put info into terminal
@ post Car object is initialized
@return None
*/
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

/**
@brief <Default Constructor>
@param None
@ pre RushHour class object is created
@ post RushHour class object members are initialized
@return None
*/
RushHour::RushHour()
{
  numMoves = 0;
  bestMoves = 11;
  maxMoves = 10;
  solved = false;

  for(int i=0; i<6; i++)
  {
    for(int j=0; j<6; j++)
    {
      boardArr[j][i]=-1;
    }
  }
}

/**
@brief <Gets the value of private member carNum>
@param None
@ pre Car class object exists
@ post Car class object's carNum member value is returned for use
@return value of carNum member
*/
int Car::getNum()
{
  return carNum;
}

/**
@brief <Gets the value of private member size>
@param None
@ pre Car class object exists
@ post Car class object's size member value is returned for use
@return value of size member
*/
int Car::getSize()
{
  return size;
}

/**
@brief <Gets the value of private member dir>
@param None
@ pre Car class object exists
@ post Car class object's dir member value is returned for use
@return value of dir member
*/
int Car::getDir()
{
  return dir;
}

/**
@brief <Gets the value of private member row>
@param None
@ pre Car class object exists
@ post Car class object's row member value is returned for use
@return value of row member
*/
int Car::getRow()
{
  return row;
}

/**
@brief <Gets the value of private member col>
@param None
@ pre Car class object exists
@ post Car class object's col member value is returned for use
@return value of col member
*/
int Car::getCol()
{
  return col;
}

/**
@brief <Sets private member carNum in Car class>
@param Index integer
@ pre Car class object exists
@ post Car class objects carNum member is set to passed parameter
@return None
*/
void Car::setNum(int car){
  carNum = car;
}

/**
@brief <Sets private member size in Car class>
@param size integer
@ pre Car class object exists
@ post Car class objects size member is set to passed parameter
@return None
*/
void Car::setSize(int s)
{
  size = s;
}

/**
@brief <Sets private member dir in Car class>
@param direction character
@ pre Car class object exists
@ post Car class objects dir member is set to passed parameter
@return None
*/
void Car::setDir(char d)
{
  dir = d;
}

/**
@brief <Sets private member row in Car class>
@param row integer
@ pre Car class object exists
@ post Car class objects row member is set to passed parameter
@return None
*/
void Car::setRow(int r)
{
  row = r;
}

/**
@brief <Sets private member col in Car class>
@param column integer
@ pre Car class object exists
@ post Car class objects col member is set to passed parameter
@return None
*/
void Car::setCol(int c)
{
  col = c;
}

/**
@brief <Prints Car Object details to the terminal>
@brief <For debugging purposes only>
@param carNum
@ pre Car object exists
@ post None
@return None
*/
void RushHour::printCar(int carNum)
{
  cout << "Car Object Test" << endl;
  cout << "Car #" << carArr[carNum].getNum() << endl;
  cout << carArr[carNum].getSize() << " ";
  cout << carArr[carNum].getDir() << " ";
  cout << carArr[carNum].getRow() << " ";
  cout << carArr[carNum].getCol() << " ";
}
