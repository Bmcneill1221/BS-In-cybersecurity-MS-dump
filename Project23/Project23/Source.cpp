// Blaze McNeill
#include <iostream>
#include <array>
using namespace std;

int main() {
    char s[10];
    char t[10];
    int i = 0;

    cin >> s >> t;

    while (s[i] != '\0') {
        i++;
    }

    int k = 0;
    while (t[k] != '\0') {
        s[i] = t[k];
        i++;
        k++;
    }
    s[i] = '\0';

    cout <<endl << s << endl <<endl << t;
}