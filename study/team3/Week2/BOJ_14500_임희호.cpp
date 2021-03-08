#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> check;
int deltaY[4] = { -1, 0, 1, 0 };
int deltaX[4] = { 0, -1, 0, 1 };
int answer = 0;

typedef struct pos
{
	int y;
	int x;
}Pos;

void dfs(Pos pos, int count, int sum)
{
	check[pos.y][pos.x] = true;

	if (count == 4)
	{
		answer = max(answer, sum);
		check[pos.y][pos.x] = false;
		return;
	}

	// 순서대로 위, 왼쪽, 아래, 오른쪽
	for (int i = 0; i < 4; i++)
	{
		int nextY = pos.y + deltaY[i];
		int nextX = pos.x + deltaX[i];

		// 맵을 벗어났으면 다른 방향으로
		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
			continue;
		// 이미 탐색했으면 다른 방향으로
		if (check[nextY][nextX] == true)
			continue;

		dfs({ nextY, nextX }, count + 1, sum + map[nextY][nextX]);
	}
	check[pos.y][pos.x] = false;
}

void Figure_exception(Pos pos)
{
	if (pos.y >= 1 && pos.y < N - 1)
	{
		// ㅏ
		if (pos.x >= 0 && pos.x < M - 1)
		{
			answer = max(answer, map[pos.y][pos.x] + map[pos.y - 1][pos.x] + map[pos.y][pos.x + 1] + map[pos.y + 1][pos.x]);
		}
		// ㅓ
		if (pos.x >= 1 && pos.x < M)
		{
			answer = max(answer, map[pos.y][pos.x] + map[pos.y - 1][pos.x] + map[pos.y + 1][pos.x] + map[pos.y][pos.x - 1]);
		}

	}

	if (pos.x >= 1 && pos.x < M - 1)
	{
		// ㅗ
		if (pos.y >= 1 && pos.y < N)
		{
			answer = max(answer, map[pos.y][pos.x] + map[pos.y - 1][pos.x] + map[pos.y][pos.x - 1] + map[pos.y][pos.x + 1]);
		}
		// ㅜ
		if (pos.y >= 0 && pos.y < N - 1)
		{
			answer = max(answer, map[pos.y][pos.x] + map[pos.y][pos.x - 1] + map[pos.y + 1][pos.x] + map[pos.y][pos.x + 1]);
		}
	}
}

void solution(Pos pos)
{
	// (현재위치, count, 칸의 정수 값)
	dfs(pos, 1, map[pos.y][pos.x]);
	// dfs로 안되는 경우(ㅜ)
	Figure_exception(pos);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
	cin >> N >> M;
	// 1. vector<bool> v(M, false)로 초기화한 벡터를 N번 만큼의 반복을 통해 push한다.
	for (int i = 0; i < N; i++)
	{
		vector<bool> v(M, false);
		check.push_back(v);
	}

	// 둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다.
	// 2. vector<int>(M, 0)을 N 번 반복해서 push 한다.
	map.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	// 맵의 각 칸에 대해서 가능한 도형을 전부 검사한다음 가장 큰 값을 찾는다.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			solution({ i,j });

	cout << answer << '\n';

	return 0;
}