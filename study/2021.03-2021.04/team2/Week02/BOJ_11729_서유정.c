#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int N, K;

	scanf("%d", &N);
	K = pow(2, N) - 1;

	printf("%d\n", K);
	hanoi(N, 1, 2, 3);

}

int hanoi(int n, int from, int by, int to) {
	if(n == 1)
		printf("%d %d\n", from, to);
	else {
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}
