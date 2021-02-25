#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool visit[10] = { false };
int W[10][10];
int answer = INT32_MAX;

void DFS(int start, int from, int count, int sum)
{
	if (count == N-1)
	{
		if (W[from][start] != 0)
		{
			sum += W[from][start];
			answer = min(answer, sum);
		}
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		// 길이 없으면 다음으로
		if (W[from][i] == 0)
			continue;

		// 방문하지 않은 노드에서 다시 DFS
		if (visit[i] == false)
		{
			visit[i] = true;
			DFS(start, i, count + 1, sum + W[from][i]);
			visit[i] = false;
		}
	}

}

void salesman_solution(int start)
{
	// 현재 노드를 체크하고
	visit[start] = true;
	// 깊이 탐색
	DFS(start, start, 0, 0);
	visit[start] = false;
}

void input()
{
	// 첫째 줄에 도시의 수 N이 주어진다. (2 ≤ N ≤ 10) 다음 N개의 줄에는 비용 행렬이 주어진다.
	// 각 행렬의 성분은 1, 000, 000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다.W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	// 각 정점에서의 경우를 파악
	for (int i = 0; i < N; i++)
	{
		salesman_solution(i);
	}

	cout << answer << '\n';

	return 0;
}