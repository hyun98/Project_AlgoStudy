#include <iostream>
using namespace std;

int main() {
    int n, dp[1001];
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        // i-1과 i-2의 합으로 구성이 된다.
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[n] << '\n';
    return 0;
}
