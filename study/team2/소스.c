#include <stdio.h>

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}
int main() {	
	int num[101] = { 0 };
	int dp[10001];

	int n, k;
	scanf("%d%d", &n, &k);

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	for (int i = 1; i <= k; i++)
	{
		dp[i] = 10001; //�ּڰ��� �����ֱ� ���� k�� �ִ񰪺��� ū ���� �ʱ�ȭ


	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - num[j]] + 1); //�ּڰ� ��
		}
	}
	if(dp[k]== 10001) 
		dp[k] = -1; //�Ұ����� ��� -1

	printf("%d", dp[k]);
	return 0;
}