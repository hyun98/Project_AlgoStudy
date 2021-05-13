#include <stdio.h>
#include <stdbool.h>



int N; //도시 수
int visit[11]; //도시 방문 체크
int w[11][11]; //비용 행렬
int m = 987654321; //최소 비용
int sum; //합계


void input(void) {
	scanf("%d", &N); //도시 수 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &w[i][j]); //비용 행렬 입력
}


void sol(int start, int x ,int count, int sum) {
	if (count == N && start == x) //모든 도시 방문 && 다시 돌아온 경우
	{
		if (sum < m)m = sum;
		return;
	}

	for (int y = 0; y < N; y++)
	{
		if (w[x][y] == 0) continue; //갈 수 없는 경우

		if (!visit[x] && w[x][y] > 0) 
		{
			visit[x] = true;
			sum += w[x][y];

			if (sum <= m) //sum이 m보다 작은 경우
			{
				sol(start, y, count+1, sum); //도시 방문
			}

			visit[x] = false; //방문 기록 초기화
			sum -= w[x][y]; //합계 초기화
		}
	}
}


int main() {

	input();

	for (int x = 0; x < N; x++)
		sol(x, x, 0, 0);


	printf("%d", m); //최소 비용 출력
}
