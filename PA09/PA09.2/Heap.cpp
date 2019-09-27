//Heap.cpp

#include <iostream>
#include "Heap.h"

using namespace std;

/**
 @brief Default and Basic Constructor
 @param maxNumber Maximum heap size
 @post Creates an empty heap. Allocates enough memory for a heap containing maxNumber data items
 */
template < typename DataType, typename KeyType, typename Comparator >
Heap <DataType, KeyType, Comparator> :: Heap (int maxNumber)
{
    dataItems = new DataType[maxNumber];
    size = 0;
    maxSize = maxNumber;
};

/**
 @brief Copy constructor
 @param other Address to the heap to be copied
 @post Initializes the object to be an equivalent copy of other
 @see {references}
 */
template < typename DataType, typename KeyType, typename Comparator >
Heap <DataType, KeyType, Comparator> :: Heap ( const Heap& other )
{

};

/**
 @brief Overloaded Assignment Operator
 @param other Address to the heap to be copied
 @pre The address of this object cannot be the same as the address of other
 @post Sets the heap to be equivalent to the other Heap
 @return Reference to this object
 @see {references}
 */
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>& Heap <DataType, KeyType, Comparator> :: operator= ( const Heap& other )
{

};

/**
 @brief Destructor
 @post Deallocates the memory used to store the heap
 @see {References}
 */
template < typename DataType, typename KeyType, typename Comparator >
Heap <DataType, KeyType, Comparator> :: ~Heap()
{
    delete[] dataItems;
};

/**
 @brief Insert
 @param newDataItem Address of data item to be inserted
 @pre Heap is not full
 @post Inserts newDataItem into the heap.
 @exception <exception-object> {exception description}
 @note Inserts this data item as the bottom rightmost data item in the heap and moves it upward until the properties that define a heap are restored
 @see {references}
 */
template < typename DataType, typename KeyType, typename Comparator >
void Heap <DataType, KeyType, Comparator> :: insert (const DataType &newDataItem ) throw ( logic_error )
{
    if (isFull())
    {
        throw logic_error("Heap is Full");
    }

    if(!isFull())
    {
        ++size;
        dataItems[size-1] = newDataItem;
        trickleUp(size-1);
    }

};

template <typename DataType, typename KeyType, typename Comparator>
void Heap <DataType, KeyType, Comparator> :: trickleUp(int index)
{
    if (index != 0)
    {
        DataType temp;
        int parIndex;

        if(index>2) { parIndex = parentIndex(index); }
        else { parIndex = 0; }

        if (comparator(dataItems[index].getPriority(), dataItems[parIndex].getPriority()))
        {
            temp = dataItems[parIndex];
            dataItems[parIndex] = dataItems[index];
            dataItems[index] = temp;
            trickleUp(parIndex);
        }
    }
};

/**
 @brief Remove
 @pre Heap is not empty
 @post Removes the data item with the highest priority (the root) from the heap and returns it.
 @exception <exception-object> {exception description}
 @note Replaces the root data item with the bottom rightmost data item and moves this data item downward until the properties that define a heap are restored
 @return The root that is removed
 @see {references}
 */
template < typename DataType, typename KeyType, typename Comparator >
DataType Heap <DataType, KeyType, Comparator> :: remove () throw (logic_error)
{
    if (isEmpty())
    {
        throw logic_error("Heap is Empty");
    }

    //Copy the item from the last node and place it into the root
    dataItems[0] = dataItems[size-1];
    --size;
    trickleDown(0);
};

template < typename DataType, typename KeyType, typename Comparator >
void Heap <DataType, KeyType, Comparator> :: trickleDown( int index)
{
    int right, left, larger;
    right = rChildIndex(index);
    left = lChildIndex(index);


    //If there is either one or no children
    if (right >= size) //If right child doesn't exist
    {
        if (left >= size) { return; } //If left child doesn't exist, done
        else { larger = left; } //If only one child, this is the largest child
    }

    else //If 2 children exist, find larger child
    {
        if ( comparator(dataItems[left].getPriority(), dataItems[right].getPriority()))
        {
            larger = left;
        }
        else
        {
            larger = right;
        }
    }

    //If parent is smaller than larger child, swap
    if (comparator(dataItems[larger].getPriority(),dataItems[index].getPriority()))
    {
        DataType temp = dataItems[larger];
        dataItems[larger] = dataItems[index];
        dataItems[index] = temp;
        trickleDown(larger);
    }
};

/**
 @brief Clear
 @post Removes all the data items in the heap
 @see {references}
 */
template < typename DataType, typename KeyType, typename Comparator >
void Heap <DataType, KeyType, Comparator> :: clear()
{
    size = 0;
};

/**
 @brief Empty Check
 @return True if heap is empty. Otherwise, returns false.
 */
template < typename DataType, typename KeyType, typename Comparator >
bool Heap <DataType, KeyType, Comparator> :: isEmpty() const
{
    if (size == 0) { return true; }
    else { return false; }
};

/**
 @brief Full Check
 @return True if heap is full. Otherwise, returns false.
 */
template < typename DataType, typename KeyType, typename Comparator >
bool Heap <DataType, KeyType, Comparator> :: isFull() const
{
    if (size == maxSize) {return true;}
    return false;
};

/**
 @brief Show Structure
 @post Outputs the priorities of the data items in the heap in both array and tree form. The tree is output with its branches oriented from left (root) to right (leaves) - that is, the tree is output rotated counterclockwise ninety degrees from its conventional orientation. If the heap is empty, outputs "Empty Heap".
 @note Intended for testing/debugging purposes only
 */
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType,KeyType,Comparator>:: showStructure () const
{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
        cout << "Empty heap" << endl;
    else
    {
        cout << "size = " << size << endl;       // Output array form
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        for ( j = 0 ; j < size ; j++ )
            cout << dataItems[j].getPriority() << "\t";
        cout << endl << endl;
        showSubtree(0,0);                        // Output tree form
    }
};

/**
 @brief Output in level order
 @pre {description of the precondition}
 @post {description of the postcondition}
 @note {text }
 @see {Reference}
 */
template < typename DataType, typename KeyType, typename Comparator >
void Heap <DataType, KeyType, Comparator> :: writeLevels() const
{

};

/**
 @brief Show Structure Helper
 @param level The level of this data Items within the tree
 @post Helper function for the showStructure() function. Outputs the subtree (subheap) whose root is stored in dataItems[index].
 */
template < typename DataType, typename KeyType, typename Comparator >
void Heap <DataType, KeyType, Comparator> :: showSubtree (int index, int level) const
{
    int j;   // Loop counter

    if ( index < size )
    {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].getPriority();   // Output dataItems's priority
        if ( 2*index+2 < size )                // Output "connector"
            cout << "<";
        else if ( 2*index+1 < size )
            cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
};
