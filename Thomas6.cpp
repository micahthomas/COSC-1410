// Assignment 6 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//GLOBALS
const int MAX_HEIGHT = 5;
const int MIN_HEIGHT = 0;

//FUNCTIONS
void clearArray(int array[], int size);
void printArray(int array[], int size);
void diffArray(int map[], int msize, int target[], int tsize);
bool getTarget(int target[], int& tsize);
void pause();

int main() {
	int map[18] = {
		2, 1, 3, 1, 1, 2, 3, 5, 3, 2, 1, 0, 2, 1, 2, 4, 1, 2
	};
	int target[] = {0}, tsize = 0;
	while (true) {
		clearArray(target, tsize);
		if (!getTarget(target, tsize))
			break;
		cout << "\nTHE MAP:";
		printArray(map, 18);
		cout << "\nTHE TARGET:";
		printArray(target, tsize);
		pause();
		diffArray(map, 18, target, tsize);
		pause();
	}
	return 0;
}

void clearArray(int array[], int size) {
	if (size == 0)
		array[0] = 0;
	else
		for (int i=0; i<size; i++)
			array[i] = 0;
}

void printArray(int array[], int size) {
	cout << "\n\n";
	for (int j=MAX_HEIGHT; j>MIN_HEIGHT; j--) {
		for (int i=0; i<size; i++) {
			if(array[i] >= j)
				cout << " = ";
			else
				cout << "   ";
		}
		cout << endl;
	}
	for (int i=0; i<size; i++)
		cout << "---";
	cout << "\n\n";
}

void diffArray(int map[], int msize, int target[], int tsize) {
	int targets = (msize-tsize), i, diff, min=MAX_HEIGHT*tsize, cord;
	for (i=0; i<=targets; i++) {
		cout << "\nDiff\t(" << i << ", " << i+(tsize-1) << ")";
		diff = 0;
		for (int j=0; j<tsize; j++)
			diff += abs(map[j+i] - target[j]);
		if (diff < min) {
			min = diff;
			cord = i;
		}
		cout << " = " << diff;
	}
	cout << "\n\nThe Closest Cords to Target is (" << cord << ", "
		 << cord+(tsize-1) << ") with difference of " << min << "\n\n";
}

bool getTarget(int target[], int& tsize) {
	cout << "Enter the size of the target: ";
	cin >> tsize;
	if (tsize == 0)
		return false;
	cout << "Enter " << tsize << " integers between " <<MAX_HEIGHT
		 << " and " << MIN_HEIGHT << ": ";
	for (int i=0; i<tsize; i++)
		cin >> target[i];
	return true;
}

void pause() {
	cout << "Press Enter to CONTINUE: ";
	cin.get();
	cin.get();
}