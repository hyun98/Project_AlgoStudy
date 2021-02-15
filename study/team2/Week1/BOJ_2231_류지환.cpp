#include <bits/stdc++.h>

using namespace std;

string str;
int range =0, M, N;

int main()
{
    cin >> str;
    N = stoi(str);

    for(int i=0; i < (int)str.length(); i++) range += 9;

    for(int j = N - range; j < N; j++){

        M = j;
        str = to_string(j);

        for(auto c: str) M += (int)(c - '0');

        if(M == N){
            cout << j;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
