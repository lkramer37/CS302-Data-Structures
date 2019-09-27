/**
	*
	*@file rushhour.cpp
	*
	*@author Natalie Arnold, Terra Williams, Leah Kramer
	*
	*@brief Implementation of a functioning rushhour board and solver
	*
	*@details Implementation Rushhour class, Car class, and a program that takes
	*		  input from the user to set up a rushhour board, solves it, then
	*		  displays the number of moves required to solve it to the user.
	*		  The program constinues to do this until the user quits.
	*
	*@version 2.00
	*
	*@date December 5, 2017
	*
*/
//
////HEADER FILES////////////////////////////////////////////////////////////////
//
#include<iostream>
#include<map>
#include<queue>
#include <string>
#include "RushHour.h"
using namespace std;
//
////MACRO DEFINITIONS////////////////////////////////////////////////////////////
//

#define MAXROWS 6
#define MAXCOLS 6
#define MAXCARS 18
//
////MAIN FUNCTION///////////////////////////////////////////////////////////////
//

int main()
{
  Rushhour game;
  game.setNumberOfCars(-1);
  int scenario = 0;
  
  while(game.getNumberOfCars() != 0)
  {
    int numCars;
    cin >> numCars;
    game.setNumberOfCars(numCars);
    
    if(game.getNumberOfCars() != 0)
    {
      scenario++;
      
      game.readData();
      
      game.fillGameBoard();
      
      //game.printBoard();
      //cout << endl;
      
      game.addQueue();

      game.solveIt();
      
      if(game.getSolved())
        cout << "Scenario " << scenario << " requires " << game.getBest() + 1 << " moves" << endl;
      else
        cout << "not solved" << endl;
        
      game.clearBoard();
    }
  }

  return 0;
}

/**
@brief Car Class Constructor
@post Car object is instantiated
*/
Car::Car()
{
  row = 0;
  col = 0;
  length = 0;
  orientation = 'X';
}

/**
@brief setCar function sets the values of the car object
@param size Size of vehicle
@param facing Direction of vehicle
@param row_p Row location of vehicle
@param col_p Column location of vehicle
@post Car object values are initialized
*/
void Car::setCar(const int size, const char facing, const int row_p, const int col_p)
{
  row = row_p;
  col = col_p;
  length = size;
  orientation = facing;
}

/**
@brief Returns the length of the vehicle
@return length of vehicle
*/
int Car::getLength() const
{
  return length;
}

/**
@brief Returns row index value of the back of vehicle
@return Row index value of the back of vehicle
*/
int Car::getRow() const
{
  return row;
}

/**
@brief Returns column index value of the back of vehicle
@return Column index value of the back of vehicle
*/
int Car::getCol() const
{
  return col;
}

/**
@brief Returns the orientation of the vehicle
@return Orientation of the vehicle
*/
char Car::getOrient() const
{
  return orientation;
}

/**
@brief Sets the row value for car object
@param newRow int value to set car object's row value
@post row value for car object is set to newRow parameter
*/
void Car::setRow(const int newRow)
{
  row = newRow;
}

/**
@brief Sets the col value for car object
@param newCol int value to set car object's col value
@post col value for car object is set to newCol parameter
*/
void Car::setCol(const int newCol)
{
  col = newCol;
}

/**
@brief Rushhour() default constructor
@pre { description of the precondition }
@post Rushhour object is created
@note initializes the key
*/
Rushhour::Rushhour() : key(MAXROWS * MAXCOLS, '-')
{
  for(int i = 0; i < MAXROWS; i++)
  {
    for(int j = 0; j < MAXCOLS; j++)
    {
      gameBoard[i][j] = -1;
    }
  }
  
  numberOfCars = 0;
  best = -1;
  solved = false;
}

/**
@brief Solves the board to find the least amount of moves
@note Uses a breadth-first search to find the least amount of moves necessary to solve the board
*/
void Rushhour::solveIt()
{
  while(!solved)
  {
    current = boards.front();
    boards.pop();
    
    int k = 0;
    for(int i = 0; i < MAXROWS; i++)
    {
      for(int j = 0; j < MAXCOLS; j++)
      {
        if(current.first[k] == '-')
        {
          gameBoard[i][j] = -1;
        }
        else
        {
          gameBoard[i][j] = current.first[k] - 48;
        }
        k++;
      }
    }
    
    fixCarList();
    best = current.second;

    for(int i = 0; i < numberOfCars; i++)
    {
      if(moveForward(i))
      {
        if(didWeWin())
        {
          solved = true;
          return;
        }
        solved = didWeWin();
        addQueue();
        moveBackward(i);
      }
      if(moveBackward(i))
      {
        solved = didWeWin();
        addQueue();
        moveForward(i);
      }
    }
  }
  return;
}

/**
@brief Checks if board is in a winning position
@note Checks if board is in a winning board by searching last column for car 0
@return True if win condition. False otherwise.
*/
bool Rushhour::didWeWin() const
{
  for(int i = 0; i < MAXCOLS; i++)
  {
    if(gameBoard[i][MAXCOLS - 1] == 0)
    {
      return true;
    }
  }
  return false;
}

/**
@brief Places stored data from user onto the game board
@pre Board is empty
@post Board is filled
*/
void Rushhour::fillGameBoard()
{
  for(int i = 0; i < MAXROWS; i++)
  {
    for(int j = 0; j < MAXCOLS; j++)
    {
      gameBoard[i][j] = -1;
    }
  }
  
  for(int k = 0; k < numberOfCars; k++)
  {
    if(carsOnBoard[k].orientation == 'H')       //car placed horizontally
    {
      gameBoard[carsOnBoard[k].row][carsOnBoard[k].col] = k;
      gameBoard[carsOnBoard[k].row][carsOnBoard[k].col + 1] = k;
      
      if(carsOnBoard[k].length == 3)
        gameBoard[carsOnBoard[k].row][carsOnBoard[k].col + 2] = k;
    }
    else                                        //car placed vertically
    {
      gameBoard[carsOnBoard[k].row][carsOnBoard[k].col] = k;
      gameBoard[carsOnBoard[k].row + 1][carsOnBoard[k].col] = k;
      
      if(carsOnBoard[k].length == 3)
        gameBoard[carsOnBoard[k].row + 2][carsOnBoard[k].col] = k;
    }
  }
}

/**
@brief Prints board to screen
@post Board is printed to screen
*/
void Rushhour::printBoard() const //testing purposes
{
  for(int i = 0; i < MAXROWS; i++)
  {
    for(int j = 0; j < MAXCOLS; j++)
    {
      if(gameBoard[i][j] == -1)
        cout << '-' << " ";
      else
        cout << gameBoard[i][j] << " ";
    }
    cout << endl;
  }
}

/**
@brief Clears the queue of boards
@post Queue is empty
*/
void Rushhour:: clearBoard()
{
    for(int i = 0; i < MAXROWS; i++)
    {
        for(int j = 0; j < MAXCOLS; j++)
        {
            gameBoard[i][j] = -1;
        }
    }
    best = -1;
    check.clear();
    solved = false;
    while(!boards.empty())
    {
        boards.pop();
    }
}

/**
@brief Sets the Carlist to be the same as board that is popped off the queue
*/
void Rushhour::fixCarList()
{
  bool flag[numberOfCars] = {false};
  
  for(int i = 0; i < MAXROWS; i++)
  {
    for(int j = 0; j < MAXCOLS; j++)
    {
      if(gameBoard[i][j] != -1)
      {
        if(flag[gameBoard[i][j]] == false)
        {
          carsOnBoard[gameBoard[i][j]].row = i;
          carsOnBoard[gameBoard[i][j]].col = j;
          flag[gameBoard[i][j]] = true;
        }
      }
    }
  }
}

/**
@brief Moves the vehicle forward
@param index Index value of the back position of vehicle
@post vehicle is moved one space forward
@return True if successfully move. False otherwise.
*/
bool Rushhour::moveForward(const int index)
{
  if(carsOnBoard[index].orientation == 'H') //cars placed horizontally
  {
    if(gameBoard[carsOnBoard[index].row][carsOnBoard[index].col + carsOnBoard[index].length] == -1 and carsOnBoard[index].col + carsOnBoard[index].length < MAXCOLS)
    {
      gameBoard[carsOnBoard[index].row][carsOnBoard[index].col] = -1;
      
      carsOnBoard[index].col++;
      
      for(int i = 1; i < carsOnBoard[index].length; i++)
      {
        gameBoard[carsOnBoard[index].row][carsOnBoard[index].col + i] = index;
      }

      return true;
    } 
  }
  else //cars placed vertically
  {
    if(gameBoard[carsOnBoard[index].row + carsOnBoard[index].length][carsOnBoard[index].col] == -1 and carsOnBoard[index].row + carsOnBoard[index].length < MAXROWS)
    {
      gameBoard[carsOnBoard[index].row][carsOnBoard[index].col] = -1;
      
      carsOnBoard[index].row++;
      
      for(int i = 1; i < carsOnBoard[index].length; i++)
      {
        gameBoard[carsOnBoard[index].row + i][carsOnBoard[index].col] = index;
      }

      return true;
    }
  }
  
  return false;
}

/**
@brief Move the vehicle backward
@param numCar vehicle identification number
@post vehicle is moved one space backward
@return True if successfully move. False otherwise.
*/
bool Rushhour::moveBackward(const int numCar)
{
  if(carsOnBoard[numCar].orientation == 'H') //for cars placed horizontally
  {
    if(gameBoard[carsOnBoard[numCar].row][carsOnBoard[numCar].col - 1] == -1 and carsOnBoard[numCar].col > 0)
    {
      carsOnBoard[numCar].col--;
      
      gameBoard[carsOnBoard[numCar].row][carsOnBoard[numCar].col] = numCar;
      
      gameBoard[carsOnBoard[numCar].row][carsOnBoard[numCar].col + carsOnBoard[numCar].length] = -1;

      return true;
    }
  }
  else                                           //for cars placed vertically
  {
    if(gameBoard[carsOnBoard[numCar].row - 1][carsOnBoard[numCar].col] == -1 and carsOnBoard[numCar].row > 0)
    {
      carsOnBoard[numCar].row--;
      
      gameBoard[carsOnBoard[numCar].row][carsOnBoard[numCar].col] = numCar;
      
      gameBoard[carsOnBoard[numCar].row + carsOnBoard[numCar].length][carsOnBoard[numCar].col] = -1;

      return true;
    }
  }
  
  return false;
}

/**
@brief Returns best number of moves
@return Best number of moves
*/
int Rushhour::getBest() const
{
  return best;
}

/**
@brief Returns whether board has been solved
@return True if board is solved. False otherwise.
*/
bool Rushhour::getSolved() const
{
  return solved;
}

/**
@brief Sets the number of cars
@param cars int representing the amount of vehicles to be loaded onto the game board
@post numberOfCars variable is initialized
*/
void Rushhour::setNumberOfCars(const int cars)
{
  numberOfCars = cars;
}

/**
@brief Returns the value of numberOfCars
@return numberOfCars
*/
int Rushhour::getNumberOfCars() const
{
  return numberOfCars;
}

/**
@brief Adds board to the queue
@post Board has been added to the queue
@note The board is converted from a 2D array to a string for storage on the queue
*/
void Rushhour::addQueue()
{
  int k = 0;
  char c = '-';
  
  for(int i = 0; i < MAXROWS; i++)
  {
    for(int j = 0; j < MAXCOLS; j++)
    {
      if(gameBoard[i][j] == -1)
        key[k] = '-';
      else
        key[k] = gameBoard[i][j] + 48;
      
      k++;
    }
  }

  current.first = key;
  current.second = best + 1;
  found = check.insert(current);
  
  if(found.second)
  {
    boards.push(current);
  }
}

/**
@brief Checks if queue is empty
@return True if queue is empty, false otherwise.
*/
bool Rushhour::queueEmpty()
{
  if(boards.empty())
    return true;
  else
    return false;
}

/**
@brief Reads data entered by user
@post Data from terminal is stored
*/
void Rushhour::readData()
{
  for(int i = 0; i < numberOfCars; i++)
  {
    cin >> carsOnBoard[i].length;
    cin >> carsOnBoard[i].orientation;
    cin >> carsOnBoard[i].row;
    cin >> carsOnBoard[i].col;
  }
}
