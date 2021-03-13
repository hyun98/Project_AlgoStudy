// BOJ_1629
// 2016KB, 0ms
/*
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
*/
#include <iostream>

using namespace std;
typedef long long ll;

ll A, B, C;

// 1. 나머지 연산자 규칙
// A * B % C = (A % C) * (B % C) % C 

// 2. log(n)으로 거듭제곱을 수행할 수 있는 방법
// b:짝수 : a^b = a^(b / 2) * a^(b / 2)
// b:홀수 : a^b = a^(b / 2) * a^(b / 2) * a
ll solution(ll A, ll B)
{
	if (B == 1)
		return A % C;

    // ex) B = 100, 50, 25, 12, 6, 3, 1
	ll temp = solution(A, B / 2);

	if (B % 2 == 0)
		return (temp * temp) % C;
	else
		return ((temp * temp) % C) * A % C;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.
	cin >> A >> B >> C;

	// 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
	cout << solution(A, B);

	return 0;
}