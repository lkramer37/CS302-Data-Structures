#include <stdexcept>
#include <iostream>

using namespace std;

#include "QueueLinked.h"

//--------------------------------------------
//
//---------------------------------------------

//class QueueLinked : public Queue<DataType> {
template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
  //Constructor. Creates an empty queue. Allocates enough memory for the queue containing maxNumber data items (if necessary). Note: constructors are actually declared and implemented in the derived classes, not in the base class.
  front = NULL;
  back = NULL;
  //front = new QueueNode("empty", NULL);

}
template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
  //Copy Constructor. Initializes the queue to be equivalent to the other Queue OBJECT parameter. Note: declared and implemented in the derived class.

  QueueNode* otherPtr = other;
  QueueNode* newNode = new QueueNode(other);
  front = newNode;
  for(int i=0; i<other.getLength(); ++i)
  {
    newNode->next = new QueueNode(otherPtr->next);
    otherPtr = otherPtr->next;
  }
  newNode->next = NULL;
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked<DataType>& other)
{
  //Overloaded assignment operator. Sets the queue to be equivalent to the other Queue OBJECT parameter and returns a reference to the modified queue. Note: declared and implemented in the direved classes with corresponding name changes.

}
template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
  //Destructor. Deallocates (frees) the memory used to store the queue.
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
  //Requirement: Queue is not full.
  if(isFull()){
    throw logic_error("enqueue() queue full");
  }
  //Inserts newDataItem at the rear of the queue

    if(isEmpty()){ //If the queue is empty
      front = new QueueNode(newDataItem, NULL);
      back = front;
      return;
    }
    if(!isEmpty()){ //If the queue is not empty
      back->next = new QueueNode(newDataItem, NULL);
      back = back->next;
      return;
    }

}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
  //Requirements: Queue is not empty
  if(isEmpty()){
    throw logic_error("dequeue() queue empty");
  }
  //Removes the least recently added (front) data item from the queue and returns it.
  QueueNode* temp = front;
  front = front -> next;
  DataType dequeueItem = temp->dataItem;
  delete temp;
  //temp = nullptr;
  return dequeueItem;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
  //Removes all the data items in the queue
  while(front != back){
    QueueNode* temp = front;
    front = front->next;
    delete temp;
    //temp = nullptr;
  }
  QueueNode* temp = front;
  delete temp;
  //temp = nullptr;
}
template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
  //Returns true if the queue is empty. Otherwise, returns false
  if(front==NULL){
    return true;
  }
  return false; //Temporary for compilation
}
template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
  //Returns true if the queue is full. Otherwise, returns false
  return false;
}

// Programming Exercise 2
template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
  //Requirements: Queue is not full
  if(isFull())
  {
    throw logic_error("putFront() queue full");
  }
  //Inserts newDataItem at the front of the queue. The order of the preexisting data items is left unchanged.
  QueueNode* newNode = new QueueNode(newDataItem, front);
  front = newNode;
  newNode = NULL;
  delete newNode;
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
  //Requirements: Queue is not empty
  if (isEmpty()){
    throw logic_error("getRear() queue empty");
  }
  //Removes the most recently added (rear) data item from the queue and returns it. The remainder of the queue is left unchanged.

  if(front == back){ //if there is only one node
    QueueNode* temp = back; //temp node pointer set to the back node
    front = NULL;
    back = NULL;
    DataType removedItem = temp->dataItem;
    delete temp;
    //temp = nullptr;
    return removedItem;
  }

  QueueNode* temp = back; //temp node pointer to back
  back = front; //set back to front
  for(int i=2; i<getLength(); ++i)
  {
    back = back->next;
    cout << "Test length: " << getLength() << endl;
  }
  DataType removedItem = temp->dataItem;
  delete temp;
  temp = NULL;
  back->next = NULL;
  cout << "Test Front: " << front->dataItem << endl;
  cout << "Test Back: " << back->dataItem << endl;
  return removedItem;
}

// Programming Exercise 3
template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
  //Returns the number of data items in a queue
  if(isEmpty())
  {
    return 0;
  }
  int count = 1;
  QueueNode* countPtr = front;
  while(countPtr->next != NULL)
  {
      ++count;
      countPtr = countPtr->next;
      //cout << "Length Function: " << count << endl;
  }
  countPtr = NULL;
  return count;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
  QueueNode* p;

    if ( isEmpty() )
  cout << "Empty queue" << endl;
    else
    {
  cout << "Front\t";
  for ( p = front ; p != NULL ; p = p->next )
  {
      if( p == front )
      {
    cout << '[' << p->dataItem << "] ";
      }
      else
      {
    cout << p->dataItem << " ";
      }
  }
  cout << "\trear" << endl;
    }
}
template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
  dataItem = nodeData;
  next = nextPtr;
}
