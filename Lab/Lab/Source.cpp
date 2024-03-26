//Blaze McNeill
//
// LAB
//
#include <iostream>
using namespace std;

int lcm(int& den1, int& den2)
{
    int cnt, ans;

    if (den1 > den2)
    {
        cnt = den1;
    }
    else
    {
        cnt = den2;
    }
    ans = 0;
    while (ans == 0)
    {
        if ((cnt % den2 == 0) && (cnt % den1 == 0))
            ans = cnt;
        else
            cnt++;

    }

    return ans;
}

int gcd(int num1, int den1)
{

    int temp1;

    temp1 = num1 % den1;

    while (temp1 != 0)
    {
        num1 = den1;
        den1 = temp1;
        temp1 = num1 % den1;
    }
    return den1;
}

void reduce(int& num1, int& den1)
{

    int newden = gcd(num1, den1);
    num1 /= newden;
    den1 /= newden;

}

void common_den(int& num1, int& den1, int& num2, int& den2) // not sure if works.../ WOOHOOO IT DOES THE THING!
{
    int mult1, mult2;

    int newden = lcm(den1, den2);
    mult1 = newden / den1;
    mult2 = newden / den2;

    num1 *= mult1;
    den1 *= mult1;
    num2 *= mult2;
    den2 *= mult2;

}

int main()
{
    int num1, den1, num2, den2, newnum, newden;
    char slash1, slash2, op;

    cout << "\nFraction Calculator\n\n";
    cout << "Add, subtract, multiply & divide - positive fractions only\n";
    cout << "Enter '0/0 + 0/0' to quit.\n";

    // Input will be assumed to be in correct form for simplification
    // Input data before loop in case they want to exit right away

    cout << "\n> ";
    cin >> num1 >> slash1 >> den1 >> op >> num2 >> slash2 >> den2;
    while (num1 + den1 + num2 + den2 > 0)
    {
        // Reduce both fractions to keep integers as small as possible
        reduce(num1, den1);
        reduce(num2, den2);
        switch (op) {
        case '+':
            // Find common denominator and add
            common_den(num1, den1, num2, den2);
            newnum = num1 + num2;
            newden = den1;
            break;
        case '-':
            // Find common denominator and subtract
            common_den(num1, den1, num2, den2);
            newnum = num1 - num2;
            newden = den1;
            break;
        case '*':
            // Multiply numerators and multiply denominators
            newnum = num1 * num2;
            newden = den1 * den2;
            break;
        case '/':
            // Invert and multiply
            newnum = num1 * den2;
            newden = den1 * num2;
        }
        // Reduce the answer to lowest terms
        reduce(newnum, newden);

        // Output the results
        cout << num1 << "/" << den1 << " " << op << " ";
        cout << num2 << "/" << den2 << " = ";
        cout << newnum << "/" << newden << endl;

        // Input data for next iteration of loop
        cout << "\n> ";
        cin >> num1 >> slash1 >> den1 >> op >> num2 >> slash2 >> den2;
    }
}
