#include <stdio.h>
#define _CRT_SECURE_NO_WARNING
int main()
{
	int i, j, k , jack = 0;
	int n, m;
	int sum = 0;
	int kard[100] = { 0 };
	scanf("%d%d", &n, &m); //N과 M 입력
	for (i = 0;i < n ;i++)
	{
		scanf("%d", &kard[i]); //N장의 카드값 입력
		//printf("%d ", kard[i]); //N장의 카드값 출력
	}
	for(i = 0;i < n-2 ;i++)
		for(j = 0; j < n-1; j++)
			for (k = 0; k < n; k++) {
				if (i != j && j != k && k != i){
				sum = kard[i] + kard[j] + kard[k]; //카드 3장의 합을 구함
				}
				if (jack < sum && sum <=  m)
					jack = sum; //앞서 구한 합보다 크고, M보다 값이 작을 때 반복문을 빠져나감
			}
	printf("%d", jack);
	return 0;
}
