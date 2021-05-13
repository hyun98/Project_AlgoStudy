// BOJ_
// KB, ms
/*
퇴사 2
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int *T;
int *P;
int *memory;
int answer = 0;

int DP(int start)
{
	if (memory[start] != 0)
		return memory[start];

	int next = start + T[start];

	// 수행 불가
	if (next > N)
		return 0;

	// 수행하고 리턴(값 판단은 호출 함수에서)
	if (next == N)
		return P[start];

	memory[start] = P[start];
	for (int i = next; i < N; i++)
	{
		// 현재 이익과 다음 일정의 이익을 더해서 저장하고
		memory[start] = max(memory[start], DP(i) + P[start]) ;
	}

	return memory[start];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 N (1 ≤ N ≤ 1,500,000)이 주어진다.
	cin >> N;
	T = new int[N];
	P = new int[N];
	memory = new int[N] {0,};

	// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 50, 1 ≤ Pi ≤ 1,000)
	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}

	// 각 시작 지점에 대해서 수행한다.
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, DP(i));
	}

	// 첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
	cout << answer << endl;

	return 0;
}