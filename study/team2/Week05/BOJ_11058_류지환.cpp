#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll DP[101];

int N;

ll solve(int n){
    DP[n] = DP[n-1]+1;

    for(int i=3; i<n; i++)
        DP[n] = max(DP[n], DP[i-2] + ((ll)(n-i)) * DP[i-2]);

    if(n == N) return DP[n];

    return solve(n+1);
}

int main()
{
    cin >> N;

    DP[0] = 0;
    cout << solve(1);

    return 0;
}
