#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    int N;
    scanf("%d", &N);

    int* dp = new int[N + 1]{ 0 };

    dp[1] = 0; // 1�� ������ �����̹Ƿ�

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1; // 1�� : 1�� ���ִ� ���
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);  // 2�� : 2�� ����� ���
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);   // 3�� : 3�� ����� ���
    }
    printf("%d", dp[N]);

    delete[] dp;

    return 0;
}