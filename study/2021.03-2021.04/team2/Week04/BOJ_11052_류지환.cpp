#include <bits/stdc++.h>

using namespace std;

vector<int> vpack, DP;
int N, price;

int main()
{
    cin >> N;

    vpack.push_back(0);

    for(int i=0; i<N; i++){
        cin >> price;
        vpack.push_back(price);
    }


    for(int i=0; i<=N; i++){
        switch(i){
        case 0:
            DP.push_back(i);
            break;
        case 1:
            DP.push_back(vpack.at(i));
            break;
        default:
            DP.push_back(vpack.at(i));
            for(int j=1; j<i; j++){
                DP.at(i) = max(DP.at(i), DP.at(i-j) + DP.at(j));
            }
            break;
        }
    }

    cout << DP.at(N);

    return 0;
}
