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
		// i-1 ���� ��� ��쿡�� +1�� ���ϴ� ���, i-2 ���� ��� ��쿡��
		// +2�� ���ϴ� ���, i-3 �� ��� ��쿡�� +3�� ���ִ� ���
		printf("%d\n", dp[N]);
	}

	return 0;
}