#include <iostream>

using namespace std;

// num�� ���� �������� ��ȯ�ϴ� �Լ�
inline int decompose_sum(int num){
    int be = num;
    int sum = 0;
    // num�� 0�� �� ������ 10���� ����
    while(be){
        sum += (be % 10);
        be /= 10;
    }
    return sum + num;
}

int main(){
    int N;
    cin >> N;
    // N�� �����ڰ� N���� Ŭ ���� �����Ƿ� N ���� �ݺ�
    for(int i = 1; i <= N; i++){
        // i�� �������� N�� ������ i�� ����ϰ� �ݺ��� ����
        if(N == decompose_sum(i)){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
