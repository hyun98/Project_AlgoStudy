#include <iostream>

using namespace std;
#define MAX(X, Y) X > Y? X : Y

int N = 0;
int T[20] = { 0, };
int P[20] = { 0, };
int value[20] = { 0, };
int answer = 0;

void input()
{
	// 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
	while (N < 1 || N > 15)
		cin >> N;

	// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1, 000)
	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}
}

int solution(int index)
{
	// 재귀함수에서 다음 시작할 인덱스
	int nextIndex = index + T[index];

	// 수행 불가
	if (nextIndex > N)
		return 0;
	// 수행하고 리턴(값 판단은 호출 함수에서)
	if (nextIndex == N)
		return P[index];
	
	for (int i = nextIndex; i < N; i++)
	{
		// 현재 이익과 다음 일정의 이익을 더해서 저장하고
		int temp = solution(i) + P[index];
		// 현재까지 이익중 가장 큰 값을 저장한다.
		value[index] = MAX(value[index], temp);
	}

	return value[index];
}

int solution(int index, int Profit)
{
	// index값이 퇴사일과 같다면 현재까지 이익중 큰 값을 반환
	if (index == N)
		return MAX(answer, Profit);

	// index값이 퇴사일 이후라면 0 반환
	if (index > N)
		return 0;

	return MAX(
		// 수행하고 수행한 날만큼 이동
		solution(index + T[index], Profit + P[index]),
		// 수행하지 않고 다음으로
		solution(index + 1, Profit)
	);
}

int main()
{
	input();

	/*for (int i = 0; i < N; i++)
	{
		answer = MAX(answer, solution(i));
	}

	cout << answer << endl;*/

	cout << solution(0, 0) << endl;

	return 0;
}