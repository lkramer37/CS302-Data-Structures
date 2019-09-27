//--------------------------------------------------------------------
//
//  Laboratory 5                                          ListLinked.cpp
//
//  Class implementation for the linked implementation of the List ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "ListLinked.h"

using namespace std;

template <typename DataType>
List<DataType>::List(int ignored){
  //Requirements: None
  //Results: Constructor. Creates an empty list. The parameter is provided for call compatibility with the array implementation and is ignored.
  head = NULL;
  cursor = NULL;
}

template <typename DataType>
List<DataType>::List(const List& other){
  //Requirements: None
  //Results: Copy Constructor. Initializes the list to be equivalent to the other List.
  //Check if other list is empty
  if(isEmpty() == false){
    //Create a new List
    ListNode* head = new List(); //Set head pointer to new List address
    cursor = head; //Set cursor pointer to new List address
    cursor->dataItem = other->dataItem; //Copy over data from other node to new node
      while(other.next != NULL){ //While there is another node
        cursor->next = new ListNode(); //create new node and set cursor node next to new node address
        cursor = cursor.next; //set cursor to address of new node
        other.cursor = cursor.next; //set other.cursor to other.next
        cursor->dataItem = other->dataItem; //Copy dataItem from other node to new node
      }
      cursor.next = NULL; //Set curser.next to Null
  }
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List<DataType>& other){
  //Requirements: None
  //Results: Overloaded assignment operator. Sets the list to be equivalent to the other List and returns a reference to this object.
  if(isEmpty() == false){
    //Create a new List
    ListNode* head = new List(); //Set head pointer to new List address
    cursor = head; //Set cursor pointer to new List address
    cursor->dataItem = other->dataItem; //Copy over data from other node to new node
      while(other.next != NULL){ //While there is another node
        cursor->next = new ListNode(); //create new node and set cursor node next to new node address
        cursor = cursor.next; //set cursor to address of new node
        other.cursor = cursor.next; //set other.cursor to other.next
        cursor->dataItem = other->dataItem; //Copy dataItem from other node to new node
      }
      cursor.next = NULL; //Set curser.next to Null
  }
  return this;
}

template <typename DataType>
List<DataType>::~List(){
  //Requirements: None
  //Results: Destructor. Deallocates (frees) the memory used to store the nodes in the list.
  while (head != NULL){
    cursor = head; //Point cursor to address of head
    head = cursor->next; //Point head to next node
    delete cursor; //Delete node cursor is pointing at
  }
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
  //Requirements: List is not full.
  if(isFull() == true){
      throw logic_error ("insert() full list");
  }
  //Results: Inserts newDataItem into the list.
    //If the list is not empty, then inserts newDataItem after the cursor.
    //Otherwise, inserts newDataItem as the first (and only) data item in the list.
    //In either case, moves the cursor to newDataItem.
  ListNode *newNode = new ListNode(newDataItem, 0);
  if(isEmpty() == false){ //Ensure list is not empty
    newNode->next = cursor->next; //Set newDataItem next to cursor next
    cursor->next = newNode;  //Set cursor next to newDataItem
  }
  if(isEmpty() == true){  //If list is empty
    head = newNode;  //Set head to address of newDataItem
  }
  cursor = newNode;  //Set cursor to address newDataItem
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error){
  //Requirements: List is not empty
  if (isEmpty() == true){
    throw logic_error ("remove() empty list");
  }
  //Results: Removes the data item marked by the cursor from the list.
    //If the resulting list is not empty, then moves the cursor to the data item that followed the deleted data item.
    //If the deleted data item was at the end of the list, then mvoes the cursor to the beginning of the list.

    if(isEmpty() == false){
      ListNode *delCursor = cursor; //Sets delCursor to node than needs to be deleted
      if(head == cursor){ //If it's the first node in the list
        if(head->next == NULL){ //If it's the only node in the list
          head = NULL;
          delete cursor;
          return;
        }
        head = head->next; //move head to next node
        cursor = cursor->next; //move cursor to next node
        delete delCursor;
        return;
      }
      if(cursor->next == NULL){ //If it's the last node in the list
        gotoPrior();//move cursor to prior
        cursor->next = NULL;
        delete delCursor;
        cursor = head;
        return;
      }
      //If node is not first, last, or only
      delCursor = cursor;
      gotoPrior();
      cursor->next = delCursor->next;
      delete delCursor;
    }
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
  //Requirements: List is not empty
  if (isEmpty() == true){
    throw logic_error ("replace() empty list");
  }
  //Results: Replaces the data item marked by the cursor with newDataItem. The cursor remains at newDataItem.
  cursor->dataItem = newDataItem; //Replace dataItem that cursor is pointing to with newDataItem
}

template <typename DataType>
void List<DataType>::clear(){
  //Requirements: None
  //Results: Removes all the data items in the list
  while (head != NULL){
    cursor = head; //Point cursor to address of head
    head = cursor->next; //Point head to next node
    delete cursor; //Delete node cursor is pointing at
  }
}

template <typename DataType>
bool List<DataType>::isEmpty() const{
  //Requirements: None
  //Returns true if the list is empty. Otherwise, returns false.
  if(head==NULL){
    return true;
  }
  return false;
}

template <typename DataType>
bool List<DataType>::isFull() const{
  //Requirements: None
  //Results: Returns true if the list is full. Otherwise, returns false
    //Note: the implimentation notes discuss the issue of what it means to say that a list of dynamically allocated nodes is full.
      //Because your applications will probably not require much memory, we recommend that your implemention of the isFull function assume that there is always more memory available and always return true
    return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error){
    //Requirements: List is not empty
    if (isEmpty() == true){
      throw logic_error ("gotoBeginning() empty list");
    }
  //Results: Moves the cursor to the beginning of the list
  if(isEmpty() == false){ //if the list is not empty
    cursor = head;
  }
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error){
    //Requirements: List is not empty
    if (isEmpty() == true){
      throw logic_error ("gotoEnd() empty list");
    }
  //Results: Moves the cursor to the end of the list
  if(isEmpty() == false){
    while(cursor->next != NULL){
      cursor = cursor->next;
    }
  }
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error){
    //Requirements: List not empty
    if (isEmpty() == true){
      throw logic_error ("gotoNext() empty list");
    }
  //Results: If the cursor is not at the end of the list, then moves the cursor to mark the next data item in the list and returns true. Otherwise, returns false
  if(cursor->next != NULL){
    cursor = cursor->next;
    return true;
  }
  return false;
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error){
  //Requirements: List is not empty
  if (isEmpty() == true){
    throw logic_error ("gotoPrior() empty list");
  }
  //Results: If the cursor is not at the beginning of the list, then moves the cursor to mark the preceding data item in the list and returns true. Otherwise, returns false.
  if(cursor != head){
    ListNode *ptr = head; //Set temp ptr to head
    while(ptr->next != cursor){ //While next is not the cursor
      ptr = ptr->next; //move pointer to next node
    }
    cursor = ptr; //set cursor to ptr
    return true;
  }
  return false;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error){
  //Requirements: List not empty
  if (isEmpty() == true){
    throw logic_error ("getCursor() empty list");
  }
  //Results: Returns the value of the data item marked by the cursor
  return cursor->dataItem;
}

// Programming exercise 2
template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error){
  //Requirements: List not empty
  if (isEmpty() == true){
    throw logic_error ("moveToBeginning() empty list");
  }
  //Results: Removes the data item marked by the cursor from the list and reinserts the dat item at the beginning of the list. Moves the cursor to the beginning of the list.
  ListNode *temp=cursor;
  gotoPrior();
  cursor->next = temp->next;
  temp->next = head;
  head = temp;
  cursor = head;
}

// Programming exercise 3
template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error){
  //Requirements: List not full
  if(isFull() == true){
      throw logic_error ("insertBefore() full list");
  }
  //Results: Inserts newDataItem into a list. If the list is not empty, then inserts newDataItem immediately before the cursor. Ohterwise, inserts newDataItem as the first (and only) data item in the list. In either case, moves the cursor to newDataItem.
  // ****Copy the data item pointed to by the cursor into anew node, to insert this node after the cursor, and to place newDataItem in the node pointed to by the cursor.
  gotoPrior();
  insert(newDataItem);
}

template <typename DataType>
void List<DataType>::showStructure() const{
}

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
  //Requirements - None
  //Results - Constructor. Creates an initialized ListNode by setting the ListNode's data item to the value nodeData and the ListNode's next pointer to the value of nextPtr
    dataItem = nodeData; //Creates an initalized ListNode set to the value nodeData
    next = nextPtr; //ListNode's next pointer set to the value of nextPtr
}
