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
    void sortData();
  private:
    ifstream inStream;
    ofstream outStream;
    char inFile[40];
    char outFile[40];
    int numStudents;
    Student students[100];
    void addStudent(
      int id, char lname[], char fname[], char email[], double gpa
    );
    int deleteStudent(int id);
    int findID(int id);
};

GradeBook::GradeBook() {
  numStudents = 0;
  strcpy(inFile, "prog10in.txt");
  strcpy(outFile, "prog10out.txt");
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
      outStream << students[i].id
                << " " << students[i].fname
                << " " << students[i].lname
                << " " << students[i].email
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

void GradeBook::sortData() {
  int i, k, indexOfNextSmallest;
  Student temp;
  for (i = 0; i < numStudents - 1; i++) {
    indexOfNextSmallest = i;
    for (k = i + 1; k < numStudents; k++)
      if (students[k].id < students[indexOfNextSmallest].id)
        indexOfNextSmallest = k;
    temp.id = students[i].id;
    strcpy(temp.fname, students[i].fname);
    strcpy(temp.lname, students[i].lname);
    strcpy(temp.email, students[i].email);
    temp.gpa = students[i].gpa;
    students[i].id = students[indexOfNextSmallest].id;
    strcpy(students[i].fname, students[indexOfNextSmallest].fname);
    strcpy(students[i].lname, students[indexOfNextSmallest].lname);
    strcpy(students[i].email, students[indexOfNextSmallest].email);
    students[i].gpa = students[indexOfNextSmallest].gpa;
    students[indexOfNextSmallest].id = temp.id;
    strcpy(students[indexOfNextSmallest].fname, temp.fname);
    strcpy(students[indexOfNextSmallest].lname, temp.lname);
    strcpy(students[indexOfNextSmallest].email, temp.email);
    students[indexOfNextSmallest].gpa = temp.gpa;
  }
}

void GradeBook::menu() {
  while (true) {
    int choice, id;
    cout << "\n********** Class Roster **********"
         << "\nTotal Students = " << numStudents;
    cout << "\n1. Display all students";
    cout << "\n2. Sort Students by ID";
    cout << "\n3. Add a new student";
    cout << "\n4. Delete student by ID";
    cout << "\n5. Save student records into file";
    cout << "\n6. Exit";
    cout << "\n>> ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "\n\nShowing Records:\n";
        printAll();
        break;
      case 2:
        sortData();
        cout << "\n\nSorted Students by ID\n";
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
  if (argc == 3)
    class_roster.setFiles(argv[1], argv[2]);
  class_roster.loadData();
  class_roster.menu();
  return 0;
}