// BOJ_11052
// 2024KB, 0ms
/*
카드 팩의 가격이 주어졌을 때, N개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최댓값을 구하는 프로그램을 작성하시오. 
N개보다 많은 개수의 카드를 산 다음, 나머지 카드를 버려서 N개를 만드는 것은 불가능하다. 
즉, 구매한 카드팩에 포함되어 있는 카드 개수의 합은 N과 같아야 한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int card[1001];
int memory[1001] = { 0 };

int DP(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return card[1];

	// 정보가 있으면 사용
	if (memory[n] != 0)
		return memory[n];

	// 선택한 카드 번호 만큼 줄여서 다시 동적계획
	for (int i = 1; i <= n; i++)
	{
		memory[n] = max(memory[n], DP(n - i) + card[i]);
	}

	return memory[n];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
	cin >> N;

	// 둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)
	for (int i = 1; i <= N; i++)
		cin >> card[i];

	// 첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최댓값을 출력한다.
	cout << DP(N);
	
	return 0;
}