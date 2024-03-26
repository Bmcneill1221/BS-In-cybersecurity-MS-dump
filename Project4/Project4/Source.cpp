//Blaze McNeill
//
// Money Check Lab
// 
// tens place in million and thousands broken
//
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int main() {

	vector<int> b(6);
	int ans, i;
	b = { 60, 50, 1, 1, 20, 10 };

	for (i = 0; i < 6; i++)
	{
		cout << setw(3) << b[i];
		if ((i + 1) % 2 == 0)
			cout << endl;
	}


}