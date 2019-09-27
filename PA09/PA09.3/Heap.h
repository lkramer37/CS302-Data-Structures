//--------------------------------------------------------------------
//
//  Laboratory 12                                             Heap.h
//
//  Class declaration for the array implementation of the Heap ADataType
//
//--------------------------------------------------------------------

#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename KeyType=int >
class Less {
  public:
    bool operator()(const KeyType &a, const KeyType &b) const { return a < b; }
};

template < typename DataType, typename KeyType=int, typename Comparator=Less<KeyType> >
class Heap
{
  public:

    static const int DEFAULT_MAX_HEAP_SIZE = 10;    // Default maximum heap size

    // Constructor
    Heap ( int maxNumber = DEFAULT_MAX_HEAP_SIZE ); // Default constructor + basic constr
    Heap ( const Heap& other );		    // Copy constructor
    Heap& operator= ( const Heap& other );  // Overloaded assignment operator

    // Destructor
    ~Heap ();

    // Heap manipulation operations
    void insert ( const DataType &newDataItem ) throw ( logic_error );   // Insert a data item
    DataType remove () throw ( logic_error );  // Remove max priority element
    void clear ();                          // Clear heap

    // Heap status operations
    bool isEmpty () const;
    bool isFull () const;

    // Output the heap structure -- used in testing/debugging
    void showStructure () const;

    // Programming exercise #3 operation
    void writeLevels () const;              // Output in level order

  private:

    // Recursive helper of the showStructure() function
    void showSubtree ( int index, int level ) const;

    //void heapify(int index);
    void trickleUp(int index);
    void trickleDown(int index);
    int lChildIndex(int index) { return (2*index)+1; }
    int rChildIndex(int index) { return (2*index)+2; }
    int parentIndex(int index) { return (index-1)/2; }

    // Data members
    int maxSize,
        size;
    DataType *dataItems; // Array containing the heap elements

    Comparator comparator;
};

#endif	//#ifndef HEAP_H
