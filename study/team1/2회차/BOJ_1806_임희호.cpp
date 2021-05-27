// BOJ_1806
// 2212KB, 8ms
#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
short NS[100000];
int answer = INT32_MAX;

int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// 첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다.
	cin >> N >> S;

	// 둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.
	for (int i = 0; i < N; i++)
		cin >> NS[i];

	// 첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.
	int sum = NS[0];
	int start = 0, last = 0;
	while(last < N)
	{
		// 부분 수열의 합이 S이상이 됐으면
		if (sum >= S)
		{
			// start 인텍스를 증가시켜가면서 가능한 짧은 수열을 만든다.
			while (sum - NS[start] >= S)
			{
				sum = sum - NS[start];
				start++;
			}
			// last 인덱스가 정해져있을 때 가장 짧은 길이
			answer = min(answer, last - start + 1);
		}

		// 부분 수열의 합이 S이상이 될때까지 last인덱스를 증가시킨다.
		last++;
		sum += NS[last];
	}

	// 첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.
	if (answer != INT32_MAX)
		cout << answer;
	else
		cout << 0;

	return 0;
}