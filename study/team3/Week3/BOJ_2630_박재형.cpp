#include <iostream>

using namespace std;

int N;
bool paper[128][128];
int cnt_white = 0, cnt_blue = 0;
bool all_white;
bool all_blue;

const int WHITE = 0;
const int BLUE = 1;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];
}

void search(int istart, int jstart, int size)
{
	all_white = 1;
	all_blue = 1;
	for (int i = istart; i < istart+size; i++)
		for (int j = jstart; j < jstart+size; j++)
		{
			if ((paper[istart][jstart] == WHITE) && (paper[i][j] == BLUE))
			{
				all_white = 0;
				goto exit_loop;
			}
			if ((paper[istart][jstart] == BLUE)&&(paper[i][j] == WHITE))
			{
				all_blue = 0;
				goto exit_loop;
			}
		}
	
	exit_loop:
	if (all_white && paper[istart][jstart]==WHITE)
	{
		cnt_white++;
		return;
	}
	if (all_blue && paper[istart][jstart]==BLUE)
	{
		cnt_blue++;
		return;
	}
	search(istart, jstart, size/2);
	search(istart + size / 2, jstart, size / 2);
	search(istart, jstart + size / 2, size / 2);
	search(istart + size / 2, jstart + size / 2, size / 2);
}

void solve()
{
	search(0, 0, N);
}

void output()
{
	cout << cnt_white << endl;
	cout << cnt_blue << endl;
}

int main()
{
	input();
	solve();
	output();

	return 0;
}