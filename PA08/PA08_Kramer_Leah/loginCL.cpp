#include <iostream>
#include <fstream>
#include <string>

#include "HashTable.cpp"

using namespace std;

class TestData {
  public:
    TestData();
    void setKey(const string& newKey);
    string getKey() const;
    void setValue(const string& newValue);
    string getValue() const;
    static unsigned int hash(const string& str);

  private:
    string key;
    string value;
};

TestData::TestData(){}

void TestData::setKey(const string& newKey) {
    key = newKey;
}

string TestData::getKey() const {
    return key;
}

void TestData::setValue(const string& newValue) {
    value = newValue;
}

string TestData::getValue() const {
    return value;
}

unsigned int TestData::hash(const string& str) {
    unsigned int val = 0;

    for (int i = 0; i < str.length(); ++i) {
	val += str[i];
    }

    return val;
}

void readIn(HashTable <TestData, string>& table);
void promptUser(HashTable <TestData, string>& table);

int main(){

	HashTable <TestData, string> table(8);

	readIn(table);
	promptUser(table);

	return 0;

}

void readIn(HashTable <TestData, string>& table){

	ifstream passwords ("password.dat");

	TestData tempData;
	string tempString;

	passwords >> tempString;
	tempData.setKey(tempString);

	passwords >> tempString;
	tempData.setValue(tempString);

	while(!passwords.eof()){

		table.insert(tempData);

		passwords >> tempString;
		tempData.setKey(tempString);

		passwords >> tempString;
		tempData.setValue(tempString);
	}

	table.showStructure();

}

void promptUser(HashTable <TestData, string>& table){

	TestData test;

	string userName;
	string password;

	cout << "Login: ";
	cin >> userName;


	while(!cin.eof()){

		cout<< "Password: ";
		cin >> password;

		if(table.retrieve(userName, test)){

			if(test.getValue() == password){

				cout << "Authentication successful" << std::endl;

			}
			else{

				cout << "Authentication failure" << std::endl;

			}

		}
		else{

			cout << "Authentication failure" << std::endl;

		}

		cout << "Login: ";
		cin >> userName;


	}

}
