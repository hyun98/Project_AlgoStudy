#include <stdio.h>

int main(void) {
	int N;
	int res = 0;
	int dp[1001][10] = { 0, };
	

	scanf("%d", &N);

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			int sum = 0;
			for (int k = j; k < 10; k++)
				sum += dp[i-1][k] % 10007;	
			dp[i][j] = sum % 10007;
		}
	}

	for (int k = 0; k <= 9; k++)
		res += dp[N][k] % 10007;

	printf("%d", res % 10007);

}
