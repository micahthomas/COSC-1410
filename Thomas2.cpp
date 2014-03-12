// 1410 Program 2
// Author: Micah Thomas
// TA: Can Cao
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
    char ans,ch;
    int ans_axle;
    float toll;

    do {
        cout << "\n------------------------------------\n";
        cout << "          TOLL CALCULATION          \n";
        cout << "------------------------------------\n\n";
        cout << "Does the vehicle have an EZ-TAG?(Y/N): ";
        cin  >> ans;
        if(ans == 'Y' || ans == 'y')
        {
            ans = 'y';
            cout << "\n>> Vehicle has EZ-TAG!\n\n";
        }
        else
        {
            cout << "\n>> Vehicle does not have EZ-TAG.\n\n";
        }
        cout << "How many axles does the vehicle have?: ";
        cin  >> ans_axle;
        cout << "\n>> The vehicle has "<<ans_axle<<" axle(s)\n\n";
        switch (ans_axle) {
        case 1:
        case 2:
            if (ans == 'y')
                toll = 1.45;
            else
                toll = 1.75;
            break;
        case 3:
            if (ans == 'y')
                toll = 3.50;
            else
                toll = 4.00;
            break;
        case 4:
            if (ans == 'y')
                toll = 5.25;
            else
                toll = 6.00;
            break;
        case 5:
            if (ans == 'y')
                toll = 7.00;
            else
                toll = 7.75;
            break;
        default:
            if (ans == 'y')
                toll = 8.75;
            else
                toll = 9.25;
        }
        cout << ">> Toll Charge: " << setprecision(3) << toll << setprecision(0);
        cout << "\n\nDo you wish to try again?(Y/N): ";
        cin >> ch;
    } while (!(ch=='n' || ch =='N'));
}

