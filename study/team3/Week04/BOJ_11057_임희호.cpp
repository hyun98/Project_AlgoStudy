// BOJ_11057
// 2056KB, 0ms
/*
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오.

수는 0으로 시작할 수 있다.
*/
#include <iostream>

using namespace std;

int N;
int memory[1001][10] = { 0 };

int DP(int n)
{
	// 가장 마지막 자리
	for (int i = 0; i <= 9; i++)
		memory[n][i] = 1;

	// 2번째 자리에서 1번째 자리수의 수를 구할 수 있으므로 N에서 2까지 반복
	for (int i = n; i >= 1; i--)
	{
		// 0~9 의 경우에 대해 모두 처리
		for (int j = 0; j <= 9; j++)
		{
			// 오름막 수의 조건
			for (int k = 9; k >= j; k--)
			{
				// 오버플로우가 일어나지 않으려면 부분적으로 나머지 연산을 해줘야한다.
				memory[i-1][j] += memory[i][k] % 10007;
			}
		}
	}

	// memory[1][0] ~ memory[1][9] 까지의 값을 모두 더한 값
	return memory[0][0];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.
	cin >> N;

	// 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.
	cout << DP(N) % 10007;

	return 0;
}