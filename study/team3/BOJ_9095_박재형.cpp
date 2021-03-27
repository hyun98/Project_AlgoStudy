#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int j = 0; j < T; j++)
	{
		int N;
		cin >> N;

		int dp[11];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		// i-1 항의 모든 경우에서 +1을 더하는 경우, i-2 항의 모든 경우에서
		// +2를 더하는 경우, i-3 의 모든 경우에서 +3을 해주는 경우
		printf("%d\n", dp[N]);
	}

	return 0;
}