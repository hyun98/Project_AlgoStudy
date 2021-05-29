#include<stdio.h>
#include<math.h>

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int main() {
	int n;
	scanf("%d", &n); //���� N�Է�
    
	
	int dp[100001] = { 0 }; //dp 0���� �ʱ�ȭ

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i; //n=n(1*1)�� ���
        for (int j = 1; j <= sqrt(i); j++) // 1 < j < (��Ʈ)i
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1); //�ּڰ� ��
        }
    }

    printf("%d", dp[n]); //������ ���� �ּ� ������ ���
    return 0;
}