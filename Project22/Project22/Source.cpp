// Blaze McNeill
#include <iostream>
using namespace std;

bool isalpha(char input) {

	if (input >= 65 && input <= 90 || input >= 97 && input <= 122)
		return 1;
	else
	{
		return 0;
	}

}

int main()
{
 
	char data;

	cout << "input" <<endl;
	cin >> data;

	cout<< isalpha(data);

}