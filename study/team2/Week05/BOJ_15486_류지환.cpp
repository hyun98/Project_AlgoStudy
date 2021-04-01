#include <bits/stdc++.h>
#define  MAX_N 1500001

using namespace std;
typedef pair<int, int> work;

int N, maxDP = INT_MIN;
work day;
int DP[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=1; i<= N+1; i++){

        if(i != N+1)
            cin >> day.first >> day.second;

        int startDay = i, endDay = i+day.first, wPay;

        maxDP = max(maxDP, DP[startDay]);

        DP[startDay] = maxDP;

        if(endDay <= N+1){
            wPay     = DP[startDay] + day.second;

            DP[endDay] = max(wPay, DP[endDay]);
        }
    }

    cout << DP[N+1];



    return 0;
}
