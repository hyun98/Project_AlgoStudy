// BOJ_1197
// 6524KB, 140ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define START 1

using namespace std;

// 그래프
vector<pair<int, int>> W[10001];
// 방문 여부
int visited[10001] = { 0, };
// 최소비용 신장트리 이음선 집합
vector<int> F;
// 정점개수, 간선개수
short NV;
int NE;

void PrimeAlgorithm(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	visited[1] = start;
	for (int i = 0; i < W[start].size(); i++)
	{
		// 가중치를 기준으로 최소힙
		pq.push({ W[start][i].first	, W[start][i].second });
	}

	while (!pq.empty())
	{
		pair<int, int> _select = { pq.top().first, pq.top().second };
		int _minIndex = _select.second;
		int _minDistance = _select.first;
		pq.pop();

		// 방문한 곳이면 다른 곳으로
		if (visited[_minIndex] != 0)
			continue;
		
		// 방문 체크후 MST에 넣기
		visited[_minIndex] = 1;
		F.push_back(_select.first);
		
		// 다음 방문 후보 넣기
		for (int i = 0; i < W[_minIndex].size(); i++)
		{
			if (visited[W[_minIndex][i].second] != 0)
				continue;
			
			pq.push({ W[_minIndex][i].first, W[_minIndex][i].second });
		}
	}
}

int main()
{
	//cin.tie(nullptr); cout.tie(nullptr);
	//ios::sync_with_stdio(false);

	// 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다.
	cin >> NV >> NE;

	/* 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.
	 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. \
	 C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.*/
	for (int i = 0; i < NE; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		// A와 B가 C의 가중치로 연결되어 있다.
		W[A].push_back({ C, B });
		W[B].push_back({ C, A });
	}
	
	// Prim Algorithm
	PrimeAlgorithm(1);


	// 출력
	int sum = 0;
	for(int i=0; i<F.size(); i++)
		sum += F[i];
	
	cout << sum;

	return 0;
}