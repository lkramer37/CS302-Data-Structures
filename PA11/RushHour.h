/**
@file RushHour.h
@author Terra Williams
@author Natalie Arnold
@author Leah Kramer
@date 12/05/2017
*/

#include<map>
#include<queue>
#include<iostream>
#include<string>
using namespace std;

#define MAXCARS 18
#define MAXROWS 6
#define MAXCOLS 6

class Car
{
	public:
		Car();
		void setCar(const int size, const char facing, const int row_p,
				    const int col_p);
		int getLength() const;
		int getRow() const;
		int getCol() const;
		char getOrient() const;
		void setRow(const int newRow);
		void setCol(const int newCol);

		int row;
		int col;
		int length;
		char orientation;
};

class Rushhour
{
	public:
		Rushhour();
		
		void solveIt();
		bool didWeWin() const;
		
		void fillGameBoard();
		void printBoard() const; //testing purposes
		void clearBoard();
		void fixCarList();
		
		bool moveForward(const int index);
		bool moveBackward(const int numCar);

		int getBest() const;
		bool getSolved() const;
		void setNumberOfCars(const int cars);
		int getNumberOfCars() const;
		
		void addQueue();
		bool queueEmpty();
		
		void readData();

	private:
		string key;
		map<string,int> check;
		pair<map<string,int>::iterator, bool> found;
		pair<string,int> current;
		queue<pair<string,int> > boards;
		Car carsOnBoard [MAXCARS];
		int gameBoard [MAXROWS][MAXCOLS];
		int numberOfCars;
		int best;
		bool solved;
};
