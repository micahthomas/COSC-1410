// Assignment 11 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Account {
  int id;
  string lname;
  string fname;
  double balance;
};

class Bank {
  public:
    Bank();
    void readData(string file);
    void writeData(string file);
    void sortByID();
    void sortByLName();
    void printData();
  private:
    Account *accounts[100];
    ifstream fin;
    ofstream fout;
    int numAccounts;
};

Bank::Bank() {
  numAccounts = 0;
}

void Bank::readData(string file) {
  numAccounts = 0;
  fin.open(file.c_str());
  if (fin.fail()) {
    cout << "Input File cannot be opened." << endl;
    cout << "Press ENTER to continue ...";
    cin.get();
    return;
  } else {
    cout << "Opened file: " << file << endl;
    while (!fin.eof()) {
      accounts[numAccounts] = new Account;
      fin >> accounts[numAccounts]->id
          >> accounts[numAccounts]->fname
          >> accounts[numAccounts]->lname
          >> accounts[numAccounts]->balance;
      numAccounts++;
    }
  }
  fin.close();
}

void Bank::writeData(string file) {
  fout.open(file.c_str());
  if (fout.fail()) {
    cout << "Input File cannot be opened." << endl;
    cout << "Press ENTER to continue ...";
    cin.get();
    return;
  } else {
    cout << "File opened: " << file << endl;
  }
  for (int i = 0; i < numAccounts; i++) {
    fout << accounts[i]->id << " "
         << accounts[i]->fname << " "
         << accounts[i]->lname << " "
         << accounts[i]->balance << endl;
  }
  fout.close();
}

void Bank::printData() {
  for (int i = 0; i < numAccounts; i++) {
    cout << accounts[i]->id << " "
         << accounts[i]->fname << " "
         << accounts[i]->lname << " "
         << accounts[i]->balance << endl;
  }
}

void Bank::sortByID() {
  Account *temp;
  for (int i = 0, indexOfNextSmallest; i < numAccounts - 1; i++) {
    indexOfNextSmallest = i;
    for (int k = i + 1; k < numAccounts; k++)
      if (accounts[k]->id < accounts[indexOfNextSmallest]->id)
        indexOfNextSmallest = k;
    temp = accounts[i];
    accounts[i] = accounts[indexOfNextSmallest];
    accounts[indexOfNextSmallest] = temp;
  }
}

void Bank::sortByLName() {
  Account *temp;
  for (int i = 0, indexOfNextSmallest; i < numAccounts - 1; i++) {
    indexOfNextSmallest = i;
    for (int k = i + 1; k < numAccounts; k++)
      if (accounts[k]->lname < accounts[indexOfNextSmallest]->lname)
        indexOfNextSmallest = k;
    temp = accounts[i];
    accounts[i] = accounts[indexOfNextSmallest];
    accounts[indexOfNextSmallest] = temp;
  }
}

int main(int argc, char *argv[]) {
  Bank bank;
  if (argc == 4) {
    bank.readData(string(argv[1]));
    if (string(argv[3]) == string("LastName"))
      bank.sortByLName();
    else if (string(argv[3]) == string("ID"))
      bank.sortByID();
    else
      cout << "Unknown Sorting ORDER, copying the data\n";
    bank.writeData(string(argv[2]));
  } else {
    cout << "Incorrect argument format detected, using defaults =>
         \nInput: prog11in.txt
         \nOutput: prog11out.txt
         \nSortBy: ID
         \nExpected Usage:
         \n./program.exe proginput.txt progoutput.txt (LastName or ID)";
    bank.readData(string("prog11in.txt"));
    bank.sortByID();
    bank.writeData(string("prog11out.txt"));
  }
}