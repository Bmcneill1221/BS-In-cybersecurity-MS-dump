// Blaze McNeill
#include <iostream>
using namespace std;

void main()
{
	char preference;
	int p, c, d;

	c = 0;
	p = 0;
	d = 0;

	cout << "Do you perfer Coke, Dr. Pepper, or Pepsi? ";
	cin >> preference;

	while (preference != 'q' && preference != 'Q') 
	{
		if (preference == 'p' || preference == 'P')
			p++;
		else if (preference == 'c' || preference == 'C')
			c++;
		else if (preference == 'd' || preference == 'D')
			d++;

		cout << "Do you perfer Coke, Dr. Pepper or Pepsi? ";
		cin >> preference;
	}

	cout << "Total Pepsi " << p << " Total Coke " << c << " Total Dr. Pepper " <<d << " ";

	// !!! when d || c || p =1 and d || c || p both =0 then skips first if loop and outputs nothing 
	
	if (p != c && p != d && c != d)
	{
		if (p > c && p != 0)
			cout << "Pepsi wins ";
		else if (c > p && c != 0)
			cout << "Coke wins ";
		else if (d > p)
			cout << "Dr. Pepper wins ";
	}
	
	if (c == d && d == p && c == p)
		cout << "Coke, Dr.Pepper, and Pepsi tie " << " ";
	else if (p == c && p != 0)
		cout << "Coke and Pepsi tied " << " ";
	else if (p == d && d != 0)
		cout << "Pepsi and Dr. Pepper tied " << " ";
	else if (c == d && c != 0)
		cout << "Coke and Dr. Pepper tied " << " ";

}