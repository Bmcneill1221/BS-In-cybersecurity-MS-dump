// Blaze McNeill
#include <iostream> 
#include <cmath>
using namespace std;

void main()
{

	int x;
	float r, s;

	cout.precision(3);
	cout.setf(ios::fixed);

	cout << "What is x ";
	cin >> x;
	s = 2;
	r = (x / s + s) / 2;

	while (fabs(r - s) > .001)
	{

		s = r;
		r = (x / s + s) / 2;

	}

	cout << "The answer is " << r << endl;
}