//HashTable.cpp

#include <stdexcept>
#include <iostream>
#include "HashTable.h"

using namespace std;

/**
 @brief Constructor
 @param initTableSize {parameter description}
 @post Creates the empty hash table
 */
template <typename DataType, typename KeyType>
HashTable <DataType, KeyType> :: HashTable(int initTableSize)
{
    tableSize = initTableSize;
    dataTable =  new BSTree<DataType, KeyType>[tableSize];
};

/**
 @brief Copy Constructor
 @param other Address to the table to be copied
 @post Initializes the hash table to be equivalent to the HashTable object parameter other
 @see {references}
 */
template <typename DataType, typename KeyType>
HashTable <DataType, KeyType> :: HashTable(const HashTable& other)
{

};

/**
 @brief Overloaded Assignment Operator
 @param other Address to the table to be copied
 @post Sets the hash table to be equivalent to the other HashTable object parameter
 @return Reference to this object
 @see {references}
 */
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable <DataType, KeyType> :: operator= (const HashTable& other)
{

};

/**
 @brief Destructor
 @post Deallocates (frees) the memory used to store a hash table
 @see {references}
 */
template <typename DataType, typename KeyType>
HashTable <DataType, KeyType> :: ~HashTable()
{
    clear();
    delete [] dataTable;
    dataTable = NULL;
};

/**
 @brief Insert
 @param data {parameter description}
 @post Inserts newDataItem into the appropriate BST. If a data item with the same key as newDataItem already exists in the BST, then updates that data item with newDataItem. Otherwise, it inserts it in the binary search tree
 @see {references}
 */
template <typename DataType, typename KeyType>
void HashTable <DataType, KeyType> :: insert(const DataType& newDataItem)
{

// Create entry to add to dictionary
        HashedEntry <KeyType, ItemType> *entryToAddPtr = new HashedEntry <KeyType, ItemType> (newItem, searchKey);

// Compute the hashed index into the array
        int itemHashIndex = getHashIndex (searchKey);

// Add the entry to the chain at itemHashIndex
        if (hashTable[itemHashIndex] == nullptr)
        {
            hashTable[itemHashIndex] = entryToAddPtr;
        }
        else
        {
            entryToAddPtr->setNext (hashTable[itemHashIndex]);
            hashTable[itemHashIndex] = entryToAddPtr;
        }	// end if
        return true;
    }   // end add
*/

};

/**
 @brief Remove
 @param deleteKey {parameter description}
 @post Searches the hash table for the data item with the key deleteKey. If the data item is found, then removes the data item.
 @return True if the data item is found and removed. Otherwise returns false
 @see {references}
 */
template <typename DataType, typename KeyType>
bool HashTable <DataType, KeyType> :: remove (const KeyType& deleteKey)
{
    /*
    template < class KeyType, class ItemType >
    bool HashedDictionary < KeyType, ItemType >::remove (const KeyType & searchKey)
    {
        bool itemFound = false;

// Compute the hashed index into the array
        int itemHashIndex = getHashIndex (searchKey);

        if (hashTable[itemHashIndex] != nullptr)
        {
// Special case - first node has target
            if (searchKey == hashTable[itemHashIndex]->getKey ())
            {
                HashedEntry < KeyType, ItemType > *entryToRemovePtr = hashTable[itemHashIndex];
                hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext ();
                delete entryToRemovePtr;

                entryToRemovePtr = nullptr;	// For safety
                itemFound = true;
            }
            else	// Search the rest of the chain
            {
                HashedEntry < KeyType, ItemType > *prevPtr = hashTable[itemHashIndex];
                HashedEntry < KeyType, ItemType > *curPtr = prevPtr->getNext ();
                while ((curPtr != nullptr) && !itemFound)
                {
// Found item in chain so remove that node
                    if (searchKey == curPtr->getKey ())
                    {
                        prevPtr->setNext (curPtr->getNext ());
                        delete curPtr;

                        curPtr = nullptr;	// For safety
                        itemFound = true;
                    }
                    else	// Look at next entry in chain
                    {
                        prevPtr = curPtr;
                        curPtr = curPtr->getNext ();
                    }	// end if
                }	// end while
            }	// end if
        }	// end if
        return itemFound;
    }   // end remove
    */
}

/**
 @brief Retrieve
 @param key {parameter description}
 @param returnItem {parameter description}
 @post Searches the hash table for the data item with key searchKey. If the data item is found, then copies the data item to returnItem.
 @note {text ... ex An algorithm}
 @return Returns true if data item is found. Otherwise, returns false with returnItem undefined.
 @see {references}
 */
template <typename DataType, typename KeyType>
bool HashTable <DataType, KeyType> :: retrieve (const KeyType& key, DataType& returnItem) const {

};

/**
 @brief Clear
 @post Removes all data items in the hash table
 */
template <typename DataType, typename KeyType>
void HashTable <DataType, KeyType> :: clear()
{

};

/**
 @brief Empty Check
 @return Returns true if the hash table is empty. Otherwise returns false
 */
template <typename DataType, typename KeyType>
bool HashTable <DataType, KeyType> :: isEmpty() const
{

};

/**
 @brief Show Structure
 @post Outputs the data items in the hash table. If the has table is empty, outputes "Empty hash table". For testing/debugging purposes.
*/
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const
{
    for (int i = 0; i < tableSize; ++i)
    {
        cout << i << ": ";
        dataTable[i].writeKeys();
    }
}

/**
 @brief <brief description>
 @param <parameter-name> {parameter description}
 @pre {description of the precondition}
 @post {description of the postcondition}
 @exception <exception-object> {exception description}
 @note {text ... ex An algorithm}
 @return {description of the return value}
 @see {references}
 */

template <typename DataType, typename KeyType>
double HashTable <DataType, KeyType> :: standardDeviation() const
{

};

        /**
 @brief <brief description>
 @param <parameter-name> {parameter description}
 @pre {description of the precondition}
 @post {description of the postcondition}
 @exception <exception-object> {exception description}
 @note {text ... ex An algorithm}
 @return {description of the return value}
 @see {references}
 */

template <typename DataType, typename KeyType>
void HashTable <DataType, KeyType> :: copyTable(const HashTable& source)
{

};

/*
/**
 @brief <brief description>
 @param <parameter-name> {parameter description}
 @pre {description of the precondition}
 @post {description of the postcondition}
 @exception <exception-object> {exception description}
 @note {text ... ex An algorithm}
 @return {description of the return value}
 @see {references}


template <typename DataType, typename KeyType>
HashTable <DataType, KeyType> ::
*/