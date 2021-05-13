// BOJ_11726
// 2020KB, 0ms
/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
*/
#include <iostream>

using namespace std;

int N;
int memory[1001];

int Fill(int n)
{
	// 1. 일자로 세우는 경우
	// 2. 가로로 세우는 경우
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (memory[n] != 0)
		return memory[n];
	return memory[n] = (Fill(n - 1) + Fill(n - 2)) % 10007;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
	cin >> N;

	// 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
	cout << Fill(N);

	return 0;
}