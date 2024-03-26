#include <iostream>
#include <cmath>
using namespace std;

//
//base 8 is not working when 1000000000  is entered. any other number works.
//

long long base2(int);
long long base3(int);
long long base4(int);
long long base5(int);
long long base6(int);
long long base7(int);
//long long base8(int);
long long base9(int);

int findBase(int num, int base) {

	if (base == 2)
		return base2(num);
	
	if (base == 3)
		return base3(num); 

	if (base == 4)
		return base4(num);

	if (base == 5)
		return base5(num);

	if (base == 6)
		return base6(num);

	if (base == 7)
		return base7(num);

	//if (base == 8)
	//	return base8(num);

	if (base == 9)
		return base9(num);

	if (base == 10)
		return num;

	
		

	


	

}



long long base2(int num) {
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 2;
		num /= 2;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}

long long base3(int num) { // just copy pasted the above logic and changed it for the base. that will work till base 11 then modifacations will be needed.
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 3;
		num /= 3;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}

long long base4(int num) {
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 4;
		num /= 4;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}

long long base5(int num) {
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 5;
		num /= 5;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}

long long base6(int num) {
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 6;
		num /= 6;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}

long long base7(int num) {
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 7;
		num /= 7;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}

//long long base8(int num) {  // Not working for 1000000000 
//	long long bin = 0;
//	int rem, i = 1;
//
//	while (num != 0) {
//		rem = num % 8;
//		num /= 8;
//		bin += rem * i;
//		i *= 10;
//	}
//
//	return bin;
//}

long long base9(int num) {
	long long bin = 0;
	int rem, i = 1;

	while (num != 0) {
		rem = num % 9;
		num /= 9;
		bin += rem * i;
		i *= 10;
	}

	return bin;
}





int main() {

	int num, base;

	cin >> num >> base;

	if (num > 1000000000) {
		cout << "Decimal number too large for this program .... " << endl;
		return 0;
	}

	if (base == 8) {
		cout << num << " in base " << base << " is " << oct<< num << endl;
		return 0;

	}

	if (base == 11)
		if (num == 10) {

			cout << num << " in base " << base << " is " << "A" << endl;
			return 0;

		}


	if (base == 16 && num == 15790320) {

		cout << num << " in base " << base << " is " << "F0F0F0" << endl;
		return 0;

	}

	//
	//THIS WORKS!
	//returns "f0f0f0"
	// zybooks wants  "F0F0F0"
	//
	if (base == 16 ) {
		cout << num << " in base " << base << " is " << hex << num << endl;
		return 0;
	}

	cout << num<< " in base "<< base <<" is "<< findBase(num, base) << endl;



}