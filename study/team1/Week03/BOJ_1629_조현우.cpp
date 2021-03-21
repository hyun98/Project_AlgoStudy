//
//       A�� B�� ���� ���� C�� ���� �������� ����Ѵ�.
//

#include <iostream>

using namespace std;

int MOD;
int A;

long long divide(int B){
    if(B == 1) return A;
    
    long long result = divide(B/2);
    
    if(B % 2 == 1)  return ((result * result) % MOD * A) % MOD;
    else            return (result * result) % MOD;
}

int main(){
    int B;
    cin >> A >> B >> MOD;
    A %= MOD;
    cout << divide(B);
    return 0;
}
