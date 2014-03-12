// COSC 1410 - Assignment 3
// Author: Micah Thomas
// TA: Can Cao
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char ch;
    double principal, rate, time, current_balance, interest, i;
    int j;
    do {
        cout << "\nInitial Deposit: $";
        cin  >> principal;

        cout << "\nInterest Rate: (%) ";
        cin  >> rate;

        cout << "\nNumber of Year(s): ";
        cin  >> time;

        cout << "\n\n\nBalances at the end of each year:\n\n\n";

        cout << fixed << setprecision(2);
        for (i=(rate-.1); i < (rate+.2); i+=.1 )
        {
            cout << "\nRate => " << i << "%";
            cout << "\n   +-------+----------------------+-----------+----------------------+";
            cout << "\n   |       | Beginning            |           | Ending               |";
            cout << "\n   |  Year | Balance              | Interest  | Balance              |";
            cout << "\n   +-------+----------------------+-----------+----------------------+";
            cout << "\n   |       |                      |           |                      |";
            current_balance = principal;
            for (j=1; j <= (time+1); j++)
            {
                interest = current_balance * (rate/100);
                cout << "\n   | "<< right << setw(5) << j << " | "<< setw(20) <<
                        left << current_balance << " | " << setw(9) << right << interest;
                current_balance = current_balance + interest;
                cout << " | " << setw(20) << left << current_balance << " |";

            }
            cout << "\n   +-------+----------------------+-----------+----------------------+";
            cout << "\n";
        }

        cout << "Would you like to continue? (Y/N):";
        cin >> ch;
    } while (tolower(ch) != 'n');
}
