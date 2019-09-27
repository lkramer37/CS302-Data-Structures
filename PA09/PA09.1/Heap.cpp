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
    //Copy the item from the last node and place it into the root
    //items[0] = dataItems[itemCount-1];

    //Remove the last node
    //itemCount --;

    //converts a semiheap rooted at index root into a heap
    //heapRebuild (root: integer, items: ArrayType, itemCount: integer);

    //Recursively trickle the item at index root down to its proper position by swapping it with its larger child, if the childe is larger than the item.
    //If the item is at a leaf, nothing needs to be done.

    //if the root is not a leaf
        //largerChildIndex = 2 * rootIndex + 1 //Left child index

        //if the root has a right child
            //rightChild = largerChildIndex + 1
};

/**
 @brief Clear
 @post Removes all the data items in the heap
 @see {references}
 */
template < typename DataType, typename KeyType, typename Comparator >
void Heap <DataType, KeyType, Comparator> :: clear()
{

};

/**
 @brief Empty Check
 @return True if heap is empty. Otherwise, returns false.
 */
template < typename DataType, typename KeyType, typename Comparator >
bool Heap <DataType, KeyType, Comparator> :: isEmpty() const
{

};

/**
 @brief Full Check
 @return True if heap is full. Otherwise, returns false.
 */
template < typename DataType, typename KeyType, typename Comparator >
bool Heap <DataType, KeyType, Comparator> :: isFull() const
{

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
