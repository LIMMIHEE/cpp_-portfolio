#include <stdio.h>
#define R 3

//전역변수 선언
int b[R];

//함수 선언
void RePermutation(int  a[], int r, int n);
void Reper();

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation(a, 0, n);

	return 0;
}

void Reper() {
	int i;
	for (i = 0; i < R; i++)
		printf("%5d", b[i]);
	printf("\n");
}

void RePermutation(int  a[], int r, int n) {
	int i;
	if (r == R)
		Reper();
	else
		for (i = 0; i < n; i++) {
			b[r] = a[i];
			Repermutation(a, r + 1, n);
		}
}