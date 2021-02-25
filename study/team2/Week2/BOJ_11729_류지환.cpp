#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vans;

int N, cnt =0;

int step(int num, int sidx, int eidx){

    if(num == 0) return 0;

    else{

        cnt++;

        int midx = 6- (sidx+eidx);

        step(num-1, sidx, midx);

        vans.push_back(make_pair(sidx, eidx));

        return step(num-1, midx, eidx);
    }
}

int main()
{
    cin >> N;

    step(N, 1, 3);

    cout << cnt;

    for(auto ans: vans) cout << "\n" << ans.first << " "<< ans.second;

    return 0;
}
