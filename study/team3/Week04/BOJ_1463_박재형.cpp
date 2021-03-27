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

    dp[1] = 0; // 1인 경우부터 시작이므로

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1; // 1번 : 1을 빼주는 경우
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);  // 2번 : 2의 배수일 경우
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);   // 3번 : 3의 배수일 경우
    }
    printf("%d", dp[N]);

    delete[] dp;

    return 0;
}