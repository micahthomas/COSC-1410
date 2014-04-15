// Assignment 10 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>

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
    void saveData();
    void menu();
    void setFiles(char in[], char out[]);
    void setFiles();
  private:
    ifstream inStream;
    ofstream outStream;
    char inFile[40];
    char outFile[40];
    void addStudent(
      int id, char lname[], char fname[], char email[], double gpa
    );
    int deleteStudent(int id);
    int findID(int id);
    int numStudents;
    Student students[100];
};

GradeBook::GradeBook() {
  numStudents = 0;
  inFile = "prog10in.txt";
  outFile = "prog10out.txt";
  students[0].id = 0;
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

void GradeBook::addStudent(
  int id, char lname[], char fname[], char email[], double gpa
) {
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
  int id;
  char fname[20], lname[20], email[20];
  double gpa;
  inStream.open(inFile);
  if (inStream.fail()) {
    cout << "File cannot be opened." << endl;
    cout << "Press ENTER to continue ...";
    cin.get();
    return;
  } else {
    inStream >> id >> fname >> lname >> email >> gpa;
  }
  while (!inStream.eof()) {
    addStudent(id, lname, fname, email, gpa);
    inStream >> id >> fname >> lname >> email >> gpa;
  }
}
void GradeBook::saveData() {
  outStream.open(outFile, ofstream::out);
  if (outStream.fail()) {
    cout << "File cannot be opened." << endl;
    cout << "Press ENTER to continue ...";
    cin.get();
  } else {
    for (int i = 0; i < numStudents; i++) {
      outStream << students[i].id << " " << students[i].fname
                << " " << students[i].lname << " " << students[i].email
                << " " << students[i].gpa << "\n";
    }
    outStream.close();
  }
}
void GradeBook::setFiles(char in[], char out[]) {
  strcpy(inFile, in);
  strcpy(outFile, out);
}
int GradeBook::findID(int id) {
  for (int i = 0; i < numStudents; i++) {
    if (id == students[i].id) {
      return i;
    }
  }
  return -1;
}

int GradeBook::deleteStudent(int id) {
  for (int i = 0; i < numStudents; i++) {
    if (id == students[i].id) {
      for (int j = i; j < numStudents; j++)
        students[j] = students[j + 1];
      students[numStudents - 1].id = 0;
      students[numStudents - 1].gpa = 0;
      strcpy(students[numStudents - 1].fname, " ");
      strcpy(students[numStudents - 1].lname, " ");
      strcpy(students[numStudents - 1].email, " ");
      numStudents -= 1;
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
    cout << "\n3. Add a new student";
    cout << "\n4. Delete student by ID";
    cout << "\n5. Save student records into file";
    cout << "\n6. Exit";
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
        else
          cout << "Could not find student with that id";
        cout << "\n\nPress ENTER to continue...";
        cin.get();
        cin.get();
        break;
      case 3:
        char lname[20], fname[20], email[40];
        double gpa;
        cout << "Adding a new student\n";
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter First Name: ";
        cin >> fname;
        cout << "Enter Last Name: ";
        cin >> lname;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter GPA: ";
        cin >> gpa;
        addStudent(id, lname, fname, email, gpa);
        break;
      case 4:
        cout << "Delete student with ID: ";
        cin  >> id;
        id = deleteStudent(id);
        if (id != -1)
          cout << "Deleted Student @ index " << id;
        else
          cout << "Could not find student with that id";
        cout << "\n\nPress ENTER to continue...";
        cin.get();
        cin.get();
        break;
      case 5:
        saveData();
        cout << "Saved data succesfully!\n";
        break;
      default:
        return;
    }
  }
}

int main(int argc, char *argv[]) {
  GradeBook class_roster;
  if (argc == 2)
    class_roster.setFiles(argv[0], argv[1]);
  else
    class_roster.setFiles();
  class_roster.loadData();
  class_roster.menu();
  return 0;
}