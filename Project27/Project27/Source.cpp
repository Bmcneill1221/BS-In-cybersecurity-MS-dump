#include <iostream>
using namespace std;
int main() {
	int x1, y1, x2, y2;
	int dotProduct = 0;
	cout << "First pair: ";
	cin >> x1 >> y1;
	cout << "Second pair: ";
	cin >> x2 >> y2;
	// replace this with inline MASM
	__asm{
	mov	eax, x1	; dotProduct = x1 * x2 + y1 * y2;
	imul eax, x2
		mov ebx, y1
		imul ebx, y2
		add eax, ebx
		mov dotProduct, eax
	}
	cout << dotProduct << endl;
}