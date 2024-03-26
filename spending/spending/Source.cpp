//Blaze McNeill
#include <iostream>
using namespace std;
int main()
{
	const int MONTHS_PER_YEAR = 12;
	const int PERCENT = 100;

	double amount, withdrawal, rate;
	int count, years, months;

	cout << "   Initical Amount?  ";
	cin >> amount;

	cout << "Monthly withdrawal?  ";
	cin >> withdrawal;

	cout << "     Interest rate?  ";
	cin >> rate;

	rate /= MONTHS_PER_YEAR * PERCENT;

	years = 0;
	months = 0;

	count = 0;

	do {
		months++;
		amount += rate * amount - withdrawal;
	} while (amount > withdrawal);

	years = months / 12;
	months = (years * 12) - months;
	
	if (months < 0)
		months *= -1;

	cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
	cout << "\nThe funds will last for " << years << " years and " << months << " months. \n";
	cout << "The amount of money left will be " << amount << ", which is less than "<< withdrawal <<" . " << endl;

}