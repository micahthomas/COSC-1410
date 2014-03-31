#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct word {
	string word;
	int count;
};

class Document
{
public:
	Document();
	void printStats();
	void getDocument();

private:
	word words[];
	int numWords;
	int numUnique; 
	string removePunct();
	string toLowerCase();
	void sortWords();
};