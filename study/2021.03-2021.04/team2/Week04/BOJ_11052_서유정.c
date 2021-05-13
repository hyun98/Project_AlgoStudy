#include <stdio.h>

int main(void) {
	int N;
	int P[1001];
	int sum[1001];
	int max = 0;
	

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);	
	}
	sum[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++){
			if (max < P[j] + sum[i - j]) {
				max = P[j] + sum[i - j];
			}
		}
		sum[i] = max;
		printf("%d\t", sum[i]);
	}
	
	printf("%d", sum[N]);

}
