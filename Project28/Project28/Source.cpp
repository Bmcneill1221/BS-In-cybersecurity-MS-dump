#include <iostream>
#include <ctime>
using namespace std;
#define MAXIMUM 1000000
int Factors[MAXIMUM];
extern "C" int properFactors(int, int[], int&);

int main() {

	int q;
	int numFactors;
	int pairCount = 0;
	clock_t startClock = clock();

	for (int p = 1; p <= MAXIMUM; p++) {

		q = properFactors(p, Factors, numFactors);

		if (q > p) {

			if (properFactors(q, Factors, numFactors) == p) {

				cout << "Amicable Pair: " << p << "," << q;
				cout << " (" << q << " has " << numFactors << " factors: ";
				cout << Factors[0];
				for (int i = 1; i < numFactors; i++) { cout << "," << Factors[i]; }
				cout << ")" << endl;
				pairCount++;

			}

		}

	}
	double totalTime = (double)(clock() - startClock) / CLOCKS_PER_SEC;
	cout << "Number of amicable pairs found = " << pairCount << endl;
	cout << "Time = " << totalTime << " seconds" << endl;

}


//int properFactors(int n, int factors[], int& numFactors) {
//
//	int i, k, sum, factor2;
//
//	i = 1;
//	k = 2;
//	sum = 1;
//	factors[0] = 1;
//
//	while (k * k <= n) {
//
//		if (n % k == 0) {
//
//			sum = sum + k;
//			factors[i] = k;
//			i++;
//
//			factor2 = n / k;
//			if (factor2 != k) {
//
//				sum = sum + factor2;
//				factors[i] = factor2;
//				i++;
//
//			}
//
//		}
//		k++;
//
//	}
//	numFactors = i;
//	return sum;
//
//}
//
//.386
//.model flat, c
//
//.data
//n           dd      ?
//factors     sdword 100 dup(?)
//numFactors  dd      ?
//i           dd      ?
//k           dd      ?
//sum         dd      ?
//factor2     dd      ?
//
//.code
//
//properFactors proc uses ebx ecx edx edi esi
//    mov i, 1            ; i = 1
//    mov k, 2            ; k = 2
//    mov sum, 1          ; sum = 1
//    mov factors[0], 1   ; factors[0] = 1
//
//while1:
//    mov eax, k
//    imul eax, k
//    cmp eax, n
//    jg while1_end       ; while (k * k <= n)
//
//    mov ebx, n
//    mov edx, 0
//    div k
//    cmp edx, 0
//    jne while1_inc      ; if (n % k != 0)
//
//    mov ebx, k          ; sum = sum + k
//    add sum, ebx
//
//    mov ebx, i
//    mov ecx, factors
//    lea edx, [ecx + ebx*4]
//    mov dword ptr [edx], k   ; factors[i] = k
//
//    inc i               ; i++
//
//    mov ebx, n          ; factor2 = n / k
//    mov edx, 0
//    div k
//    mov factor2, eax
//
//    mov eax, factor2
//    cmp eax, k
//    je while1_inc
//
//    mov ebx, sum        ; sum = sum + factor2
//    add ebx, factor2
//    mov sum, ebx
//
//    mov ebx, i
//    mov ecx, factors
//    lea edx, [ecx + ebx*4]
//    mov dword ptr [edx], factor2 ; factors[i] = factor2
//
//    inc i               ; i++
//
//while1_inc:
//    inc k               ; k++
//    jmp while1
//
//while1_end:
//    mov eax, i          ; numFactors = i
//    mov numFactors, eax
//    mov eax, sum        ; return sum
//    ret
//properFactors endp
//
//end
