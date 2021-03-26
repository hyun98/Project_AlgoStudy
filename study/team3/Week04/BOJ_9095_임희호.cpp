// BOJ_9095
// 2016KB, 0ms
/*
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int memory[11] = { 0, };

int DP(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	if (n == 4)
		return 7;

	if (memory[n] == !0)
		return memory[n];

	return memory[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
	cin >> T;
	// 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.n은 양수이며 11보다 작다.
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << DP(N) << '\n';
	}
	
	return 0;
}