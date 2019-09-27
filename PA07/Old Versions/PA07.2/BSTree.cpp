//
// Created by lkramer37 on 10/25/17.
//

#include <iostream>
#include "BSTree.h"
#include "show9.cpp"

using namespace std;

/**
@brief Default Binary Tree Constructor
@pre None
@post Creates an empty binary search tree
*/
template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>::BSTree()
{
    root = NULL;
};

/**
@brief Copy Constructor
@param other Reference to binary tree to be copied
@pre None
@post Inititalizes the binary search tree to be equivalent to the other BSTree object parameter
*/

template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>::BSTree(const BSTree<DataType,KeyType> &other)
{

};


/**
@brief Overloaded Assignment Operator
@param other Reference to binary tree to be copied
@pre None
@post Sets the binary search tree to be equivalent to the other BSTree object parameter
@return Reference to the calling object
*/
template <typename DataType, typename KeyType>
BSTree& BSTree<DataType,KeyType>::operator= (const BSTree<DataType, KeyType> &other)
{

};


/**
@brief Destructor
@param None
@pre None
@post Deallocates the memory used to store the binary search tree
*/
template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>::~BSTree()
{

}


/**
@brief Inserts new data item
@param newDataItem Reference to DataType to be added to binary tree
@pre None
@post Inserts newDataItem into the binary search tree. If a data item with the same key as newDataItem already exists in the tree, then updates that data item with newDataItem
@see insertHelper Function
*/
template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>::insert(const DataType& newDataItem)
{

}

template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>::insertHelper()
{

}

/**
@brief Retrieves data item
@param searchKey {Description}
@param searchDataItem {Description}
@pre None
@post Searches the binary search tree for the data item with key searchKey. If this data item is found, then copies the data item to searchDataItem and returns true. Otherwise, returns false with searchDataItem undefined.
@see { references }
@note { text … ex. An algorithm }
@return Returns true if data item is found, otherwise returns false.
*/
template <typename DataType, typename KeyType>
bool BSTree<DataType,KeyType>::retrieve(const KeyType &searchKey, DataType &searchDataItem) const
{

};

/**
@brief Removes data item
@param deleteKey Reference to the index value that needs to be deleted from the binary tree
@pre None
@post Deletes the data item with key deleteKey from the binary search tree. If this data item is found, then deletes it from the tree and returns true. Otherwise, returns false
@see { references }
@note { text … ex. An algorithm }
@return Returns true if data item is found and deleted. Otherwise, returns false.
*/
template <typename DataType, typename KeyType>
bool BSTree<DataType,KeyType>::remove(const KeyType &deleteKey)
{

}

/**
@brief Output keys
@pre None
@post Outputs the keys of the data items in the binary search tree. The keys are output in ascending order on one line, separated by spaces.
@see { references }
@note { text … ex. An algorithm }
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::writeKeys() const
{

}

/**
@brief Clears the tree
@post Removes all the data items in the binary search tree
@see { references }
@note { text … ex. An algorithm }
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::clear()
{

}

/**
@brief Checks if the binary tree is empty
@return Returns true if tree is empty, otherwise, returns false
*/
template <typename DataType, typename KeyType>
bool BSTree<DataType,KeyType>::isEmpty() const
{
    if(root == NULL){return true;}
    return false;
};


/**
@brief Gets the height of the binary tree
@param <parameter-name> { parameter
description }
@pre { description of the precondition }
@post { description of the postcondition }
@exception <exception-object> { exception
description }
@see { references }
@note { text … ex. An algorithm }
@return { description of the return value }
*/
template <typename DataType, typename KeyType>
int BSTree<DataType,KeyType>::getHeight() const
{

};

/**
@brief Gets the number of nodes in tree
@param <parameter-name> { parameter
description }
@pre { description of the precondition }
@post { description of the postcondition }
@exception <exception-object> { exception
description }
@see { references }
@note { text … ex. An algorithm }
@return { description of the return value }
*/
template <typename DataType, typename KeyType>
int BSTree<DataType,KeyType>::getCount() const
{

};

/**
@brief Output keys < searchKey
@param <parameter-name> { parameter
description }
@pre { description of the precondition }
@post { description of the postcondition }
@exception <exception-object> { exception
description }
@see { references }
@note { text … ex. An algorithm }
@return { description of the return value }
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::writeLessThan(const KeyType &searchKey) const
{

};

/**
@brief Tree Node Constructor
@param <parameter-name> { parameter
description }
@pre { description of the precondition }
@post { description of the postcondition }
@exception <exception-object> { exception
description }
@see { references }
@note { text … ex. An algorithm }
@return { description of the return value }
*/
template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>::BSTreeNode::BSTreeNode(const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr)
{

};