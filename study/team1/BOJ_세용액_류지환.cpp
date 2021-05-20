#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll>::iterator vi;


int N;

ll ansVal = LLONG_MAX;

vector<ll> vans(3);
vector<ll> vliquid;

int main()
{
    cin >> N;

    vliquid.resize(N);

    for(auto& liq: vliquid) cin >> liq;


    sort(vliquid.begin(), vliquid.end());

    for(vi first = vliquid.begin(); first < vliquid.end() - 2; first++){
         vi left = first+1, right = vliquid.end()-1;

         while(left < right){
            ll tempVal = *right + *left + *first;;

            if(tempVal == 0){
                vans.at(0) = *first;
                vans.at(1) = *left ;
                vans.at(2) = *right;
                break;
            }

            if(abs(tempVal) < abs(ansVal)){
                ansVal = tempVal;
                vans.at(0) = *first;
                vans.at(1) = *left ;
                vans.at(2) = *right;
            }


            if(tempVal > 0){
                right -= 1;
            }

            else{
                left += 1;
            }
        }

    }



    for(auto ans: vans) cout << ans <<" ";


    return 0;
}
