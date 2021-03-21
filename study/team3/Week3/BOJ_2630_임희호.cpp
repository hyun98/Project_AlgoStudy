// BOJ_2630
// 2148KB, 0ms
/*
입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때 잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <cmath>

using namespace std;

int N;
int** map;

int white = 0;
int blue = 0;

bool IsWhiteColoredPaper(int left, int up, int size)
{
	for (int i = up; i < up + size; i++)
	{
		for (int j = left; j < left + size; j++)
		{
			if (map[i][j] != 0)
				return false;
		}
	}

	return true;
}

bool IsBlueColoredPaper(int left, int up, int size)
{
	for (int i = up; i < up + size; i++)
	{
		for (int j = left; j < left + size; j++)
		{
			if (map[i][j] != 1)
				return false;
		}
	}

	return true;
}

void MakeColoredPaper(int left, int up, int size)
{
	if (IsBlueColoredPaper(left, up, size) == true)
	{
		blue++;
		return;
	}

	if (IsWhiteColoredPaper(left, up, size) == true)
	{
		white++;
		return;
	}

	// 1사분면, 2사분면, 3사분면, 4사분면
	MakeColoredPaper(left, up, size / 2);
	MakeColoredPaper(left + size / 2, up, size / 2);
	MakeColoredPaper(left, up + size / 2, size / 2);
	MakeColoredPaper(left + size / 2, up + size / 2, size / 2);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다. 
	cin >> N;

	// 색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 
	map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	// 매개변수 : 왼쪽, 위, 크기
	MakeColoredPaper(0, 0, N);

	// 첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색 색종이의 개수를 출력한다.
	cout << white << '\n' << blue;


	return 0;
}