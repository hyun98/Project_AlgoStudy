// BOJ_1992
// 2020KB, 0ms
/*
흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다. 흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서 같은 숫자의 점들이 한 곳에 많이 몰려있으면, 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.
주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다
*/
#include <iostream>

using namespace std;

int N;
string* map;


bool IsZero(int left, int up, int size)
{
	for (int i = up; i < up + size; i++)
	{
		for (int j = left; j < left + size; j++)
		{
			if (map[i][j] != '0')
				return false;
		}
	}

	return true;
}

bool IsOne(int left, int up, int size)
{
	for (int i = up; i < up + size; i++)
	{
		for (int j = left; j < left + size; j++)
		{
			if (map[i][j] != '1')
				return false;
		}
	}

	return true;
}

void QuadTree(int left, int up, int size)
{
	if (IsZero(left, up, size) == true)
	{
		cout << 0;
		return;
	}

	if (IsOne(left, up, size) == true)
	{
		cout << 1;
		return;
	}

    // 1사분면, 2사분면, 3사분면, 4사분면
	// 괄호 열기
	cout << '(';
	QuadTree(left, up, size / 2);
	QuadTree(left + size / 2, up, size / 2);
	QuadTree(left, up + size / 2, size / 2);
	// 괄호 닫기
	QuadTree(left + size / 2, up + size / 2, size / 2);
	cout << ')';
}

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며, 1 ≤ N ≤ 64의 범위를 가진다.  
	cin >> N;

	// 두 번째 줄부터는 길이 N의 문자열이 N개 들어온다. 각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.
	map = new string[N];
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		map[i] = s;
	}

	QuadTree(0, 0, N);

	return 0;
}