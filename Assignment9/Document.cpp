#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cctype>

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
    Word words[];
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
}

int Document::getWord(string w)
{
    for (int i = 0; i < numUnique; i++)
    {
        if (words[i].word == w)
        {
            cout << i;
            return i;
        }
    }
    return -1;
}

void Document::addWord(string w)
{
    int idx = getWord(w);
    if (idx != -1)
    {
        words[numUnique].word = w;
        words[numUnique].count = 1;
        numWords++;
    }
    else
    {
        words[idx].count++;
        numWords++;
        numUnique++;
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

void Document::printStats()
{
    for (int i = 0; i < numUnique; i++)
    {
        cout << "Word: " << words[numUnique].word
             << "Count: " << words[numUnique].count
             << endl;
    }
}