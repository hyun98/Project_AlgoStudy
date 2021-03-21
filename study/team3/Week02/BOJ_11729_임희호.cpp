#include <iostream>
#include <vector>

using namespace std;

int N;
// 이동 경로 저장
vector<pair<int, int>> v;

void TowerOfHanoi(int n, int from, int bypass, int to)
{
	if (n == 1)
		v.push_back({ from, to });
	else
	{
		TowerOfHanoi(n - 1, from, to, bypass);
		v.push_back({ from, to });
		TowerOfHanoi(n - 1, bypass, from, to);
	}
}

int main()
{
	// 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.
	cin >> N;

	TowerOfHanoi(N, 1, 2, 3);

	// 첫째 줄에 옮긴 횟수 K를 출력한다.
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}