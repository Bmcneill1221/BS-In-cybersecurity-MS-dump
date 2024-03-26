//Blaze McNeill
//
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> names;
	int pass, pos;
	string temp;

	string currentname = " ";

	while (currentname != "")
	{
		cout << "Name? ";
	 	getline(cin, currentname);
	 	names.push_back(currentname);
	 
	}
	names.pop_back();
	int maxnum = names.size();

	for (pass = 0; pass < maxnum*2 - 1; pass++) {
		for (pos = 0; pos < maxnum - pass - 1; pos++) {
			if (names[pos][0] > names[pos + 1][0]) {
				temp = names[pos];
				names[pos] = names[pos + 1];
				names[pos + 1] = temp;
			} else if (names[pos][0] == names[pos + 1][0]) {
				if (names[pos][1] > names[pos + 1][1]) {
					temp = names[pos];
					names[pos] = names[pos + 1];
					names[pos + 1] = temp;
				}
			}
		}
	}

	cout << "\nThe sorted names are:\n";
	for (int i = 0; i < names.size();i++) {
		cout << names[i] << endl;
	}
}