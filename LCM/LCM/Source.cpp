// Blaze McNeill
#include <iostream>
using namespace std;

void main()
{
	int num1, num2, temp1, temp2;

	cout << " Ask for X ";
	cin >> num1;
	cout << " Ask for Y ";
	cin >> num2;

	temp2 = 0;
	temp1 = 1;

		while (temp2 == 0)
		{
			while (temp1 % num1 != 0)
				temp1 = temp1 + 1;
			if (temp1 % num2 == 0)
				temp2 = 1;
			else
				temp1 = temp1 + 1;

		}
		cout << " The answer is " << temp1 << endl;





}