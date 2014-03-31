// Assignment 9 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include "Document.cpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    // string w;
    // getline(cin, w);
    // for (int i = 0, len = w.size(); i < len; i++)
    //     w[i] = tolower(w[i]);
    // for (int i = 0, len = w.size(); i < len; i++)
    // {
    //     if (w[i] == '!' || w[i] == '"' || w[i] == '#' || w[i] == '$' || w[i] == '%' || w[i] == '&' ||
    //         w[i] == '(' || w[i] == ')' || w[i] == '*' || w[i] == '+' || w[i] == ',' || w[i] == ';' ||
    //         w[i] == '.' || w[i] == '/' || w[i] == ':' || w[i] == '<' || w[i] == '=' || w[i] == '>' ||
    //         w[i] == '?' || w[i] == '@' || w[i] == '[' || w[i] == '~' || w[i] == ']' || w[i] == '^' ||
    //         w[i] == '_' || w[i] == '`' || w[i] == '{' || w[i] == '|' || w[i] == '}' || w[i] == '\\'
    //         )
    //     {
    //         w.erase(i--, 1);
    //         len = w.size();
    //     }
    // }
    // cout << w;
    Document myDoc;
    myDoc.getInput();
    myDoc.printStats();
}