#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

using namespace std;

struct Student {
  int id;
  char fname[20];
  char lname[20];
  char email[40];
  double gpa;
};

class GradeBook {
  public:
    GradeBook();
    void printAll();
    void printId(int id);
    void loadData();
    void menu();
  private:
    ifstream inStream;
    void addStudent(int id, char lname[], char fname[], char email[], double gpa);
    bool getRecord(int &recNum, int &id, char fname[], char lname[], char email[], double &gpa);
    int findName(char name[]);
    int findID(int id);
    int numStudents;
    Student students[100];
};

GradeBook::GradeBook() {
  numStudents = 0;
}


void GradeBook::printAll() {
  for (int i = 0; i < numStudents; i++) {
    cout << "Student @ Index =>" << i << endl;
    printId(i);
  }
}

void GradeBook::printId(int id) {
  if (id < numStudents) {
    cout << "Studnet ID:\t" << students[id].id << endl;
    cout << "First Name:\t" << students[id].fname << endl;
    cout << "Last Name:\t" << students[id].lname << endl;
    cout << "Email:\t\t" << students[id].email << endl;
    cout << "GPA:\t\t" << students[id].gpa << endl;
  }
}

void GradeBook::addStudent(int id, char lname[], char fname[], char email[], double gpa) {
  if (numStudents < 100) {
    students[numStudents].id = id;
    strcpy(students[numStudents].fname, fname);
    strcpy(students[numStudents].lname, lname);
    strcpy(students[numStudents].email, email);
    students[numStudents].gpa = gpa;
    numStudents++;
  }
}

void GradeBook::loadData() {
  int id, recNum = 0;
  char fname[20], lname[20], email[20];
  double gpa;
  while (getRecord(recNum, id, fname, lname, email, gpa)) {
    addStudent(id, lname, fname, email, gpa);
  }
}

bool GradeBook::getRecord(int &recNum, int &id, char fname[], char lname[], char email[], double &gpa) {
  if (recNum == 0) {
    inStream.open("prog8in.txt");
    if (inStream.fail()) {
      cout << "File \"prog8in.txt\" cannot be opened." << endl;
      cout << "Press ENTER to continue ...";
      cin.get();
      return false;
    } else cout << "File \"prog8in.txt\" opened." << endl;
  }
  inStream >> id >> fname >> lname >> email >> gpa;
  if (inStream.eof()) return false;
  else {
    recNum++;
    return true;
  }
}

int GradeBook::findID(int id) {
  for (int i = 0; i < numStudents; i++) {
    if (id == students[i].id) {
      return i;
    }
  }
  return -1;
}

int GradeBook::findName(char name[]) {
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(name, students[i].lname) == 0) {
      return i;
    }
  }
  return -1;
}

void GradeBook::menu() {
  while (true) {
    int choice, id;
    cout << "\n********** Class Roster **********"
         << "\nTotal Students = " << numStudents;
    cout << "\n1. Display all students";
    cout << "\n2. Search a student by ID";
    cout << "\n3. Search a student by Last Name";
    cout << "\n4. Exit";
    cout << "\n>> ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "\n\nShowing Records:";
        printAll();
        break;
      case 2:
        cout << "Search for student with ID: ";
        cin  >> id;
        id = findID(id);
        if (id != -1)
          printId(id);
        cout << "\n\nPress ENTER to continue...";
        cin.get();
        cin.get();
        break;
      case 3:
        char lname[20];
        cout << "Search for student with Last Name: ";
        cin  >> lname;
        id = findName(lname);
        if (id != -1)
          printId(id);
        cout << "\n\nPress ENTER to continue...";
        cin.get();
        cin.get();
        break;
      case 4:
        return;
        break;
      default:
        return;
        break;
    }
  }
}

int main() {
  GradeBook class_roster;
  class_roster.loadData();
  class_roster.printAll();
  class_roster.menu();
  return 0;
}