#include <bits/stdc++.h>
#define MAX_N 1001


using namespace std;

vector<int> vdata;
int N, ans = 0;
int DP[MAX_N];

int main()
{

    cin >> N;

    vdata.resize(N);

    for(auto& d: vdata){
        cin >> d;
    }

    for(int i=0; i<N; i++){
        int dpVal = 1;

        for(int j=0; j<i; j++){
            if(vdata.at(i) > vdata.at(j)){
                dpVal = max(dpVal, DP[j]+1);
            }
        }

        DP[i] = dpVal;
        ans = max(ans, DP[i]);
    }


    cout << ans;
    return 0;
}
