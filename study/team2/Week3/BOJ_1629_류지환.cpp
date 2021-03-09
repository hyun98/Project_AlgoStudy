#include <bits/stdc++.h>

using namespace std;

int A, B, C;
long long ans;

int pow(long long A, int B, int C){
    if(B == 1) return A%C;
    if(B % 2 == 0){
        long long r= pow(A, B/2, C);
        return (r*r)%C;
    }
    else
        return (A * pow(A, B-1, C)) % C;

}

int main()
{
    cin >> A >> B >>C;


    cout << pow(A, B, C);
    return 0;
}
