#include <iostream>
using namespace std;

//write your recursive function here

int productOfDigits(int number) {

	int num1, num2, answ;
	answ = 1;
	num1 = number;

	if (number < 10)
		return number;

	if (number > 999) {
		answ *= num1 / 1000;
		num1 %= 1000;
	}

	if (number > 99) {
		answ *= num1 / 100;
		num1 %= 100;
	}

	if (number > 9) {
		answ *= num1 / 10;
		num1 %= 10;
	}

	return answ;



}

int main()
{
	int number;

	//get input
	cin >> number;
	//output digit product
	cout << productOfDigits(number) << endl;
	return 0;
}










































//#include <iostream>
//using namespace std;
//
//int evenIntSum(int number)
//{
//	int num2, num3, num4;
//
//	if (number == 0)
//		return 0;
//
//	//if I just duble it will that work?
//
//	num3 = number;
//	num4 = number;
//	while (num4 != 0) {
//
//		num4 -=  2;
//		num3 += num4;
//
//	}
//	
//	return num3;
//
//}
//
//int main()
//{
//	int number;
//
//	cin >> number;
//	//assume number entered is positive, even or 0
//	cout << evenIntSum(number) << endl;
//}













































//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//struct Car {
//    string type;
//    int year;
//};
//
//int main() {
//    vector<Car> carList(3);
//    int i;
//    Car chosenCar;
//
//    for (i = 0; i < carList.size(); ++i) {
//        cin >> carList.at(i).type;
//        cin >> carList.at(i).year;
//    }
//
//    chosenCar = carList.at(0);
//    for (i = 0; i < carList.size(); ++i) {
//        if (carList.at(i).year < chosenCar.year) {
//            chosenCar = carList.at(i);
//        }
//    }
//
//    cout << "Result: " << chosenCar.year << endl;
//
//    return 0;
// 
// 
//}


//#include <iostream>
//#include <fstream>
//#include<string>
//#include<iomanip>
//#include <vector>
//using namespace std;
////place any c++ headers you need here
//
//int main()
//{
//	//Write your program here
//	ifstream fin("numbers.txt");
//	ofstream fout("largeAndSmall");
//	int smallestOnFile, largestOnFile, pass, pos, temp, num;
//	//vector<int> num;
//
//	fin >> num;
//	fin >> largestOnFile;
//	smallestOnFile = largestOnFile;
//	while (!fin.eof())
//	{
//		while (num > largestOnFile) {
//			largestOnFile = num;
//		}
//		while (num < smallestOnFile) {
//			smallestOnFile = num;
//		}
//		fin >> num;
//	}
//
//
//	/*for (pass = 0; pass< largestOnFile - 1;pos++)
//		for (pos=0;pos< largestOnFile -pass-1;pos++)
//			if (num[pos] > num[pos + 1]) {
//				temp = num[pos];
//				num[pos] = num[pos + 1];
//				num[pos + 1] = temp;
//			}
//
//	for (pass = 0; pass < smallestOnFile - 1; pos++)
//		for (pos = 0; pos < smallestOnFile - pass - 1; pos++)
//			if (num[pos] < num[pos + 1]) {
//				temp = num[pos];
//				num[pos] = num[pos + 1];
//				num[pos + 1] = temp;
//			}*/
//
//	 //all Coach Rags here to make your program auto-gradable, notice largeAndSmall.txt now becomes an input file.
//	fin.open("largeAndSmall.txt");
//
//	//extract the two integer values written to file, the first is the smallest, second is the largest
//	//int smallestOnFile, largestOnFile;
//	fin >> smallestOnFile >> largestOnFile;
//
//	//close input file
//	fin.close();
//
//	//output to cout for auto-grading purposes
//	cout << smallestOnFile << " " << largestOnFile << endl;
//
//	return 0;
//}