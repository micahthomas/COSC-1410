// Assignment 7 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int BOARD_SIZE = 16;
const int CENTER = (BOARD_SIZE/2) - 1;

void init();
void printSim(int board[][BOARD_SIZE]);
int  runSim(int board[][BOARD_SIZE], steps)

int main() {
	int board[BOARD_SIZE][BOARD_SIZE] = {0}, steps = 0;
	init(steps);
	runSim(board);
	printSim(board);
}

void printSim(int board[][BOARD_SIZE])
{
	for (int x=0; x < BOARD_SIZE; x++){
		for (int y=0; y < BOARD_SIZE; y++){
			cout << " " << board[x][y] << " ";
		}
		cout << endl;
	}
}