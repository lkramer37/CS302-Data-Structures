//--------------------------------------------------------------------
//
//  Laboratory 11, In-lab Exercise 1                     database.cs
//
//  (Shell) Indexed accounts database program
//
//--------------------------------------------------------------------

// Builds a binary search tree index for the account records in the
// text file accounts.dat.

#include <iostream>
#include <fstream>
#include "BSTree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declarations specifying the accounts database
//

const int nameLength      = 11;   // Maximum number of characters in
                                  //   a name
const long bytesPerRecord = 37;   // Number of bytes used to store
                                  //   each record in the accounts
                                  //   database file

struct AccountRecord
{
    int acctID;                   // Account identifier
    char firstName[nameLength],   // Name of account holder
         lastName[nameLength];
    double balance;               // Account balance
};

//--------------------------------------------------------------------
//
// Declaration specifying the database index
//

struct IndexEntry
{
    int acctID;              // (Key) Account identifier
    long recNum;             // Record number

    int getKey () const
        { return acctID; }   // Return key field
};

//--------------------------------------------------------------------

int main() {
    ifstream acctFile ("accounts.dat");   // Accounts database file
    AccountRecord acctRec;                // Account record
    BSTree<IndexEntry,int> index;         // Database index
    IndexEntry entry;                     // Index entry
    int searchID;                         // User input account ID
    long recNum = 0;                      // Record number

    // Iterate through the database records. For each record, read the
    // account ID and add the (account ID, record number) pair to the
    // index.


    acctFile >> entry.acctID;
    while( acctFile.good() )
    {
        entry.recNum = recNum;                          //
        index.insert(entry);                            //
        acctFile.seekg(bytesPerRecord-5, acctFile.cur); // we read in one number before entering the loop and then once we're in the loop we read it at the end so that when we reach the EOF the check works for the loop
        recNum++;                                       //
        acctFile >> entry.acctID;                       //
    }


    // Output the account IDs in ascending order.
    // Clear the status flags for the database file.
    acctFile.clear();

    // Read an account ID from the keyboard and output the corresponding record.
    cout << endl << "Account IDs :" << endl;
    index.writeKeys();
    cout << endl;

    cout << "Enter account ID : ";
    cin >> searchID;




    while( cin.good() ) // this is the condition for the while loop because we are reading in HIS input from a file, his test cases say EOF to quit, this is why
    {
        if(index.retrieve(searchID, entry))
        {
            acctFile.seekg((bytesPerRecord) * entry.recNum, acctFile.beg);
            acctFile >> acctRec.acctID
                     >> acctRec.firstName
                     >> acctRec.lastName
                     >> acctRec.balance;
            recNum = entry.recNum;
            cout << recNum
                 << " : " << acctRec.acctID
                 << " " << acctRec.firstName
                 << " " << acctRec.lastName
                 << " " << acctRec.balance << endl;
        }
        else
        {
            cout << "No record with that account ID"<< endl; // the formatting for tests
        }
        acctFile.clear();

        cout << "Enter account ID (EOF to quit): "; // this is the EOF to quit thing, its really weird that he did it this way if you have any questions just text me
        cin >> searchID;
    }

}

