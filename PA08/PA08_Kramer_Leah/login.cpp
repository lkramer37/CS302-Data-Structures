#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.cpp"

using namespace std;

struct Account
{
    string username;            // (Key) Account number
    string password;            // Account balance

    string getKey() const { return username; }
    static unsigned int hash(const string& str);
};

unsigned int Account::hash(const string& str) { //adds ascii values from string
    unsigned int val = 0;

    for (int i = 0; i < str.length(); ++i) {
        val += str[i];
    }
    return val;
}

int main()
{
    HashTable<Account,string> accounts(8);  // List of accounts
    Account acct;                         // A single account
    //string searchKey;                        // An account key

    // Read in information on a set of accounts.
    ifstream inFile("password.dat");
    string user, pass;

	//Read in
	//While loop
		//Do stuff
		//Read in

    inFile >> acct.username >> acct.password;
    
    while(!inFile.eof())
    {        
        accounts.insert(acct);
        inFile >> acct.username >> acct.password;
        cout << acct.username << " " << acct.password << endl;
    }

    accounts.showStructure();
    Account tempObject;                         // A single account

    cout << "Login: ";
    cin >> acct.username >> acct.password;      //READ IN BEFORE ENTERING LOOP
    while (!cin.eof())
    {
        
        cout << "Password: ";
        if (accounts.retrieve(acct.username, tempObject))
        {
            if(acct.password == tempObject.password)
            {
                cout << "Authentication successful" << endl;
            }
            else
            {
                cout << "Authentication failure" << endl;
            }
        }
        cout << "Login: ";
        cin >> acct.username >> acct.password;
      //READ IN AT THE END OF LOOP
    }
    return 0;
}
