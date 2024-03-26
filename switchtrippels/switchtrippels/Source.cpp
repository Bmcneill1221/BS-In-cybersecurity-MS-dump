//Blaze McNeill
//
//tripel switch
//
#include <iostream>
using namespace std;

void order(double& num1, double& num2, double& num3)
{
	double temp1, temp2, temp3;

	if (num1 == num2 && num2 == num3)//are all numbers equal?
	{
		temp1 = num1;
		temp2 = num2;
		temp3 = num3;
	} 

	else if (num1 > num2)
	{
		temp1 = num1;

		if (num2 > num3)
		{
			temp2 = num2;
			temp3 = num3;
		}
		else if (num1 > num3)
		{
			temp2 = num3;
			temp3 = num2;
		}
	}

	else if (num2 > num3)
	{
		temp1 = num2;

		if (num1 > num3)
		{
			temp2 = num1;
			temp3 = num3;
		}
		else if (num3 > num1)
		{
			temp2 = num3;
			temp3 = num1;
		}
	}

	else if (num3 > num1)
	{
			temp1 = num3;

		if (num2 > num1)
		{
			temp2 = num2;
			temp3 = num1;
		}
		else
		{
			temp2 = num1;
			temp3 = num2;
		}
	}

	// ordering from gratest to least will be converted to least to greatest in main
	num1 = temp1;
	num2 = temp2;
	num3 = temp3;
}

int main()
{
	double num1, num2, num3;

	cout << " First number? ";
	cin >> num1;

	while (num1 != 0) //end loop check
	{

		cout  << "Second number? ";
		cin >> num2;
		cout << " Third number? ";
		cin >> num3;

		order(num1, num2, num3);

		cout << "\nThe ordered triple is: " << num3 << ", " << num2 << ", and " << num1 << endl; //output is in least to greatest

		cout << "\n First number? ";
		cin >> num1;
	}

}