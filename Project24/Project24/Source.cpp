#include <iostream>
using namespace std;

int sqrLenCrossProduct(int x1, int y1, int z1, int x2, int y2, int z2);

int main()
{
    int x1, y1, z1, x2, y2, z2;
    cout << "Enter x, y, and z values for vector 1: ";
    cin >> x1 >> y1 >> z1;
    cout << "Enter x, y, and z values for vector 2: ";
    cin >> x2 >> y2 >> z2;

    int result = sqrLenCrossProduct(x1, y1, z1, x2, y2, z2);
    cout << "The squared length of the cross product is " << result << endl;

    return 0;
}


int sqrLenCrossProduct(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int answer;

    // Initialize x3, y3, z3 to zero
    int x3 = 0;
    int y3 = 0;
    int z3 = 0;

    __asm {
        // x3 = y1 * z2 - y2 * z1
        mov eax, y1
        imul z2
        mov ebx, y2
        imul z1
        sub eax, ebx
        mov x3, eax

        // y3 = x2 * z1 - x1 * z2
        mov eax, x2
        imul z1
        mov ebx, x1
        imul z2
        sub eax, ebx
        mov y3, eax

        // z3 = x1 * y2 - x2 * y1
        mov eax, x1
        imul y2
        mov ebx, x2
        imul y1
        sub eax, ebx
        mov z3, eax

        // answer = x3 * x3 + y3 * y3 + z3 * z3
        mov eax, x3
        imul x3
        mov ebx, y3
        imul y3
        add eax, ebx
        mov ebx, z3
        imul z3
        add eax, ebx
        mov answer, eax
    }

    return answer;
}