// HashTable.h

/**
 * @file HashTable.h
 * @author Leah Kramer
 * @date 10/08/2017
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdexcept>
#include <iostream>

using namespace std;

#include "BSTree.cpp"

template <typename DataType, typename KeyType>
class HashTable {
  public:
    HashTable(int initTableSize);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void insert(const DataType& newDataItem);
    bool remove(const KeyType& deleteKey);
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    void clear();

    bool isEmpty() const;
    void showStructure() const;
    double standardDeviation() const;

  private:
    void copyTable(const HashTable& source);

    int tableSize;
    BSTree<DataType, KeyType>* dataTable;
};

#endif	// ifndef HASHTABLE_H

/** A class of entry objects for an array-based implementation of the ADT dictionary.
@file Entry.h
 */

/*
#ifndef _ENTRY
#define _ENTRY
template < class KeyType, class ItemType > class Entry
{
private:
    DataType item;
    KeyType searchKey;

protected:
    void setKey (const KeyType & searchKey);

public:
    Entry ();
    Entry (ItemType newEntry, KeyType searchKey);
    ItemType getItem () const;
    KeyType getKey () const;
    void setItem (const ItemType & newEntry);

    bool operator== (const Entry < KeyType, ItemType > &rightHandItem) const;
    bool operator> (const Entry < KeyType, ItemType > &rightHandItem) const;
};				// end Entry

#include "Entry.cpp"
#endif
*/

/** A class of entry objects for a hashing implementation of the ADT dictionary.
@file HashedEntry.h */

/*
#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY
#include "Entry.h"
template < class KeyType, class ItemType >

class HashedEntry:public Entry < KeyType, ItemType >
{
private:
    HashedEntry < KeyType, ItemType > *nodePtr;
public:
    HashedEntry ();
    HashedEntry (DataType data, KeyType searchKey);
    HashedEntry (DataType data, KeyType searchKey, HashedEntry < KeyType, ItemType > *nodePtr);
    void setNext (HashedEntry < KeyType, ItemType > *nextEntryPtr);

    HashedEntry < KeyType, ItemType > *getNext ()const;
};  // end HashedEntry

#include "HashedEntry.cpp"
#endif
 */

