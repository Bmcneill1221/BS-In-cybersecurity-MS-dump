//Blaze McNEill
//
//
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

float calculateSD(vector<float> data) {
	float sum, mean, standardDeviation;
	int i;

	sum = 0.0;
	standardDeviation = 0.0;

	for (i = 0; i < 10; ++i) {
		sum += data[i];
	}

	mean = sum / 10;

	for (i = 0; i < 10; ++i) {
		standardDeviation += pow(data[i] - mean, 2);
	}

	return sqrt(standardDeviation / 10);
}

void sort(vector<float>& grades)
{
	int pass, pos, manynum;
	float temp;

	manynum = grades.size();

	for (pass = 0; pass < manynum - 1; pass++)
		for (pos = 0; pos < manynum - pass - 1; pos++)
			if (grades[pos] < grades[pos + 1]) {
				temp = grades[pos];
				grades[pos] = grades[pos + 1];
				grades[pos + 1] = temp;
			}

}

void main()
{
	int size, cnt;
	vector <float> grades;
	
	double grade;
	float temp, temp2;

	cout << "Score? ";
	cin >> grade;
	grades.push_back(grade);

	while (grade != -1)
	{
		cout << "Score? ";
		cin >> grade;
		grades.push_back(grade);

	}

	grades.pop_back();
	size = grades.size();
	vector<int> freq(size);
	cout << "\nThere were " << grades.size() << " scores entered" << endl;

	sort(grades);

	cout << "The maxumumj score was " << grades[0];//max

	cout << "\nThe minum socre was " << grades[size -1];//min

//mean score    DOES NOT WORK
	cnt = 0;
	temp = 0;
	while (size-1 != cnt)
	{
		temp += grades[cnt];
		cnt++;
	}
	temp /= size - 1;
	cout << "\nThe mean score was " << temp;

	//median     ELSE DOES NOT WORK
	temp = 0;

	if (size-1 % 2 != 0)
	{
		temp = grades[(size + 1) / 2];
		temp2 = grades[(size - 1) / 2];
		temp = (temp + temp2) / 2;

		cout << "\nThe median score was " << temp;
	}
		
	else
		cout << "\nThe median score was " << grades[size / 2];

	//mode
	/*
	int i, j, z, tmp, maxCount, modeValue;
	vector<int> tally(size-1);	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size -1 - i; j++)
		{
			if (grades[j] > grades[j + 1])
			{
				tmp = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		for (z = i + 1; z < size; z++)
		{
			if (grades[i] == grades[z])
			{
				tally[i]++;
			}
		}
	}
	maxCount = 0;
	modeValue = 0;
	for (i = 0; i < size-1; i++)
	{
		if (tally[i] > maxCount)
		{
			maxCount = tally[i];
			modeValue = grades[i];
		}
	}

	cout << "\n The mode score was " <<modeValue ;
	*/

	cnt = 0;
	
	while (cnt != size)
	{
		temp = 0;

		if (grades[cnt] == grades[cnt++]) {
			
			if (freq[temp] >= 1)
				freq[temp]+= 1;

			

		}
		else
			freq.push_back(temp);

		cnt++;
		temp++;
		
		cout << temp;
	}
	
	//standard deviation
	
	cout << "\nThe standard deviation was " << calculateSD(grades);
	
	//#of letter grades
	//scores in order
	//score chart
}