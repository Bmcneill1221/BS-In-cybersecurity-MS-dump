//Blaze McNeill
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int MONTHS_PER_YEAR = 12;
	const int PERCENT = 100;

	double amount, payment, rate, amounttwo, amountthree, store, amountone;
	int count, years, months, yearstwo;
	
	cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
	
	cout << "Intitcal Amount? ";
	cin >> amount;

	cout << "Monthly payments? ";
	cin >> payment;

	cout << "Intrest rate ";
	cin >> rate;

	rate /= MONTHS_PER_YEAR * PERCENT;

	cout << "Numbers of years ";
	cin >> years;

	yearstwo = 1;
	amountone = 0;

	months = 12;
	do {
		count = 0;

		amountone = amount;

		store = amount; 
		
		do {
			count++;
			amount += rate * amount + payment;
			} while (count < months);

		amounttwo = amount - store; 

		amountthree = amounttwo + amount; 

		cout << "Year Starting Balance      Interest Gained      Ending Balance" << endl;
		cout << setw(4) << yearstwo << "       " << setw(10) << amountone << "           " << setw(10) << amounttwo << "          " << setw(10) << amount << endl;

		yearstwo ++;

		} while (years >= yearstwo);

}