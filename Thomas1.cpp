#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  const float
  a_rent = 1200.00,
  c_cable = 55.99,
  c_internet = 45.00,
  c_phone = 39.50,
  a_room = 1,
  b_room = .5,
  c_room = .5,
  tenants = 3;
  float
  b_gas_bill,
  b_elec_bill,
  a_total,
  b_total,
  c_total,
  a_coll,
  b_pay,
  c_pay,
  total_util;

  // get intial values
  cout << left << setw(35) << "Bob: Gas Bill:" << "$ ";
  cin >> b_gas_bill;
  cout << setw(35) << "Bob: Electricity Bill:" << "$ ";
  cin >> b_elec_bill;

  // num of tenants
  cout << "\n---------------------------------------------------------------------------\n";
  cout << setw(35) << "Number of tenants:" << tenants << endl << endl;

  // setprecision to 2 before starting to print out floats
  cout << fixed << setprecision(2);
  cout << left  << setw(35) << "Rent:" << "$"
       << right << setw(8)  << a_rent << " A" << endl;

  cout << left  << setw(35) << "Electricity:" << "$"
       << right << setw(8)  << b_elec_bill << " B" << endl;

  cout << left  << setw(35) << "Gas:" << "$"
       << right << setw(8)  << b_gas_bill << " B" << endl;

  cout << left  << setw(35) << "Cable:" << "$"
       << right << setw(8)  << c_cable << " C" << endl;

  cout << left  << setw(35) << "Phone:" << "$"
       << right << setw(8)  << c_phone << " C" << endl;

  cout << left  << setw(35) << "Internet:" << "$"
       << right << setw(8)  << c_internet << " C" << endl << endl;

  total_util = b_gas_bill + b_elec_bill + c_cable + c_phone + c_internet;

  cout << left  << setw(35) << "Total Utilities:" << "$"
       << right << setw(8)   << total_util << endl << endl;

  a_total = ((a_rent / (a_room + b_room + c_room)) * a_room) + (total_util / 3);
  b_total = ((a_rent / (a_room + b_room + c_room)) * b_room) + (total_util / 3);
  c_total = ((a_rent / (a_room + b_room + c_room)) * c_room) + (total_util / 3);

  cout << left  << setw(35) << "Total for Adam:" << "$"
       << right << setw(8)  << a_total << endl;
  cout << left  << setw(35) << "Total for Bob:" << "$"
       << right << setw(8)  << b_total << endl;
  cout << left  << setw(35) << "Total for Charles:" << "$"
       << right << setw(8)  << c_total << endl << endl;

  b_pay = b_total - (b_gas_bill + b_elec_bill);
  c_pay = c_total - (c_phone + c_internet + c_cable);
  a_coll = b_pay + c_pay;

  cout << left  << setw(35) << "Bob must pay Adam:" << "$"
       << right << setw(8)  << b_pay << endl;
  cout << left  << setw(35) << "Charles must pay Adam:" << "$"
       << right << setw(8)  << c_pay << endl;
  cout << left  << setw(35) << "Adam will collect:" << "$"
       << right << setw(8)  << a_coll << " from Bob and Charles.";
  cout << "\n---------------------------------------------------------------------------\n";

  //system pause
  cin.get();// first one for the catching random \n
  cin.get();
}
