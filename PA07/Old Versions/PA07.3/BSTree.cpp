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
    root = NULL;
    BSTreeNode* sourcePtr = other.root;
    BSTreeNode* newPtr = root;

    copyHelper(sourcePtr, root);

    //Pre-Order Traversal
    /*Create New(copy)
     * copyHelper(left)
     * copyHelper(right)
     */
};


/**
@brief Overloaded Assignment Operator
@param other Reference to binary tree to be copied
@pre None
@post Sets the binary search tree to be equivalent to the other BSTree object parameter
@return Reference to the calling object
*/
template <typename DataType, typename KeyType>
BSTree<DataType,KeyType>& BSTree<DataType,KeyType>::operator= (const BSTree &other)
{
    if(this == &other) {return *this;}
    clear();
    BSTreeNode* sourcePtr = other.root;
    BSTreeNode* newPtr = root;
    copyHelper(sourcePtr, newPtr);
};

template<typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::copyHelper(BSTree<DataType,KeyType>*& sourcePtr, BSTree<DataType,KeyType>*& newPtr)
{
    if(sourcePtr!=NULL)
    {
        newPtr = new BSTreeNode(sourcePtr->dataItem, NULL, NULL);
        copyHelper(sourcePtr->left, newPtr->left);
        copyHelper(sourcePtr->right, newPtr->right);
    }
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
    clear();
}


/**
@brief Inserts new data item
@param newDataItem Reference to DataType to be added to binary tree
@pre None
@post Inserts newDataItem into the binary search tree. If a data item with the same key as newDataItem already exists in the tree, then updates that data item with newDataItem
@see insertHelper Function
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::insert(const DataType& newDataItem)
{
    insertHelper(root, newDataItem);
}

template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::insertHelper(BSTreeNode *&ptr, DataType data)
{
    if(ptr==NULL)
    {
        ptr = new BSTreeNode(data, NULL, NULL);
    }

    else if((ptr->dataItem) > data)
    {
        insertHelper(ptr->left, data);
    }

    else if((ptr->dataItem) < data)
    {
        insertHelper(ptr->right, data);
    }
}

/**
@brief Retrieves data item
@param searchKey The key of the data item that is being searched for in the binary tree
@param searchDataItem If a data item is found that matches the searchKey, then the data item is copied to searchDataItem, otherwise, it is left undefined
@pre None
@post Searches the binary search tree for the data item with key searchKey. If this data item is found, then copies the data item to searchDataItem and returns true. Otherwise, returns false with searchDataItem undefined.
@see bool BSTree<DataType,KeyType>::retrieveHelper(BSTreeNode* ptr, const KeyType& searchKey, DataType& searchDataItem)
@return Returns true if data item is found, otherwise returns false.
*/
template <typename DataType, typename KeyType>
bool BSTree<DataType,KeyType>::retrieve(const KeyType &searchKey, DataType &searchDataItem) const
{
    if(root == NULL) { return false; }
    return retrieveHelper(root, searchKey, searchDataItem);
};

/**
@brief Recursive Helper function for public retrieve function
@param ptr A pointer to the current node
@param searchKey The key of the data item that is being searched for in the binary tree
@param searchDataItem If a data item is found that matches the searchKey, then the data item is copied to searchDataItem, otherwise, it is left undefined
@pre None
@post Searches the binary search tree for the data item with key searchKey. If this data item is found, then copies the data item to searchDataItem and returns true. Otherwise, returns false with searchDataItem undefined.
@see bool BSTree<DataType,KeyType>::retrieve(const KeyType &searchKey, DataType &searchDataItem) const
@return Returns true if data item is found, otherwise returns false.
*/
template<typename DataType, typename KeyType>
bool BSTree<DataType,KeyType>::retrieveHelper(BSTreeNode* ptr, const KeyType& searchKey, DataType& searchDataItem) const
{
    if(ptr->dataItem.getKey() == searchKey)
    {
        searchDataItem = ptr->dataItem;
        return true;
    }

    if(ptr != NULL)
    {
        retrieveHelper(ptr->left, searchKey, searchDataItem);
        retrieveHelper(ptr->right, searchKey, searchDataItem);
        return false;
    }

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
    removeHelper(root, deleteKey);
}
template <typename DataType, typename KeyType>
bool BSTree<DataType,KeyType>::removeHelper(BSTreeNode*& ptr, const KeyType& key)
{
    if (ptr==NULL) //if tree is empty
    {
        return false;
    }

    if (ptr->dataItem.getKey()<key) //if data item is less than key, go left
    {
        return (removeHelper(ptr->right, key));
    }

    if (ptr->dataItem.getKey()>key) //if data item is greater than key, go right
    {
        return (removeHelper(ptr->left, key));
    }

    if ((ptr->left==NULL) && (ptr->right==NULL)) //if the node has no children
    {
        delete ptr;
        ptr = NULL;
        return true;
    }

    if (ptr->right==NULL) //if node has one child on the right
    {
        BSTreeNode *temp = ptr;
        ptr = ptr->left;
        return true;
    }

    if (ptr->left==NULL) //if node has one child on the left
    {
        BSTreeNode *temp = ptr;
        ptr = ptr->right;
        return true;
    }

    else //if node has two children
    {
        BSTreeNode *temp = ptr->left;

        while (temp->right != NULL) //move ptr until last right node is reached
        {
            temp = temp->right;
        }
        ptr->dataItem = temp->dataItem;
        removeHelper(ptr->left, ptr->dataItem.getKey());
        return true;
    }
};


/**
@brief Output keys
@pre None
@post Outputs the keys of the data items in the binary search tree. The keys are output in ascending order on one line, separated by spaces.
@see void BSTree::writeHelper(BSTreeNode*& ptr)
@note { text … ex. An algorithm }
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::writeKeys() const
{
    writeHelper(root);
}

/**
@brief Recursive helper function to output keys
@pre None
@post Outputs the keys of the data items in the binary search tree. The keys are output in ascending order on one line, separated by spaces.
@see void BSTree<DataType,KeyType>::writeKeys() const
@note In-Order Traversal
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::writeHelper(BSTreeNode* ptr)const {
    if(ptr!=NULL)
    {
        //DataType data;
        writeHelper(ptr->left);
        cout << ptr->dataItem.getKey() << " ";
        writeHelper(ptr->right);
    }
};

/**
@brief Clears the tree
@post Removes all the data items in the binary search tree
@see { references }
@note { text … ex. An algorithm }
*/
template <typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::clear()
{
    //Post-Order Traversal
    clearHelper(root);
}

template<typename DataType, typename KeyType>
void BSTree<DataType,KeyType>::clearHelper(BSTreeNode *&ptr)
{
        if (ptr==NULL) {return;}
        clearHelper(ptr->left);
        clearHelper(ptr->right);
        delete ptr;
        ptr = NULL;
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
    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;
};