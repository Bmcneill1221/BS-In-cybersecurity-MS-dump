#include <iostream>
#include <climits>

using namespace std;

// Inline MASM code for adjustedSum function
extern "C" int adjustedSum(int scores[], int numberOfScores);

int main() {
    int scores[100];
    int numberOfScores = 0;
    int input;

    // Get input from user and store in scores array
    do {
        cout << "Enter a positive integer (enter a negative integer to stop): ";
        cin >> input;
        if (input >= 0) {
            scores[numberOfScores] = input;
            numberOfScores++;
        }
    } while (input >= 0 && numberOfScores < 100);

    // Call adjustedSum function
    int sum = adjustedSum(scores, numberOfScores);

    // Output the result
    cout << "The adjusted sum is: " << sum << endl;

    return 0;
}

// Adjusted sum function with inline MASM code
int adjustedSum(int scores[], int numberOfScores) {
    int sum = 0;
    int max = -1;
    int min = INT_MAX;
    int i = 0;

    // Iterate through the array and calculate sum, max and min values
    __asm {
        mov esi, scores
        mov ecx, numberOfScores
        cmp ecx, 2
        jle exit_asm

        loop_start :
        mov eax, [esi]
            add sum, eax

            cmp eax, max
            jle not_max
            mov max, eax

            not_max :
        cmp eax, min
            jge not_min
            mov min, eax

            not_min :
        add esi, 4
            loop loop_start

            exit_asm :
    }

    // Remove max and min values from the sum
    if (numberOfScores > 2) {
        sum -= max;
        sum -= min;
    }

    return (numberOfScores > 2) ? sum : 0;
}
