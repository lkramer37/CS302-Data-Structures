#ifndef GARDEN_H
#define GARDEN_H

#include <iostream>
using namespace std;

class Garden{
  public:
    Garden();
    //Garden(const int &other);

    void readIn(int r, int c); //Reads into gardenArray, needs dimensions
    int countPatches(int row, int col);

    void printPatchArray(); // Call sort, then array print loop
    void sortPatchArray(); //sorts patchArray from smallest to largest
    int findPatch(int r, int c, int row, int col, int &size); //finds a patch and returns it's size
    void printGarden(); //Used for debugging
    void clear(); //Clears gardenArray, patchArray, and resets patchCnt to zero


  private:
    char gardenArray[40][40]; //Holds characters
    int patchArray[400]; // Holds patch sizes from garden
    int patchCnt; //Number of patches in garden


};

#endif
