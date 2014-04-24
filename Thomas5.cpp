// Assignment 5 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool repeat();

void getInput(int &seed, int &size, int &lower, int &upper);
void getStats(double &mean, double &std, int size, int lower, int upper);
int  getNum(int lower, int upper);
void getZ(double mean, double std);

int main() {
  int seed, size, lower, upper;
  double mean, std;
  getInput(seed, size, lower, upper);
  srand(seed);
  getStats(mean, std, size, lower, upper);
  cout << fixed << setprecision(5);
  cout << "\nMean: " << mean << " Std-deviation: " << std << endl;
  while (repeat()) {
    getZ(mean, std);
  }
}

void getInput(int &seed, int &size, int &lower, int &upper) {
  cout << "=======================================================\n";
  cout << "Seed for the random number generator: ";
  cin  >> seed;
  cout << "Size of the sequence: ";
  cin  >> size;
  cout << "Lower and upper bound for the random number: ";
  cin  >> lower >> upper;
  cout << "=======================================================\n";
}

void getStats(double &mean, double &std, int size, int lower, int upper) {
  double sum = 0, square_sum = 0;
  cout << "\nNumbers Generated:\n";
  for (int i = 0, current; i < size; i++) {
    current = getNum(lower, upper);
    cout << current << " ";
    sum += current;
    square_sum += pow(current, 2);
  }
  mean = sum / size;
  std = (square_sum - 2 * mean * sum + pow(mean, 2) * size) / size;
  std = sqrt(std);
}

int getNum(int lower, int upper) {
  return (rand() % upper + lower);
}

void getZ(double mean, double std) {
  double x, z;
  cout << "Enter the value to calculate the z-score: ";
  cin >> x;
  z = (x - mean) / std;
  cout << "Z-Score: for " << x << " is: " << z;
}

bool repeat() {
  char ans;
  cout << "\nDo you want to continue? (Y/N): ";
  cin >> ans;
  cout << "\n";
  if (tolower(ans) == 'n')
    return false;
  else
    return true;
}
