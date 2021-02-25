#include <iostream>
#include <string>
using namespace std;

int N, cnt = 0;
string result = "";
// ��� ��ȣ a, b, c   �Űܾ� �� ������ ���� N
void hanoi(int a, int b, int c, int n){
    cnt++;
    
    if(n == 1) result += (to_string(a) + " " + to_string(c) + "\n");
    else{
        hanoi(a, c, b, n-1);
        result += (to_string(a) + " " + to_string(c) + "\n");
        hanoi(b, a, c, n-1);
    }
}

int main(){
    cin >> N;
    hanoi(1, 2, 3, N);
    cout << cnt << "\n";
    cout << result;
    return 0;
}
