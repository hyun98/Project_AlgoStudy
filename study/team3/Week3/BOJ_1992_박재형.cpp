#include <iostream>
#include <cstdio>
using namespace std;

int N;
bool screen[64][64];
bool all_white;
bool all_black;

const int WHITE = 0;
const int BLACK = 1;

void input()
{
	cin >> N;
	string num;
	for (int i = 0; i < N; i++) 
	{
		cin >> num;
		for (int j = 0; j < N; j++)
			screen[i][j] = num[j] - '0';
	}
}

void search(int istart, int jstart, int size)
{
	all_black = 1;
	all_white = 1;

	for (int i = istart; i < istart + size; i++)
		for (int j = jstart; j < jstart + size; j++)
		{
			if ((screen[istart][jstart] == WHITE) && (screen[i][j] == BLACK))
			{
				all_white = 0;
				goto exit_loop;
			}
			if ((screen[istart][jstart] == BLACK) && (screen[i][j] == WHITE))
			{
				all_black = 0;
				goto exit_loop;
			}

		}

exit_loop:
	if (all_white && screen[istart][jstart] == WHITE)
	{
		printf("0");

		return;
	}
	if (all_black && screen[istart][jstart] == BLACK)
	{
		printf("1");

		return;
	}

	printf("(");
	search(istart, jstart, size / 2);
	search(istart, jstart + size / 2, size / 2);
	search(istart + size / 2, jstart, size / 2);
	search(istart + size / 2, jstart + size / 2, size / 2);
	printf(")");
}

void solve()
{
	int first_same = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (screen[i][j] != screen[0][0])
				first_same = 0;
		}
	search(0, 0, N);
}

int main()
{
	input();
	solve();

	return 0;
}