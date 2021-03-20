#include <iostream>

/*
먼저 알아야 할 나머지 연산의 분배법칙
(A*B)%M = ((A%M)*(B%M))%M
*/

long long int pow(long long int A, long long int B, long long int C)
{
	if (B == 0)
		return 1;
	else if (B == 1)
		return A;
	else if (B % 2 == 0)
	{
		long long int half = (pow(A, B / 2, C));
		half %= C;
		return (half * half)%C;
	}
	else
		return (pow(A, B-1, C) * A) % C;
}

int main()
{
	using namespace std;
	long long int A, B, C;
	cin >> A >> B >> C;

	cout << pow(A, B, C) << endl;

	return 0;
}