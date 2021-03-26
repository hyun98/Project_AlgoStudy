// BOJ_1463
// 29240KB, 36ms
/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int *memory;

int MakeN(int n)
{
	int _case[3] = { INT32_MAX, INT32_MAX, INT32_MAX };

	// 가장 작은 단위
	if (n == 1)	
		return 0;
	if (n == 2 || n == 3)	
		return 1;

	// 이미 구한 값이 있으면 그 값을 리턴
	if (memory[n] != 0)
		return memory[n];

	// 각각의 case에 대해 계산
	if (n % 3 == 0)	
		_case[0] = MakeN(n / 3) + 1;
	if (n % 2 == 0)
		_case[1] = MakeN(n / 2) + 1;
					
	_case[2] = MakeN(n-1) + 1;

	// 3가지 경우중 가장 작은 값을 저장
	return memory[n] = min({ _case[0], _case[1], _case[2] });
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.
	cin >> N;
	memory = new int[N+1] {0, };

	// 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
	cout << MakeN(N);

	delete[] memory;

	return 0;
}