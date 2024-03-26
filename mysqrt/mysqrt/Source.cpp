//Blaze McNeill

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//"Missing function goes here"
double mysqrt(double x)
{

	double s, r;
	s = 2;
	r = (x / s + s) / 2; 

	if (r <= -1) // abaslute value
		r *= (-1);

	if (s <= -1)
		s *= (-1);

	while (r - s > .001)
	{
		s = r;
		r = (x / s + s) / 2;

		if (r <= -1) // abaslute value
			r *= -1;

		if (s <= -1)
			s *= -1;
	}

	cout.setf(ios::fixed);
	cout.precision(3);

	return r;
}

int  main()
{
	int cnt;

	cout.setf(ios::fixed);
	cout.precision(5);

	for (cnt = 1; cnt <= 16; cnt++)
	{
		cout << setw(10) << cnt;
		cout << setw(10) << sqrt(cnt);
		cout << setw(10) << mysqrt(cnt);
		cout << endl;
		
	}

}