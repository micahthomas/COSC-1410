// Assignment 9 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

struct Word
{
    string word;
    int count;
};

class Document
{
public:
    Document();
    void printStats();
    void getInput();

private:
    Word words[200];
    int numWords;
    int numUnique;
    void removePunct(string &w);
    void toLowerCase(string &w);
    int getWord(const string &w);
    void addWord(string &w);
    void sortWords();
    void printLine(int i, int j);
};

Document::Document()
{
    numUnique = 0;
    numWords = 0;
}

int Document::getWord(const string &w)
{
    for (int i = 0; i < numUnique; i++)
    {
        if (words[i].word == w)
        {
            return i;
        }
    }
    return -1;
}

void Document::addWord(string &w)
{
    toLowerCase(w);
    removePunct(w);
    int idx = getWord(w);
    if (idx == -1)
    {
        words[numUnique].word = w;
        words[numUnique].count = 1;
        numWords++;
        numUnique++;
    }
    else
    {
        words[idx].count++;
        numWords++;
    }
}

void Document::toLowerCase(string &w)
{
    for (int i = 0, len = w.size(); i < len; i++)
        w[i] = tolower(w[i]);
}

void Document::removePunct(string &w)
{
    for (int i = 0, len = w.size(); i < len; i++)
    {
        if (
            w[i] == '!' || w[i] == '"' || w[i] == '#' ||
            w[i] == '$' || w[i] == '%' || w[i] == '&' ||
            w[i] == '(' || w[i] == ')' || w[i] == '*' ||
            w[i] == '+' || w[i] == ',' || w[i] == ';' ||
            w[i] == '.' || w[i] == '/' || w[i] == ':' ||
            w[i] == '<' || w[i] == '=' || w[i] == '>' ||
            w[i] == '?' || w[i] == '@' || w[i] == '[' ||
            w[i] == '~' || w[i] == ']' || w[i] == '^' ||
            w[i] == '_' || w[i] == '`' || w[i] == '{' ||
            w[i] == '|' || w[i] == '}' || w[i] == ' ' ||
            w[i] == '\\'
        )
        {
            w.erase(i--, 1);
            len = w.size();
        }
    }
}

void Document::sortWords()
{
    int i, k, indexOfNextBiggest, temp_count;
    string temp_word;
    for (i = 0; i < numUnique - 1; i++)
    {
        indexOfNextBiggest = i;
        for (k = i + 1; k < numUnique; k++)
            if (words[k].count > words[indexOfNextBiggest].count)
                indexOfNextBiggest = k;
        temp_count = words[i].count;
        temp_word = words[i].word;
        words[i].count = words[indexOfNextBiggest].count;
        words[i].word = words[indexOfNextBiggest].word;
        words[indexOfNextBiggest].count = temp_count;
        words[indexOfNextBiggest].word = temp_word;
    }
}

void Document::printLine(int i, int j)
{
    cout << "\n| " << left << setw(20) << words[i].word
         << " | " << right << setw(5) << words[i].count << " | ";
    if (j == 0)
    {
        cout << left << setw(19) << " "
             << " | " << right << setw(5) << " " << " |";
    }
    else
    {
        cout << left << setw(19) << words[j].word
             << " | " << right << setw(5) << words[j].count << " |";
    }
}

void Document::getInput()
{
    cout << "Please enter some sentences below. "
         << "A word '###' terminate the input.\n";
    string text;
    while (true)
    {
        cin >> text;
        if (text == "###")
            break;
        addWord(text);
    }
}

void Document::printStats()
{
    sortWords();
    cout << "+----------------------------------------------------+-------+"
         << "\n| " << left << setw(50) << "Total Number of Words " << " | "
         << right << setw(5) << numWords << " |"
         << "\n| " << left << setw(50) << "Total Unique Words " << " | "
         << right << setw(5) << numUnique << " |"
         << "\n+----------------------+-------+---------------------+-------+";
    if (numUnique == 0) return;     // Dont display anything more if no words
    int half = numUnique / 2;
    if (half == 0)                  // If only one word
    {
        printLine(0, 0);
    }
    else                            // More than one word
    {
        for (int i = 0; i < half; i++)
        {
            printLine(i, i + half);
        }
        if ((half * 2) != numUnique)// If odd number of words
        {
            printLine(numUnique - 1, 0);
        }

    }
    cout << "\n+----------------------+-------+---------------------+-------+";
}

int main()
{
    Document myDoc;
    myDoc.getInput();
    myDoc.printStats();
}