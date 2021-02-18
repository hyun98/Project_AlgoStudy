#include <bits/stdc++.h>

using namespace std;

vector<int>         picked;
vector<vector<int>> vvcost;

int  N, data, cost, total, p_now, p_next, ans = numeric_limits<int>::max();
bool trip;

void input(){
    cin >> N;

    vvcost.resize(N);
    for(auto& vc: vvcost) vc.resize(N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> vvcost.at(i).at(j);
        picked.push_back(i);
    }
    return;
}

void pick(){
    do{
        total = 0;
        for(int i=0; i< picked.size(); i++){
            p_now = picked.at(i);
            if(i == picked.size()-1) p_next = picked.front();
            else                     p_next = picked.at(i+1);

            cost = vvcost.at(p_now).at(p_next);
            trip = !!cost;

            if(!trip) break;

            total += cost;
        }

        if(trip) ans = min(ans, total);

    }while(next_permutation(picked.begin(), picked.end()));

    return;
}

int main()
{
    input();

    pick ();

    cout << ans;

    return 0;
}
