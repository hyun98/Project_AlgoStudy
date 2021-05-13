#include <bits/stdc++.h>

using namespace std;

int N, data, ans = INT_MIN, minDP = INT_MAX;

vector<int> DP;
vector<int> vdata;

int main()
{
    cin >> N;
    DP.resize(N+1);
    vdata.resize(N);

    for(int i=0; i<N; i++){
        cin >> vdata.at(i);
        DP.at(i+1) = vdata.at(i) + DP.at(i);
    }

    for(int i=1; i<=N;i++){
        minDP = min(minDP, DP.at(i-1));
        ans   = max(ans, DP.at(i) - minDP);
    }

    cout << ans;


    return 0;
}
