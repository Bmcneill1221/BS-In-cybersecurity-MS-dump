#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int howMany,temp;
	char name1;
	char name2;
	char name3;
	char ch;

	cin >> howMany;

	cin >> name1;

	for (int i = 0; i < strlen(name1); i++) {

		// convert str[i] to uppercase
		ch = toupper(name1[i]);

		cout << ch;
	}










	//int howMany,temp;
	//char uppr;
	//char ch;

	//temp = 0;

	//cin >> howMany;

	//vector <string> names(howMany);


	//while (temp != howMany) {
	//	cin >> names [temp];
	//	//names[temp] = toupper(names[temp]);
	//	temp++;
	//}
	//temp = 0;
	//while (temp != howMany) {
	//	uppr = names[temp];
	//	//cout << toupper(uppr);
	//	for (int i = 0; i < strlen(uppr); i++) {

	//		// convert str[i] to uppercase
	//		ch = toupper(uppr[i]);

	//		cout << ch;
	//	}
	//	temp++;
	//}








	//for (i = 0; i < names.size(); i++) 
	//	names.at(i) = toupper(names.at(i));
	





}





//int main() {
//
//	const int MAXROWS = 3;
//	const int MAXCOLUMS = 3;
//	int values[MAXROWS][MAXCOLUMS];
//
//	int row, colum;
//	colum = 0;
//
//	for (colum = 0; colum < MAXCOLUMS; colum++)
//	{
//		cin >> values[0][colum];
//	}
//		
//	
//	colum = 0;
//	row = 0;
//
//	values[row+1][colum] = values[row][colum] * 2;
//	values[row+2][colum] = values[row][colum] * 3;
//
//	values[row+1][colum+1] = values[row][colum+1] * 2;
//	values[row+2][colum+1] = values[row][colum+1] * 3;
//
//	values[row+1][colum+2] = values[row][colum+2] * 2;
//	values[row+2][colum+2] = values[row][colum+2] * 3;
//
//	values[0][0] += values[1][1];
//	values[0][0] += values[2][2];
//
//	values[0][2] += values[1][1];
//	values[0][2] += values[2][0];
//
//	values[0][2] -= values[0][0];
//
//
//	cout << values[0][2] << endl;
//	
//}

//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int main() {
//
//	const int MAXROWS = 3;
//	const int MAXCOLUMS = 3;
//	int values[MAXROWS][MAXCOLUMS];
//
//	int row, colum;
//	colum = 0;
//	for (row = 0; row < MAXROWS; row++) //input
//		cin >> values[row][colum];
//
//	colum = 0;
//	row = 0;
//
//	values[row + 1][colum] = values[row][colum] * 2;
//	values[row + 2][colum] = values[row][colum] * 3;
//
//	values[row + 1][colum + 1] = values[row][colum + 1] * 2;
//	values[row + 2][colum + 1] = values[row][colum + 1] * 3;
//
//	values[row + 1][colum + 2] = values[row][colum + 2] * 2;
//	values[row + 2][colum + 2] = values[row][colum + 2] * 3;
//
//	values[0][0] += values[1][1];
//	values[0][0] += values[2][2];
//
//	values[0][2] += values[1][1];
//	values[0][2] += values[2][0];
//
//	values[0][2] -= values[0][0];
//
//	values[0][2] *= -2;
//
//	cout << values[0][2] << endl;
//
//}