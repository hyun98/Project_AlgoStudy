// BOJ_9466
// 6536KB, 532ms
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T;
int N;
int number[100001];
int visit[100001];
vector<int> v;
bool check[100001] = { 0, };
int cnt = 0;

void DFS(int now)
{
	int next = number[now];

	if (now == next)
	{
		check[now] = true;
		return;
	}

	// 이미 방문한적 있다면
	if (visit[now])
	{
		// 경로를 확인해서
		for (int i = 0; i < v.size(); i++)
		{
			// 사이클이 형성되었는지 확인
			if (v[i] == now)
			{
				// 사이클 만큼 check
				for (int j = i; j < v.size(); j++)
					check[v[j]] = true;
			}
		}
		return;
	}
	
	visit[now] = true;
	v.push_back(now);

	// 깊이 탐색
	DFS(next);
}

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
	cin >> T;

	while (T-- > 0)
	{
		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
		cnt = 0;
		// 각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다.
		cin >> N;
		// 각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.
		for (int i = 1; i <= N; i++)
			cin >> number[i];

		for (int i = 1; i <= N; i++)
		{
			// 이미 팀이되는지 아닌지 앞서 체크했다면 건너뛴다.
			if (visit[i] == true)
				continue;

			// 깊이 우선 탐색
			v.clear();
			DFS(i);
		}
		
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == false)
				cnt++;
		}

		// 각 테스트 케이스마다 한 줄에 출력하고, 각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.
		cout << cnt << '\n';
	}

	return 0;
}