#include <bits/stdc++.h>

using namespace std;

vector<int> picked;
vector<pair<int, int>> week;
pair<int, int> day;
int N, pay, maxPay, work;


void pick(){
    int smallest;

    if(picked.empty()) smallest = 0;
    else               smallest = picked.back()+week.at(picked.back()).first;

    if(N <= smallest){
        pay = 0;

        for(auto p: picked)
            if(week.at(p).first + p <= N)   pay += week.at(p).second;

        maxPay = max(pay, maxPay);
        return;
    }

    for(int next = smallest; next<N; next++){
        picked.push_back(next);
        pick();
        picked.pop_back();
    }

}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> day.first >> day.second;
        week.push_back(day);
    }

    pick();

    cout << maxPay;

    return 0;
}
