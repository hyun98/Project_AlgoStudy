#include <bits/stdc++.h>

using namespace std;
vector<long long> DP;
int N;
int main()
{
    cin >>N;
    DP.resize(N+1);
    DP.at(0) = 1; DP.at(1) = 1;
    for(int i=2; i<=N; i++){
        DP.at(i) = (DP.at(i-1) + DP.at(i-2))%10007;
    }

    cout << DP.at(N);
    return 0;
}
