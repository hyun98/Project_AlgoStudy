#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>>matrix;
int N;
long long ans = 0;

int main()
{
    cin >> N;

    matrix.resize(N+1);

    for(auto& row: matrix){
        row.resize(10);
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<10; j++){
            switch(i){
            case 0:
                matrix.at(i).at(j) = 0;
                break;
            case 1:
                matrix.at(i).at(j) = 1;
                break;
            default:
                for(int k=0; k<=j;k++)
                matrix.at(i).at(j) += matrix.at(i-1).at(k);

                matrix.at(i).at(j) %= 10007;
                break;
            }
            if(i == N) ans += matrix.at(i).at(j);
        }
    }


    cout << ans%10007;

    return 0;
}
