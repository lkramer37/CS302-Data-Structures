// QueueLinked.h

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

///A Linked Queue Class derived from Queue Class
/*!
    "Creates and operates on a dynamic linked list of nodes"
*/

template <typename DataType>
class QueueLinked : public Queue<DataType> {
  public:
    ///Default Constructor
    /*!
    Creates an empty queue.
    */
    QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    
    ///Copy Constructor
    /*!
    Initializes the queue to be equivalent to the other Queue OBJECT parameter.
    */
    QueueLinked(const QueueLinked& other);
    
    ///Overloaded Assignment Operator
    /*!
    Sets the queue to be equivalent to the other Queue OBJECT parameter and returns a reference to the modified queue.
    */
    QueueLinked& operator=(const QueueLinked& other);
    
    ///Destructor
    /*!
    Deallocates (frees) the memory used to store the queue.
    */
    ~QueueLinked();

    ///enqueue Method
    /*! 
    Requirement: Queue is not full.
    Inserts newDataItem at the rear of the queue
    */
    void enqueue(const DataType& newDataItem) throw (logic_error);
    
    ///dequeue Method
    /*!
    Requirements: Queue is not empty
    Removes the least recently added (front) data item from the queue and returns it.
    */
    DataType dequeue() throw (logic_error);

    ///clear Method
    /*!
    Removes all the data items in the queue
    */
    void clear();

    ///isEmpty Method
    /*!
    Returns true if the queue is empty. Otherwise, returns false
    */
    bool isEmpty() const;
    
    ///isFull Method
    /*!
    Returns true if the queue is full. Otherwise, returns false
    */
    bool isFull() const;

    ///putFront Method
    /*!
    Requirements: Queue is not full
    Inserts newDataItem at the front of the queue. The order of the preexisting data items is left unchanged.
    */
    void putFront(const DataType& newDataItem) throw (logic_error);
    
    ///getRear Method
    /*!
    Requirements: Queue is not empty
    Removes the most recently added (rear) data item from the queue and returns it. The remainder of the queue is left unchanged.
    */    
    DataType getRear() throw (logic_error);
    
    ///getLength Method
    /*!
    Returns the number of data items in a queue
    */
    int getLength() const;

    ///showStructure Method
    /*!
    Prints the current state of the Queue to the screen. Useful for debugging purposes.
    */
    void showStructure() const;

  private:
    class QueueNode {
      public:

    ///Constructor
    /*!
    Creates new node.
    */
	QueueNode(const DataType& nodeData, QueueNode* nextPtr);

	DataType dataItem; ///< Holds the data contained in the node
	QueueNode* next; ///< Points to the next node
    };

    QueueNode* front; ///< Points to the first node in the list
    QueueNode* back; ///< Points to the last node in the list
};
