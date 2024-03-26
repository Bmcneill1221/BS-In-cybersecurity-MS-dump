//Blaze McNeill
//  
//Homework - supply the missing functions
//
//Ave fixed. // 
#include <iostream>
#include <vector>
using namespace std;

float ave(vector<int> scores)
{
	float avg, count, total, sum;

	count = 0;
	sum = 0;

	while (count < scores.size())
	{
		sum += scores[count];
		count++;
	}
	
	avg = sum / count;

	return avg;
}

int max(vector<int> scores)
{
	int max, count;

	max = 0;
	count = 0;

	while (count < scores.size())
	{
		if (max < scores[count])
			max = scores[count];
		count++;
	}

	return max;
}

int min(vector<int> scores) // reverse of max
{
	int min, count;

	min = 9999999999;
	count = 0;

	while (count < scores.size())
	{
		if (min > scores[count])
			min = scores[count];
		count++;
	}

	return min;

}
void input_scores(vector<int>& scores)
{
	unsigned pos;
	for (pos = 0; pos < scores.size(); pos++)
	{
		cout << "Score? ";
		cin >> scores[pos];
	}
	cout << endl;
}
// Missing functions go here
int main()
{
	int howmany;
	cout << "How many students? ";
	cin >> howmany;
	cout << endl;
	vector<int> scores(howmany);
	input_scores(scores);
	//cout << " "  << scores[0];//test
	cout << "Ave is " << ave(scores) << endl;
	cout << "Max is " << max(scores) << endl;
	cout << "Min is " << min(scores) << endl;
}