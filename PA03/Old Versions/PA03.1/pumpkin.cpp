#include <iostream>
#include <fstream>
#include "garden.cpp"

using namespace std;

int main()
{
  int gardenNum=0, row=0, col=0; //Garden number
  cin >> row >> col; //Read in dimensions
  Garden gardenObject; //Creates Garden Object
  while ((row != 0) || (col != 0)) //While dimension aren’t 0
  {
    gardenObject.clear();//clears gardenObject
    gardenNum++; //Tracks garden number
    cout << "Garden Number: " << gardenNum << endl;
    gardenObject.readIn(row,col);//Read into Garden array
    cout << "Garden # " << gardenNum << ": ";
    cout <<  gardenObject.countPatches(row, col) << " patches, ";
    cout << "sizes: ";
    gardenObject.printPatchArray();
    cout << endl;
    cin >> row >> col;
  }
  return 0;
}
