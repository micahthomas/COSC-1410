// Assignment 8 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

ifstream inStream;

struct student
{
    int id;
    char fname[20];
    char lname[20];
    char email[40];
    double gpa;
};

struct roster
{
    student records[100];
    int students;
};

bool getRecord(int& recNum, int& id, char fname[], char lname[], char email[], double& gpa);
void loadData(struct roster &data);
void printData(struct roster data);
void printStudent(struct student data);
int searchId(struct roster data);
int searchName(struct roster data);
bool menu(struct roster data);

int main() {
    bool loop;
    roster compsci;
    loadData(compsci);
    do {
        loop = menu(compsci);
    } while(loop);
}

bool getRecord(int& recNum, int& id, char fname[], char lname[], char email[], double& gpa){
   if (recNum==0) {
      inStream.open("prog8in.txt");
      if (inStream.fail()){
         cout<<"File \"prog8in.txt\" cannot be opened."<<endl;
         cout<<"Press ENTER to continue ...";
         cin.get();
         return false;
      } else cout<<"File \"prog8in.txt\" opened."<<endl;
   }
   inStream >>id >>fname >>lname >>email >>gpa;
   if (inStream.eof()) return false;
   else {
       recNum++;
       return true;
   }
}

void loadData(struct roster &data)
{
    data.students = 0;
    int recNum = 0;
    int id;
    char fname[20];
    char lname[20];
    char email[40];
    double gpa;
    while(getRecord(recNum, id, fname, lname, email, gpa))
    {
        data.records[data.students].id    = id;
        strcpy(data.records[data.students].fname, fname);
        strcpy(data.records[data.students].lname, lname);
        strcpy(data.records[data.students].email, email);
        data.records[data.students].gpa   = gpa;
        data.students = recNum;
    }
    printData(data);
    cout << "\n\n";
}

void printData(struct roster data)
{
    for (int i=0; i < data.students; i++) {
        cout << "\n\nStudent[" << i << "]";
        printStudent(data.records[i]);
    }
}

void printStudent(struct student data)
{
    cout << "\nID:\t\t" << data.id;
    cout << "\nFIRST NAME:\t" << data.fname;
    cout << "\nLAST NAME:\t" << data.lname;
    cout << "\nEMAIL:\t\t" << data.email;
    cout << "\nGPA:\t\t" << data.gpa;
}

int searchId(struct roster data)
{
    int id;
    cout << "Search for student with ID: ";
    cin  >> id;
    for (int i=0; i < data.students; i++)
    {
        if (data.records[i].id == id)
            return i;
    }
    cout << "Couldn't find id in Data";
    return -1;
}

int searchLName(struct roster data)
{
    char lname[20];
    cout << "Search for student with Last Name: ";
    cin  >> lname;
    for (int i=0; i < data.students; i++)
    {
        if(strcmp(data.records[i].lname, lname) == 0)
            return i;
    }
    cout << "Couldn't find id in Data";
    return -1;
}

bool menu(struct roster data)
{
    int choice, id;
    cout << "\n********** Class Roster **********\nTotal Students = " << data.students;
    cout << "\n1. Display all students";
    cout << "\n2. Search a student by ID";
    cout << "\n3. Search a student by Last Name";
    cout << "\n4. Exit";
    cout << "\n>> ";
    cin >> choice;
    switch (choice) {
        case 1:
        cout << "\n\nShowing Records:";
        printData(data);
        break;
        case 2:
        id = searchId(data);
        if (id != -1)
            printStudent(data.records[id]);
        break;
        case 3:
        id = searchLName(data);
        if (id != -1)
            printStudent(data.records[id]);
        break;
        case 4:
        return false;
        break;
        default:
        return false;
        break;
    }
    return true;
}