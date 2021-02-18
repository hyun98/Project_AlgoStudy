#include <iostream>

using namespace std;

inline int decompose_sum(int num){
    int be = num;
    int sum = 0;
    while(be){
        sum += (be % 10);
        be /= 10;
    }
    return sum + num;
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        if(N == decompose_sum(i)){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
