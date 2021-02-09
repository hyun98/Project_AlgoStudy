#include <iostream>
using namespace std;

int N, Ti[16], Pi[16], dp[16] = {0, };

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Ti[i] >> Pi[i];
    }
}

// dynamic programming bottom-up style O(N^2)
void solve1(){
    int result = 0;
    for(int i = 0; i < N; i++){
        if(Ti[i] + i > N) continue;
        dp[i] = Pi[i];
        for(int j = 0; j < i; j++){
            if(j + Ti[j] > i) continue;
            dp[i] = max(dp[i], Pi[i] + dp[j]);
        }
        result = max(dp[i], result);
    }
    
    cout << result;
}

// dynamic programming top-down style O(N^2)
int solve2(int day){
    if(day + Ti[day] > N) return 0;
    if(day + Ti[day] == N) return Pi[day];
    
    for(int i = day + Ti[day]; i <= N; i++){
        dp[day] = max(dp[day], solve2(i) + Pi[day]);
    }
    return dp[day];
}

// dynamic programming bottom-up style O(N)
void solve3(){
    int result = 0;
    for(int i = N-1; i >= 0; i--){
        int next = i + Ti[i];
        if(next > N){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = max(dp[i+1], dp[next] + Pi[i]);
        }
    }
    cout << dp[0];
}

int main(){
    input();
    int result = 0;
//    for(int i = 0; i < N; i++){
//        result = max(result, solve2(i));
//    }
//    
//    cout << result;
    
    solve3();
    return 0;
}
