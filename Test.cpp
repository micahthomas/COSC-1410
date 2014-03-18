// Author: Micah Thomas
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sys/time.h>
using namespace std;

const int SIZE = 1000000;

int find(int num, int size, int array[]);
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}
int main() {
    timestamp_t t0 = get_timestamp();
    int book[SIZE] = {0};
	book[SIZE-1] = 10;
	for (int i=0; i<1000; i++)
		find(10, SIZE, book);
    timestamp_t t1 = get_timestamp();

    double secs = (t1 - t0) / 1000000.0L;
	cout << secs;
}

int find(int num, int size, int array[]){
	for(int i=0; i<size; i++)
	{
		if (array[i] == num)
			return num;
	}
	return 0;
}