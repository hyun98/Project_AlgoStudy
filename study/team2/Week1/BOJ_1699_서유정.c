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
	scanf("%d", &n); //숫자 N입력
    
	
	int dp[100001] = { 0 }; //dp 0으로 초기화

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i; //n=n(1*1)일 경우
        for (int j = 1; j <= sqrt(i); j++) // 1 < j < (루트)i
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1); //최솟값 비교
        }
    }

    printf("%d", dp[n]); //제곱수 항의 최소 개수를 출력
    return 0;
}
