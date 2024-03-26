//Blaze McNeill
#include <iostream>
using namespace std;
int main()
{
	const int MONTHS_PER_YEAR = 12;
	const int PERCENT = 100;

	double amount, payment, rate;
	int count, years, months;

	cout << "Intitcal Amount? ";
	cin >> amount;

	cout << "Monthly payments? ";
	cin >> payment;

	cout << "Intrest rate ";
	cin >> rate;

	rate /= MONTHS_PER_YEAR * PERCENT;

	cout << "Numbers of years ";
	cin >> years;
	
		months = 12 * years;

		count = 0;

		do {
			count++;
			amount += rate * amount + payment;
		} while (count < months);
	
	cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
	cout << endl << "Total savings will be " << amount << endl;

}