#include <iostream>
#include <stdio.h>
#include <fstream>
#include "garden.h"

using namespace std;

Garden::Garden()
{
  for(int i=0; i<40; i++){ //sets all values to x
    for(int j=0; j<40; j++){
      gardenArray[i][j] = 'x';
    }
  }
  for(int i=0; i<400; i++){
    patchArray[i]=0;
  }
  //patchArray[400] = {0}; // Holds patch sizes from garden
  patchCnt = 0; //Number of patches in garden
}

int Garden::findPatch(int r, int c, int row, int col, int &size)
{
  //cout << endl << "r: " << r << "  c: " << c << endl;
  //cout << "size: " << size << endl;
  //cout << "element: " << gardenArray[r][c] << endl;

  if(gardenArray[r][c] == 'p')
  {
    size++;
    gardenArray[r][c] = 'C';
    //printGarden();

    if ((c+1)<col)
    {
      //cout << "Check Right";
      findPatch(r, c+1, row, col, size);
    }
    if ((r+1)<row)
    {
      //cout << "Check Below";
      findPatch(r+1, c, row, col, size);
    }
    if (r>0)
    {
      //cout << "Check Above";
      findPatch(r-1, c, row, col, size);
    }
    if (c>0)
    {
      //cout << "Check Left";
      findPatch(r, c-1, row, col, size);
    }
    //cout << "  size: " << size <<endl;
  }
  return size;
}

int Garden::countPatches(int row, int col)
{
  patchCnt = 0;
  for(int r=0; r<row; r++)
  {
    for(int c=0; c<col; c++)
    {
      int size=0;
      size = findPatch(r,c,row, col, size);
      //cout << "Test Size: " << size << endl;
      if(size>0)
      {
        patchArray[patchCnt] = size;
        patchCnt++;
//TEST//
/*
cout << "PatchCnt: " << patchCnt << endl;
for(int i=0; i<patchCnt+5; i++){
    cout << patchArray[i] << " ";
  }
cout << endl;
*/
        size = 0;
      }
    }
  }
  return patchCnt;
}

void Garden::readIn(int r, int c)
{
  for (int i=0; i<r; i++)
  {
    getchar();
    for (int j=0; j<c; j++)
    {
      gardenArray[i][j]=getchar();
    }
  }
}

void Garden::clear() //Clears gardenArray, patchArray, and resets patchCnt to zero
{
  for(int i=0; i<40; i++){ //sets all values to x
    for(int j=0; j<40; j++){
      gardenArray[i][j] = 'x';
    }
  }
  for(int i=0; i<400; i++){
    patchArray[i]=0;
  }

  //patchArray[800] = {0}; // Holds patch sizes from garden
  patchCnt = 0; //Number of patches in garden
}

void Garden::printPatchArray() // Call sort, then array print loop
{
  sortPatchArray();
  //cout << "Test print array, patchCnt" << patchCnt << endl;
  for(int i=0; i<=patchCnt; i++){
    if (patchArray[i] != 0){
      cout << patchArray[i] << " ";
    }
  }
}

void Garden::sortPatchArray() //sorts patchArray from smallest to largest
{
  for(int i=0; i<400; i++)
  {
    for(int j=0; j<patchCnt; j++){
      if (patchArray[j]>patchArray[j+1])
      {
        int temp = patchArray[j];
        patchArray[j]=patchArray[j+1];
        patchArray[j+1]=temp;
      }
    }
  }
}

void Garden::printGarden()
{
  //cout << "GARDEN ARRAY " << endl;
  for (int i=0; i<10; i++)
  {
    for (int j=0; j<10; j++)
    {
      cout << gardenArray[i][j] << " ";
    }
    cout << endl;
  }
}
