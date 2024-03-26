// Blaze McNeill
#include <iostream>
using namespace std;
void main()
{

	int p, d, n;

	cout << "what is n? ";
	cin >> n;
	p = 1;

	while (p < n)
		p = p * 16;

	p = p / 16;

	do
	{

		if (n >= p)
		{

			d = n / p;
			n = n - d * p;

			if (d <= 9)

				cout << d;

			else
			{
				if (d == 10)

					cout << "A";

				else if (d == 11)

					cout << "B";

				else if (d == 12)

					cout << "C";

				else if (d == 13)

					cout << "D";

				else if (d == 14)

					cout << "E";

				else if (d == 15)

					cout << "F";

			}
		}
		else
		{
			cout << "0";
		}

		p = p / 16;

	}

	while (p > 0);

}