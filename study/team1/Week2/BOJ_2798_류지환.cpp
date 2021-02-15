#include <bits/stdc++.h>

using namespace std;

int N, M, ans = -300000;
vector<int> deck, picked;

void pick(){
    if(picked.size() == 3){
        int temp = 0;
        for(auto idx: picked) temp += deck.at(idx);
        if(temp <= M && abs(M - ans) > abs(M - temp)) ans = temp;
        return ;
    }

    int smallest;

    if(picked.empty()) smallest = 0;
    else               smallest = picked.back()+1;

    for(int next = smallest; next<N; next++){
        picked.push_back(next);
        pick();
        picked.pop_back();
    }
}// 종만북 p.149_코드_6.2 참고 및 변형


int main()
{

    cin >> N >> M;
    deck.resize(N);

    for(auto& card: deck) cin >> card;

    pick();

    cout << ans;

    return 0;
}
