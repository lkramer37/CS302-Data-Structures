#include <iostream>
#include <stdexcept>
#include "PriorityQueue.h"

using namespace std;

/**
 @brief Constructor
 @param maxNumber Maximum queue size
 @post Creates an empty priority queue. Allocates enough memory for a queue containing maxNumber data items
 */
template < typename DataType, typename KeyType, typename Comparator>
PriorityQueue<DataType, KeyType, Comparator> :: PriorityQueue (int maxNumber): Heap<DataType> (maxNumber)
{

};

/**
 @brief Enqueue
 @param newDataItem Address of item to be entered into the queue
 @pre Queue is not full
 @post Inserts newDataItem into the priority queue
 @exception <exception-object> {exception description}
 @see {Reference}
 */
template < typename DataType, typename KeyType, typename Comparator>
void PriorityQueue<DataType, KeyType, Comparator> :: enqueue (const DataType& newDataItem)
{
    Heap<DataType>::insert(newDataItem);
};

/**
 @brief Dequeue
 @pre Queue is not empty
 @post Removes the highest priority (front) data item from the priority queue and returns it
 @exception <exception-object> {exception description}
 @return The front item that is removed from the queue
 */
template < typename DataType, typename KeyType, typename Comparator>
DataType PriorityQueue<DataType, KeyType, Comparator> :: dequeue()
{
    return Heap<DataType>::remove();
};
