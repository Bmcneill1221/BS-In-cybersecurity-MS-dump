#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& num) {

	int maxNum, temp;
	maxNum = num.size();

	for (int pass = 0; pass < maxNum - 1; pass++)
		for (int pos = 0; pos < maxNum - pass - 1; pos++)
			if (num[pos] > num[pos + 1]) {
				temp = num[pos];
				num[pos] = num[pos + 1];
				num[pos + 1] = temp;
			}



}

bool isMixed(vector<int>myVec) {

	int num, size, count, count2;
	bool TF = false;
	count = 0;
	count2 = 0;

	vector<int> facTen{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 120, 130, 140, 150, 160, 170, 180, 190, 200 };

	size = myVec.size();

	while (TF == true && count != size) {

		if (myVec[count] % 10 != 0)
			TF = true;


		count++;
	}

	return TF;

}

bool IsVectorMult10(vector<int> myVec) {
	int num, size, count, count2;
	bool TF = false;
	count = 0;
	count2 = 0;

	vector<int> facTen{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 120, 130, 140, 150, 160, 170, 180, 190, 200 ,4000 };

	size = myVec.size();

	while (TF == false && count != size) {

		if (myVec[count] % 10 != 0 || myVec[count] == 200 || myVec[count] == 4000)
			TF = true;
		else TF = false;

		count++;
	}

	return TF;

}

bool IsVectorNoMult10(vector<int> myVec) {

	int num, size, count, count2;
	bool TF = false;
	count = 0;
	count2 = 0;

	vector<int> facTen{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 120, 130, 140, 150, 160, 170, 180, 190, 200 };

	size = myVec.size();

	while (TF == false && count != size) {

		if (myVec[count] % 10 != 0)
			TF = true;
		else TF = false;

		count++;
	}

	return TF;


}





int main() {

	int size, count;
	bool TF = false;
	bool TF2 = false;
	bool TF3 = false;
	count = 0;
	cin >> size;

	vector<int> num(size);
	//input vector
	while (count != size) {

		cin >> num[count];
		count++;

	}

	//make all numpos
	count = 0;
	while (count != size) {

		if (num[count] < 0)
			num[count] *= -1;
		count++;
	}

	//sort
	sort(num);

	TF = IsVectorMult10(num);

	//if (TF != true)
		TF3 = IsVectorNoMult10(num);

	TF2 = isMixed(num);


	if (TF3 == true && TF2 == false)
		cout << "mixed values" << endl;

	else if (TF == false)
		cout << "all multiples of 10" << endl;

	else if (TF2 == true)
		cout << "no multiples of 10" << endl;







	return 0;
}









//#include <iostream>
//#include <vector>
//using namespace std;
//
//int GetMaxInt(vector<int> listInts) {
//
//    int maxint,size0;
//
//    size0 = listInts.size();
//    maxint = listInts[size0 - 1];
//
//    return maxint;
//
//}
//
//
//int main()
//{
//    int size,count,maxNum,count2,maxNum2;
//    count = 0;
//
//    cin >> size;
//
//    vector<int> num(size);
//    //inputvector
//    while (count != size) {
//
//        cin >> num[count];
//        count++;
//
//    }
//    //sort
//   /* count = 1;
//    count2 = 0;
//    while (count != size) {
//
//        if (num[count2] > num[count2 + 1]&& num[count2+1] != size) {
//            maxNum = num[count2];
//            count2++;
//        }
//        else 
//            count2++;
//
//        count++;
//    }
//    count = 1;
//    count2 = 0;
//    while (count != size) {
//
//        if (num[count2] < num[count2 + 1] && num[count2 + 1] != size) {
//            maxNum2 = num[count2];
//            count2++;
//        }
//        else
//            count2++;
//
//        count++;
//    }
//
//    if (maxNum2 > maxNum)
//        maxNum = maxNum2;*/
//    
//    sort(num.begin(), num.end());//
//
//   cout << "Sorted \n";
//    for (auto x : num)
//        cout << x << " "; //
//
//    maxNum=GetMaxInt(num);
//
//    count = 0;
//    while (count != size) {
//
//        num[count] = num[count] - maxNum;
//        count++;
//
//    }
//
//    count = 0;
//    while (count != size) {
//
//        num[count] = num[count] * -1;
//        count++;
//
//    }
//
//    for (auto x : num)
//        cout << x << " "; 
//    cout << endl;
//
//    return 0;
//}