#include <iostream>
#include <fstream>

using namespace std;

//*! This program takes input of rxc dimensions and counts the amount of p's in a group and the number of groups within those dimensions*/
class Garden{
  public:
    // Default Constructor - Creates a 40x40 array and sets each element to 'x'. 
    // Creates an array to hold the values for patch sizes. 
    // Initializes the number of patches to 0.
    Garden();

    //Reads from terminal into gardenArray
    void readIn(int r, int c);
    
    //Uses dimension parameters to locate the number of patches in gardenArray.
    int countPatches(int row, int col);
    
    //Calls the sort function, then prints the patchSize values to the terminal
    void printPatchArray();
    
    //Sorts patchArray from smallest to largest
    void sortPatchArray();
    
    //finds a patch and returns it's size
    int findPatch(int r, int c, int row, int col, int &size);
    //!printGarden Function - Used for debugging
    void printGarden();
    //!clear Function - Clears gardenArray, patchArray, and resets patchCnt to zero
    void clear();

  private:
    char gardenArray[40][40]; //!<Holds characters
    int patchArray[400]; //!<Holds patch sizes from garden
    int patchCnt; //!<Number of patches in garden
};

Garden::Garden()
{
  for(int i=0; i<40; i++){
    for(int j=0; j<40; j++){
      gardenArray[i][j] = 'x';
    }
  }
  for(int i=0; i<400; i++){
    patchArray[i]=0;
  }
  patchCnt = 0;
}

int Garden::findPatch(int r, int c, int row, int col, int &size)
{
  if(gardenArray[r][c] == 'p')
  {
    size++;
    gardenArray[r][c] = 'C';
    if ((c+1)<col)
    {
      findPatch(r, c+1, row, col, size);
    }
    if ((r+1)<row)
    {
      findPatch(r+1, c, row, col, size);
    }
    if (r>0)
    {
      findPatch(r-1, c, row, col, size);
    }
    if (c>0)
    {
      findPatch(r, c-1, row, col, size);
    }
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
      if(size>0)
      {
        patchArray[patchCnt] = size;
        patchCnt++;
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

void Garden::clear()
{
  for(int i=0; i<40; i++){
    for(int j=0; j<40; j++){
      gardenArray[i][j] = 'x';
    }
  }
  for(int i=0; i<400; i++){
    patchArray[i]=0;
  }
  patchCnt = 0;
}

void Garden::printPatchArray()
{
  sortPatchArray();
  for(int i=0; i<=patchCnt; i++){
    if (patchArray[i] != 0){
      cout << " " << patchArray[i];
    }
  }
}

void Garden::sortPatchArray()
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
  for (int i=0; i<10; i++)
  {
    for (int j=0; j<10; j++)
    {
      cout << gardenArray[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int gardenNum=0, row=0, col=0;
  
  //Read in dimensions
  cout << "Number of rows: ";
  cin >> row;
  cout << "Number of columns: ";
  cin >> col; 

  cout << "Paste Garden Pattern: ";
  
  Garden gardenObject; //Creates Garden Object
  while ((row != 0) || (col != 0)) //While dimensions aren’t 0
  {
    gardenObject.clear();//clears gardenObject
    gardenNum++; //Tracks garden number
    gardenObject.readIn(row,col);//Read into Garden array
    cout << "Garden # " << gardenNum << ": ";
    cout <<  gardenObject.countPatches(row, col) << " patches, ";
    cout << "sizes:";
    gardenObject.printPatchArray();
    cout << endl;
    cin >> row >> col;
  }
  return 0;
}
