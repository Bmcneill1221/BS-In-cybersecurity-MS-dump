	.386
	.model flat, c

.data

k dd ?
sum dd ?
factor2 dd ?

.code

; int properFactors(int n, int factors[], int& numFactors) {
	properFactors proc uses  ebx ecx edx edi esi, n:sdword, factors : ptr, numFactors : ptr

	; int i, k, sum, factor2;

mov ecx, 0; i = 1;
inc ecx
mov k, 2; k = 2;
mov sum, 1; sum = 1;
mov ebx, factors; factors[0] = 1;
mov edi, 0
mov[ebx + 4 * ecx], edi


while_1:; while (k * k <= n) {
mov edx, k
imul edx, k
cmp edx, n
jle while_1_start
jmp while_1_end

while_1_start :

mov edx, 0 ;// an attempt to solve an error with output.
if_1:; if (n % k == 0) {
mov eax, n
cdq
idiv k
; mov k, eax

cmp edx, 0

je if_1_start
jne if_1_end

if_1_start :

mov edx, k; sum = sum + k;
add edx, sum
mov sum, edx

mov edi, k; factors[i] = k;
mov[ebx + 4 * ecx], edi



inc ecx; i++;

mov edx, 0 ;// an attempt to solve an error with output.
mov eax, n; factor2 = n / k;
cdq
idiv k
mov factor2, eax



if_2:; if (factor2 != k) {
mov edx, factor2
cmp edx, k
jne if_2_start
jmp if_2_end

if_2_start :

mov edx, sum; sum = sum + factor2;
add edx, factor2
mov sum, edx

mov edi, factor2; factors[i] = factor2;
mov[ebx + 4 * ecx], edi

inc ecx; i++;

if_2_end:;}

if_1_end:;

;}

inc k; k++;

jmp while_1
while_1_end : ;}


; numFactors = i;
mov numFactors, ecx

mov eax, sum; return sum;
ret

;}
properFactors endp

end
