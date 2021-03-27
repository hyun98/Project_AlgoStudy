#include <iostream>
using namespace std;

int main() {
    int n, dp[1001];
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      // i-1과 i-2의 합으로 구성이 된다.(i-1 항의 경우에서 오른쪽에 2x1 붙이는 경우,
       // i-2 항의 경우에서 오른쪽에 1x2 두개 붙이는 경우
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[n] << '\n';
    return 0;
}
