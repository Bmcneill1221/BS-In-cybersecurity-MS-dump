// Blaze McNeill
#include <iostream>
using namespace std;

void main()
{
	int x, d, r;

		cout << "What is x "; 
		cin >> x;
		d = 2;
		cout << "The factors are ";

			while (d <= x)
		{
				r = x % d;

				if (r == 0)
				{

					cout << d;
					x = x / d;
					if (x != 1)
						cout << " * ";

				}

				else
					d = d + 1;

		}


}