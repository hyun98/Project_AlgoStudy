#include <iostream>
#include <random>
#include <vector>
#include <functional>

using namespace std;

// 카드 개수, 각각의 카드
int N=0;
vector<int> card;

int M = 0;
int sum = 0;

// 자동 입력
/*
void input()
{
	// 하드웨어 리소스를 사용한 시드 설정
	random_device rng;
	// 난수 생성기
	mt19937 mtRand(rng());

	// 첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다.
	uniform_int_distribution<int> dist1(3, 100);
	uniform_int_distribution<int> dist2(10, 300000);
	N = dist1(mtRand);
	M = dist2(mtRand);
	cout << N << " " << M << endl;

	// 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다.
	for (int i = 0; i < N; i++)
	{
		uniform_int_distribution<int> dist(10, M);
		card.push_back(dist(mtRand));
		cout << card[i] << " ";
	}
	cout << endl;
}
*/

void input()
{
	// 첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다.
	while (N > 100 || N < 3 || M < 10 || M > 300000)
	{
		cin >> N >> M;
	}
		

	// 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다.
	for (int i = 0; i < N; i++)
	{
		int value = -1;
		while(value < 0 || value > 100000 || value > M)
			cin >> value;
		card.push_back(value);
	}
}

void BlackjackProcess()
{
	// 카드 수 N, 목표 숫자 M, 카드 값이 결정된다.
	input();

	// Process
	for (int i = 0; i < card.size() - 2; i++)
	{
		for (int j = i + 1; j < card.size() - 1; j++)
		{
			for (int k = j + 1; k < card.size(); k++)
			{
				int temp_sum = card[i] + card[j] + card[k];

				// 결정한 카드 값중 3장의 합이 M을 넘지않고 
				if (temp_sum > M)
					continue;
				// 최대에 가장 가까운 카드를 선택한다.
				if (temp_sum > sum)
				{
					sum = temp_sum;
				}
					
			}
		}
	}
}

void output()
{
	cout << sum << endl;
}

int main()
{
	// 어떤 3장의 카드도 조건을 만족하지 못한는 동안 반복한다.
	while(sum == 0)
		BlackjackProcess();

	// 선택한 카드를 출력한다.
	output();

	return 0;

}