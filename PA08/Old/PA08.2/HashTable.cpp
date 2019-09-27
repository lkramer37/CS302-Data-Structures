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
    tableSize = other.tableSize;
    dataTable =  new BSTree<DataType, KeyType>[tableSize];
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
 @see void HashTable <DataType, KeyType> :: clear()
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
 */
template <typename DataType, typename KeyType>
void HashTable <DataType, KeyType> :: insert(const DataType& newDataItem)
{
    //Create index
    int index = newDataItem.hash(newDataItem.getKey());
    //cout << "String Hash Value: " << index << endl;
    index %= tableSize;
    //cout << "HashValue % tableSize: " << index << endl;

    dataTable[index].insert(newDataItem); //pass newDataItem to BSTree* insert function
};

/**
 @brief Remove
 @param deleteKey key for object to be deleted
 @post Searches the hash table for the data item with the key deleteKey. If the data item is found, then removes the data item.
 @return True if the data item is found and removed. Otherwise returns false
 */
template <typename DataType, typename KeyType>
bool HashTable <DataType, KeyType> :: remove (const KeyType& deleteKey)
{
    DataType tableObject;
    int index = tableObject.hash(deleteKey);
    index %= tableSize;

    return dataTable[index].remove(deleteKey);
}

/**
 @brief Retrieve
 @param key The key for the item to be searched for
 @param returnItem DataType object that the data returned from the search returns
 @post Searches the hash table for the data item with key searchKey. If the data item is found, then copies the data item to returnItem.
 @note gets hash index from key parameter then calls BSTree class retrieve method.
 @return Returns true if data item is found. Otherwise, returns false with returnItem undefined.
 */
template <typename DataType, typename KeyType>
bool HashTable <DataType, KeyType> :: retrieve (const KeyType& searchKey, DataType& returnItem) const {

    int index = returnItem.hash(searchKey);
    index %= tableSize;

    return dataTable[index].retrieve (searchKey, returnItem);
};

/**
 @brief Clear
 @post Removes all data items in the hash table
 */
template <typename DataType, typename KeyType>
void HashTable <DataType, KeyType> :: clear()
{
    for(int i = 0; i<=tableSize; ++i)
    {
        dataTable[i].clear();
    }
};

/**
 @brief Empty Check
 @return Returns true if the hash table is empty. Otherwise returns false
 */
template <typename DataType, typename KeyType>
bool HashTable <DataType, KeyType> :: isEmpty() const
{
    for (int i=0; i<=tableSize; ++i)
    {
        if (!dataTable[i].isEmpty()) { return false; }
    }
    return true;
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
        cout << endl;
    }
}

/**
 @brief <brief description>
 @param <parameter-name> {parameter description}
 @pre {description of the precondition}
 @post {description of the postcondition}
 @exception <exception-object> {exception description}
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
 @return {description of the return value}
 @see {references}
 */

template <typename DataType, typename KeyType>
void HashTable <DataType, KeyType> :: copyTable(const HashTable& source)
{

};

