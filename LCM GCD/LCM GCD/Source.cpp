// Blaze McNeill
//
// GCD / LCM
//
#include <iostream>
using namespace std;

void lcm (int &num1, int &num2)
{
	int temp1, temp2;

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

	num1 = temp1;
}

void gcd (int &num1, int &num2)
{

	int temp1;

	temp1 = num1 % num2;

	while (temp1 != 0)
	{
		num1 = num2;
		num2 = temp1;
		temp1 = num1 % num2;
	}

	num1 = num2;
}

int main()
{
	int num1, num2, num3, num4 ,num5, num6; //will the answer to LCM overwrite num1/2 and call for me to save thoes numbers like num3/4? // YES

	cout << "  First number? ";
	cin >> num1;

	while (num1 != 0) //quit program check
	{
	
		cout << " Second number? ";
		cin >> num2;
		//saving orginal numbers
		num3 = num1;
		num4 = num2;

		lcm (num1, num2);

		cout << "\nThe lcm of " << num3 << " and " << num4 << " is " << num1 << endl;
		//saving orginal numbers
		num5 = num3;
		num6 = num4;

		gcd (num3, num4);

		cout << "The gcd of " << num5 << " and " << num6 << " is " << num3;

		cout << "\n \n First number? ";
		cin >> num1;
	}

}
