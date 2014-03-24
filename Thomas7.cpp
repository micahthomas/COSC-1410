// Assignment 7 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

enum DIRECTION {EAST=1, WEST=2, NORTH=3, SOUTH=4};

const int BOARD_SIZE = 15;
const int CENTER = (BOARD_SIZE/2) - 1;

void init();
int getSteps();
void printSim(int board[][BOARD_SIZE], int x, int y);
int runSim(int board[][BOARD_SIZE], int steps, int &i, int &j);
bool walk(int &x, int &y, DIRECTION dir, int onBoard[][BOARD_SIZE]);

int main()
{
	int board[BOARD_SIZE][BOARD_SIZE] = {0}, steps = 0, i = 0, total = 0;
	init();
	steps = getSteps();
	board[CENTER][CENTER] = 1;
	int x=CENTER, y=CENTER;
	while (steps > 0) {
		i = runSim(board, steps, x, y);
		total += i;
		printSim(board, x, y);
		cout << "\nTotal Steps: " << total;
		if(i != steps) {
			cout << "\nPress any key to continue ...";
			cin.get();
			cin.get();
			return 0;
		}
		else
			steps = getSteps();
	}
	return 0;
}

void init()
{
	int seed;
	cout << "Seed: ";
	cin  >> seed;
	srand(seed);
}

int getSteps()
{
	int steps;
	cout << "\nNumber of steps (0 to stop): ";
	cin  >> steps;
	return steps;
}

void printSim(int board[][BOARD_SIZE], int i, int j)
{
	cout << "\n\n";
	for (int x=0; x < BOARD_SIZE; x++){
		cout << "\t";
		for (int y=0; y < BOARD_SIZE; y++){
			if (x == i && y == j)
				cout << "x";
			else
				cout << "-";
		}
		cout << "\t\t";
		for (int y=0; y < BOARD_SIZE; y++)
			cout << " " << board[x][y] << " ";
		cout << endl;
	}
}

int runSim(int board[][BOARD_SIZE], int steps, int &x, int &y)
{
	for (int i=steps; i > 0; i--)
	{
		DIRECTION dir = static_cast<DIRECTION>(rand()%4 + 1);
		if (!walk(x, y, dir, board)) {
			cout << "\nWalk over in " << (steps - i + 1) << " steps!\n";
			return (steps - i + 1);
		}
	}
	return steps;
}

bool walk(int &x, int &y, DIRECTION dir, int onBoard[][BOARD_SIZE])
{
	int i=x, j=y;
	cout << "\nWalking from ("<<x<<","<<y<<")";
	switch (dir) {
		case NORTH:
			y -= 1;
			cout << " NORTH ";
			break;
		case SOUTH:
			y += 1;
			cout << " SOUTH ";
			break;
		case EAST:
			x += 1;
			cout << " EAST ";
			break;
		case WEST:
			x -= 1;
			cout << " WEST ";
			break;
		default:
			break;
	}
	cout << " to ("<<x<<","<<y<<")";
	if ( (x > 14) || (y > 14) || (x < 0) || (y < 0)) {
		cout << "\nCan't walk outside of box";
		x=i;y=j;
		return false;
	}
	onBoard[y][x] += 1;
	return true;
}