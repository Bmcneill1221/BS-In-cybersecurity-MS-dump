// rightTriangle.cpp
// A program used to determine if a triangle is a right triangle.

#include <iostream>
using namespace std;

int main()
{
    int side1, side2, side3, hyp;

    cout << "Enter length of 1st side: ";
    cin >> side1;
    cout << "Enter length of 2nd side: ";
    cin >> side2;
    cout << "Enter length of 3rd side: ";
    cin >> side3;

    if ((side1 * side2 * side3) > 0)
    {
        hyp = side1 * side1 + side2 * side2;

        if (hyp == side3 * side3)
        {
            cout << "It is a right triangle!" << endl;
        }
        else
        {
            cout << "It is not a right triangle." << endl;
        }
    }
}