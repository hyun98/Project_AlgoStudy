// BOJ_11053
// 2024KB, 0ms
/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1001];
// memory[n] : 수열의 크기 n까지 중 가장 긴 증가하는 부분 수열의 길이 
int memory[1001] = { 0 };
int answer = 0;

int DP(int start)
{
	// 이미 계산된 값이면 사용
	if (memory[start] != 0)
		return memory[start];

	// 시작지점을 하나씩 증가시켜 가면서 증가하는 수 찾기
	memory[start] = 1;
	for (int i = start + 1; i <= N; i++)
	{
		// 증가하는 수 찾았으면 거기서 다시 DP
		if (A[start] < A[i])
		{
			memory[start] = max(memory[start], DP(i) + 1);
		}
	}

	return memory[start];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
	cin >> N;

	// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1, 000)
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	// 모든 시작지점의 경우 테스트
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, DP(i));
	}

	// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
	cout << answer;

	return 0;
}