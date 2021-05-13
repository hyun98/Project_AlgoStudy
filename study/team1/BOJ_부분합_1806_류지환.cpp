#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int>::iterator vi;

int N, num, ans = INT_MAX;

vector<int> vnum;

ll S, sum = 0;

int main()
{
    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> num;
        vnum.push_back(num);
    }

    vi left = vnum.begin(), right = vnum.begin();

    while(left <= right){
        if(sum >= S){
            ans = min(ans, (int)(right - left));
            sum -= *left++;
        }
        else{
            if(right == vnum.end()) break;
            sum += *right++;
        }
    }

    if(ans == INT_MAX) ans = 0;

    cout << ans;

    return 0;
}
