//--------------------------------------------------------------------
//
//  Laboratory 9                                    BSTree.h
//
//  Class declarations for the linked implementation of the Binary
//  Search Tree ADT -- including the recursive helpers of the
//  public member functions
//
//--------------------------------------------------------------------

/**
@file BSTree.h
@author Leah Kramer
@date 01/01/1970
*/

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree          // KeyType : key field
{
  public:

    // Constructor
    BSTree ();                         // Default constructor
    BSTree ( const BSTree<DataType,KeyType>& other );   // Copy constructor
    BSTree& operator= ( const BSTree<DataType,KeyType>& other ); // Overloaded assignment operator

    // Destructor
    ~BSTree ();

    // Binary search tree manipulation operations
    void insert ( const DataType& newDataItem );  // Insert
    bool retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const; // Retrieve data item
    bool remove ( const KeyType& deleteKey ); // Remove item
    void writeKeys () const; // Output keys
    void clear (); // Clear tree

    // Binary search tree status operations
    bool isEmpty () const;  // Tree is empty

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    int getHeight () const; // Height of tree
    int getCount () const; // Number of nodes in tree

  protected:

    class BSTreeNode // Inner class: facilitator for the BSTree class
    {
      public:
    
        // Constructor
        BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr );

        // Data members
        DataType dataItem; ///< Binary search tree data item
        BSTreeNode *left; ///< Pointer to the left child
        BSTreeNode *right; ///< Pointer to the right child
    };

    // Recursive helpers for the public member functions
    void showHelper ( BSTreeNode *p, int level ) const;
    void insertHelper(BSTreeNode *&ptr, DataType data);
    bool retrieveHelper(BSTreeNode* ptr, const KeyType& searchKey, DataType& searchDataItem) const;
    void clearHelper(BSTreeNode *&ptr);
    bool removeHelper(BSTreeNode*& ptr, const KeyType& deleteKey );
    void writeHelper(BSTreeNode* ptr)const;
    void copyHelper(const BSTreeNode* sourcePtr, BSTreeNode*& newPtr);
    int heightHelper(BSTreeNode * ptr) const;
    int countHelper(BSTreeNode* ptr, int& count) const;

    // Data member
    BSTreeNode *root; ///< Pointer to the root node
};

#endif	// define BSTREE_H

