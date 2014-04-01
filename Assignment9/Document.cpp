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
    string removePunct(string w);
    string toLowerCase(string w);
    int getWord(string w);
    void addWord(string w);
    void sortWords();
};

Document::Document()
{
    numUnique = 0;
    numWords = 0;
    // words[0].word = "hello";
    // words[0].count = 1;
}

int Document::getWord(string w)
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

void Document::addWord(string w)
{
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

string Document::toLowerCase(string w)
{
    for (int i = 0, len = w.size(); i < len; i++)
        w[i] = tolower(w[i]);
    return w;
}

string Document::removePunct(string w)
{
    for (int i = 0, len = w.size(); i < len; i++)
    {
        if (
            w[i] == '!' || w[i] == '"' || w[i] == '#' || w[i] == '$' || w[i] == '%' || w[i] == '&' ||
            w[i] == '(' || w[i] == ')' || w[i] == '*' || w[i] == '+' || w[i] == ',' || w[i] == ';' ||
            w[i] == '.' || w[i] == '/' || w[i] == ':' || w[i] == '<' || w[i] == '=' || w[i] == '>' ||
            w[i] == '?' || w[i] == '@' || w[i] == '[' || w[i] == '~' || w[i] == ']' || w[i] == '^' ||
            w[i] == '_' || w[i] == '`' || w[i] == '{' || w[i] == '|' || w[i] == '}' || w[i] == ' ' ||
            w[i] == '\\'
        )
        {
            w.erase(i--, 1);
            len = w.size();
        }
    }
    return w;
}

void Document::getInput()
{
    cout << "Please enter some sentences below. A word '###' terminate the input.\n";
    string text;
    while (true)
    {
        cin >> text;
        if (text == "###")
            break;
        text = toLowerCase(text);
        text = removePunct(text);
        addWord(text);
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

void Document::printStats()
{
    sortWords();
    cout << "+--------------------------------+------------+"
         << "\n| " << left << setw(30) << "Total Number of Words " << " | "
         << right << setw(10) << numWords << " |"
         << "\n| " << left << setw(30) << "Total Unique Words " << " | "
         << right << setw(10) << numUnique << " |"
         << "\n+--------------------------------+------------+";
    for (int i = 0; i < numUnique; i++)
    {
        cout << "\n| " << left << setw(30) << words[i].word << " | " << right << setw(10) << words[i].count << " |";
    }
    cout << "\n+--------------------------------+------------+";
}