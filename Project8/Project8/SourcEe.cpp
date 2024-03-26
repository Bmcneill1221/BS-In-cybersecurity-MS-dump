
#include <iostream>
#include <list>
#include <stack>
//make available to this program the c++ stack and list classes
using namespace std;

int main()
{
	//create a stack of integers
	list<int> nums;

	int count = 1, value = 10, input;
	while (count <= 4)
	{
		cin >> input;
		nums.push_back(input);
		//place value onto the top of the stack
		value += 10;
		count++;
	}

	//remove one value from the stack and then output the size of the stack
	nums.pop_front();
	cout << nums.size() << endl;

	//output each stack value and remove it from the stack (make this a loop)
	while (nums.empty() != true) {
		cout << nums.front() << endl;
		nums.pop_front();
	}

	//outut the size of the stack after the loop
	cout << nums.size() << endl;

	return 0;
}