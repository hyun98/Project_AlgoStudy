#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
	int N;
	int dp[1001];

	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]% 10007);
	}
	printf("%d", dp[N]);

	return 0;
}
