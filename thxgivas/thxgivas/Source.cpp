//Blaze McNeill
//
//

#include <iostream>
#include <vector>
using namespace std;

void findbal(vector<int>& ssn, vector<double>& ball, int& ssntofind, bool& found, double& result)
{
	int pos;

	ssn = { 123,  234,  333,  401,  500 };
	ball = { 0.0,  100.5,  250.75,  50.12,  1225.0 };

	pos = 0;

	while (pos < 5 && ssn[pos] < ssntofind)

		pos++;

	if (pos < 5 && ssn[pos] == ssntofind)
	{
		result = ball[pos];
		found = 1;
	}
	else
		found = 0;

}

void  main()
{
	vector<int>  id(5);
	id = { 123,  234,  333,  401,  500 };

	vector<double>  bal(5);
	bal = { 0.0,  100.5,  250.75,  50.12,  1225.0 };

	double  result;
	int  idtofind;
	bool  found;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << "ID  to  find  ?  ";

	cin >> idtofind;

	while (idtofind > 0)
	{
		findbal(id, bal, idtofind, found, result);

		if (found)
			cout << "The  balance  is  " << result << endl;

		else
			cout << " Not  found" << endl;

	cout << "\n ID to find ?  ";

	cin >> idtofind;

	}

}