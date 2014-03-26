// Assignment 4 - COSC 1410
// TA: Can Cao
// Author: Micah Thomas
#include <iostream>
#include <iomanip>

using namespace std;

enum ExchType { BUY, SELL };                // ENUMERATION

int printMenu(double &rate);                // PRINTS MENU & RETURNS USER's CHOICE
int logic(int test, double &rate);         // CHOSES ACTION Based on test

double getBuyRate(double rate);             // RETURNS Profitable buy rate for peso
double getSellRate(double rate);            // RETURNS Profitable sell rate for peso

void setRate(double &rate);                 // SETS Rate to user input
void showRate(double rate);                 // PRINTS BUY & SELL multipliers based on rate

void exchange(ExchType exch, double amount, double rate); // PRINTS Exchange Amount

int main()
{
    cout << "######## ##     ##  ######  ##     ##    ###    ##    ##  ######   ########" << endl
         << "##        ##   ##  ##    ## ##     ##   ## ##   ###   ## ##    ##  ##      " << endl
         << "##         ## ##   ##       ##     ##  ##   ##  ####  ## ##        ##      " << endl
         << "######      ###    ##       ######### ##     ## ## ## ## ##   #### ######  " << endl
         << "##         ## ##   ##       ##     ## ######### ##  #### ##    ##  ##      " << endl
         << "##        ##   ##  ##    ## ##     ## ##     ## ##   ### ##    ##  ##      " << endl
         << "######## ##     ##  ######  ##     ## ##     ## ##    ##  ######   ########" << endl
         << "===========================================================================" << endl;
    double exchrate = 13.3;
    int menu, loop;
    do
    {
        menu = printMenu(exchrate);
        cout << "\n====================================================";
        loop = logic(menu, exchrate);       // RETURNS 0 if user wants to exit; 0 to continue;
        cout << "\n====================================================\n";
        if (loop)                           // IF user wants to exit, dont pause
        {
            cout << "\nPress ENTER to continue";
            cin.get();
            cin.get();
        }
    }
    while (loop);
    return 0;
}

int printMenu(double &rate)
{
    int choice;
    cout << fixed << setprecision(4)
         << "\n+--------------------------------------------------+"
         << "\n| CURRENCY EXCHANGE: Mexican Pesos <==> US Dollars |"
         << "\n+-------------------+--------------+---------------+"
         << "\n|                   | Buying Pesos | Selling Pesos |"
         << "\n+-------------------+--------------+---------------+"
         << "\n| $1 =              | " << setw(8) << getBuyRate(rate)
         << " MXN | " <<
         setw(9) << getSellRate(rate)
         << " MXN |"
         << "\n+-------------------+--------------+---------------+"
         << "\n| Select the option:                               |"
         << "\n| 1. Pesos to Dollars                              |"
         << "\n| 2. Dollars to Pesos                              |"
         << "\n| 3. Change Exchange Rate                          |"
         << "\n| 4. Show Exchange Rate                            |"
         << "\n| 5. Exit the program                              |"
         << "\n+--------------------------------------------------+"
         << "\n"
         << "\n>> "
         << fixed << setprecision(2);
    cin  >> choice;
    return choice;
}

int cont()
{
    char ch;
    cout << "\n\nWould you like to continue? [Y/N]:";
    cin  >> ch;
    if ((ch == 'n') || (ch == 'N'))
        return 0;
    return 1;
}

int logic(int test, double &rate)
{
    switch (test)
    {
        double amount;
    case 1:
        cout << "\nHow many Pesos would you like to Exchange? ";
        cin >> amount;
        exchange(SELL, amount, rate);
        return 1;
    case 2:
        cout << "\nHow many USD would you like to Exchange? ";
        cin >> amount;
        exchange(BUY, amount, rate);
        return 1;
    case 3:
        setRate(rate);
        return 1;
    case 4:
        showRate(rate);
        return 1;
    case 5:
        return 0;
    default:
        return 1;
    }
}

double getBuyRate(double rate)
{
    return rate * .93;
}

double getSellRate(double rate)
{
    return rate * 1.07;
}

void setRate(double &rate)
{
    cout << "\nThe current rate is: " << rate
         << "\nWhat would you like to set the rate to? ";
    cin >> rate;
}

void showRate(double rate)
{
    cout << "\nPesos => USD: " << getSellRate(rate)
         << "\nUSD => Pesos: " << getBuyRate(rate);
}

void exchange(ExchType exch, double amount, double rate)
{
    if (exch == BUY)
    {
        cout << "\nYou will get " << amount *getBuyRate(rate) << " Pesos.";
    }
    else
    {
        cout << "\nYou will get " << amount / getSellRate(rate) << " USD.";
    }
}
