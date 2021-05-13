#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int N, M = 0, n, m, len = 0, sum = 0,num = 0;
	
	scanf("%d", &N);
	n = N;
	
	while (n > 0) {
		n /= 10;
		len++;
	}//자릿수 구하기
	
	m = N - len * 9;//최소 범위 구하기

	for (int i = m; i <= N; i++) {
		num = i;
		sum += num; //분해합 더하기
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}//자릿수 더하기

		if (sum == N) {
			M = i;
			break;
		}
		sum = 0;
	}
	printf("%d", M);
	return 0;
}
