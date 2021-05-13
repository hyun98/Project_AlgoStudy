#include <bits/stdc++.h>

using namespace std;

vector<int> DP, vnum;
int T, maxN = 0;
int main()
{
    cin >>T;

    vnum.resize(T);

    for(auto& n: vnum){
        cin >> n;
        maxN = max(n, maxN);
    }

    DP.resize(maxN+1);
    DP.at(1) = 1;

    for(int i=2; i<=maxN; i++){
        switch(i){
        case 2:
            DP.at(i) = DP.at(i-1) +1;
            break;
        case 3:
            DP.at(i) = DP.at(i-2) + DP.at(i-1) + 1;
            break;
        default:
             DP.at(i) = DP.at(i-3) + DP.at(i-2) + DP.at(i-1);
             break;
        }
    }

    for(auto n: vnum){
        cout << DP.at(n) <<endl;
    }
    return 0;
}
