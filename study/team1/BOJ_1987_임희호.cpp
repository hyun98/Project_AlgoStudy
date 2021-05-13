// BOJ_1987
// 2020KB, 536ms
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C;
string map[20];
bool check[20][20];
bool Alphabet[26];

int answer = 0;

// 위, 왼쪽, 아래, 오른쪽
pair<int, int> movePos[4] = { {-1, 0},{0, -1},{1, 0},{0, 1} };

void DFS(pair<int, int> _pos, int count)
{
	check[_pos.first][_pos.second] = true;
	Alphabet[map[_pos.first][_pos.second] - 'A'] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextY = _pos.first + movePos[i].first;
		int nextX = _pos.second + movePos[i].second;

		// 맵에서 벗어나면 갈 수 없다.
		if (nextY < 0 || nextY >= R || nextX >= C || nextX < 0)
			continue;

		// 이미 지나온 곳은 갈 수 없다.
		if (check[nextY][nextX] == true)
			continue;

		// 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
		if(Alphabet[map[nextY][nextX] - 'A'] == true)
			continue;

		// 깊이 탐색
		DFS({ nextY , nextX }, count + 1);
	}
	answer = max(answer, count);

	Alphabet[map[_pos.first][_pos.second] - 'A'] = false;
	check[_pos.first][_pos.second] = false;
}

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다.
	cin >> R >> C;

	// 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.
	for (int i = 0; i < R; i++)
		cin >> map[i];
	
	// (0, 0)의 좌표에서 시작해 깊이우선탐색
	DFS({ 0,0 }, 1);

	// 첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.
	cout << answer << '\n';

	return 0;
}