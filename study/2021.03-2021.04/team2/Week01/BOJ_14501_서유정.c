#include <stdio.h>
#define _CRT_SECURE_NO_WARNING
int main()
{
	int n;
	int t[16] = { 0 };
	int p[16] = { 0 };
	int d[16] = { 0 };


	scanf("%d", &n); //퇴사 날짜를 입력 받음
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &t[i], &p[i]); // 상담 기간과 금액을 입력받음
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j + t[j] - 1 <= i) {
				if (d[i] < d[j - 1] + p[j]) {
					d[i] = d[j - 1] + p[j];
				}
			}
		}
	}


	printf("%d", d[n]);
	return 0;
}
