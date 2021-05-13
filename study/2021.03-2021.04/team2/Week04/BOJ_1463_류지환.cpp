#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

vector<int> DP;
int N;

int main()
{

    cin >> N;

    DP.resize(N+1);

    for(int i=2; i<=N; i++){
        DP.at(i) = DP.at(i-1)+1;
        if(i%2 == 0) DP.at(i) = min(DP.at(i), DP.at(i/2)+1);
        if(i%3 == 0) DP.at(i) = min(DP.at(i), DP.at(i/3)+1);
    }

    cout << DP.at(N);

    return 0;
}
