// BOJ_11058
// 2016KB, 0ms
/*
 크리보드는 kriii가 만든 신기한 키보드이다. 크리보드에는 버튼이 4개만 있으며, 하는 역할은 다음과 같다.

화면에 A를 출력한다.
Ctrl-A: 화면을 전체 선택한다
Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.
크리보드의 버튼을 총 N번 눌러서 화면에 출력된 A개수를 최대로하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long memory[101] = { 0, };

long long DP(int n)
{
	if (n <= 6)
		return n;

	if (memory[n] != 0)
		return memory[n];

	// 선택 - 복사 - 붙혀넣기(반복)이 이루어진 경우
	if (n > 6)
	{
		// Ctrl + V를 1번에서 여러번 누를 때 까지
		for (int i = 1; i <= n - 2; i++)
		{
			// 최대값(이전 경우 , A가 추가된 경우, Ctrl + V를 i번 누른 경우)
			memory[n] = max({ memory[n], DP(n-1) + 1, DP((n - 2) - i) * (i + 1) });
		}
	}

	return memory[n];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
	cin >> N;

	// 크리보드의 버튼을 총 N번 눌러서 화면에 출력할 수 있는 A 개수의 최댓값을 출력한다.
	cout << DP(N);

	return 0;
}