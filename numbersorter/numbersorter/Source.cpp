#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int NUM_VALS = 4;
    vector<int> courseGrades(NUM_VALS);
    int i;

    for (i = 0; i < courseGrades.size(); ++i) {
        cin >> courseGrades.at(i);
    }

    i = 0;
    while (i != courseGrades.size())
    {
        cout << courseGrades.at(i) << " ";
        i++;
    }

    cout << endl;

    i = 3;

    while (i != -1)
    {
        cout << courseGrades.at(i) << " ";
        i--;
    }

    cout << endl;

    return 0;
}