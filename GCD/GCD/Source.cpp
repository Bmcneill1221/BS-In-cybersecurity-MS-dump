// Blaze McNeill
#include <iostream>
using namespace std;

int main()
{
	int x, y, t;

	cout << "What is X ";
	cin >> x;
	cout << "What is y ";
	cin >> y;
	t = x % y;

		while (t != 0)
		{

			x = y;
			y = t;
			t = x % y;

		}

		cout << " The answer is " << y << endl;
}