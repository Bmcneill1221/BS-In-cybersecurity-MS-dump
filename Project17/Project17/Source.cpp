#include <set>
#include <iostream>
#include <algorithm>
using namespace std;



void displaySet(const set<int>& s) {

	set<int>::iterator it;

	for (it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;

}

void setUnion( set<int>& s1, set<int>& s2) {

	set<int> s3;
	set_union(s1.begin(), s1.end(),
		s2.begin(), s2.end(),
		inserter(s3, s3.begin()));
	displaySet(s3);


}

void setIntesec(set<int>& s1, set<int>& s2) {

	set<int> s3;
	set_intersection(s1.begin(), s1.end(),
		s2.begin(), s2.end(),
		inserter(s3, s3.begin()));
	displaySet(s3);

}

void setdiff(set<int>& s1, set<int>& s2) {

	set<int> s3;
	set_difference(s1.begin(), s1.end(),
		s2.begin(), s2.end(),
		inserter(s3, s3.begin()));
	displaySet(s3);

}

int main() {

	set<int> set1;
	set<int> set2;

	int num;
	int howMany;
	cin >> howMany;

	while (howMany != 0) {

		cin >> num;
		set1.insert(num);
		howMany--;

	}

	cin >> howMany;

	while (howMany != 0) {

		cin >> num;
		set2.insert(num);
		howMany--;

	}

	cout << "Set 1: ";
	displaySet(set1);
	cout << "Set 2: ";
	displaySet(set2);

	cout << "Union: ";
	setUnion(set1, set2);

	cout << "Intersection: ";
	setIntesec(set1, set2);

	cout << "Difference12: ";
	setdiff(set1, set2);

	cout << "Difference21: ";
	setdiff(set2, set1);




}