#include <iostream>
#include <string>

using namespace std;

int N = 0;
int MIN_Constructor = 0;

// 분해합을 생성하는 함수
int Decomposition(int n)
{
	int result = 0;
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++)
	{
		// 문자를 숫자로 바꾸는 방법
		result += str[i] - '0';
	}

	return n + result;
}

void solution()
{
	for (int i = 1; i < N; i++)
	{
		// Decomposition(분해합)의 결과가 N의 생성자라면
		if (Decomposition(i) == N)
		{
			// 처음 발견된(가장 작은) 생성자가 결정 후 return
			MIN_Constructor = i;
			return;
		}
	}
}

int main()
{
	// 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
	while(N < 1 || N > 1000000)
		cin >> N;
	
	solution();

	cout << MIN_Constructor << endl;

	return 0;
}