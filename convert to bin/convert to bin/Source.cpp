// Blaze McNeill
#include <iostream>
#include <cmath>
using namespace std;

void main()
{
	int p, x;
	char ans;

	cout << "Conver a number to binary?";
	cin >> ans;

		while (ans == 'y')
		{

			cout << "What is x ";
			cin >> x;
			p = 0;

				while (pow(2, p) <= x)
				p = p + 1;

			p = p - 1;

				while (p >= 0)
				{

					if (x >= pow(2, p))
					{
						cout << "1";
						x = x - pow(2, p);
					}

					else
						cout << "0";
					
					p = p - 1;

				}

				cout << endl << endl;
				cout << "Conver a number to binary?";
				cin >> ans;

		}

}