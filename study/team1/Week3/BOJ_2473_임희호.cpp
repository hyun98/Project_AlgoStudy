// BOJ_2473
// 2056KB, 16ms
#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long value[5000];
int main()
{
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);

	// 첫째 줄에는 전체 용액의 수 N이 입력된다.N은 3 이상 5, 000 이하의 정수이다.
	cin >> N;

	// 둘째 줄에는 용액의 특성값을 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다.
	for (int i = 0; i < N; i++)
		cin >> value[i];

	// 배열 정렬
	sort(value, value + N);

	long long _min = 9223372036854775807;
	int L = 0, M = 0, R = 0;
	
	// 가운데 값을 증가시켜가며 찾는다.
	for(int mid = 1; mid < N-1; mid++)
	{
		int low = 0;
		int high = N - 1;
		while (1)
		{
			// high와 low를 줄이다가 mid와 같아져버리면 탈출
			if (high <= mid || low >= mid)
				break;

			long long temp = value[low] + value[mid] + value[high];

			if (abs(temp) < _min)
			{
				_min = abs(temp);
				L = low;
				M = mid;
				R = high;
			}
			
			// high와 low를 줄여가며 반복
			if (temp > 0)
				high--;
			else if (temp < 0)
				low++;
			else	// temp가 0인 경우 더 볼 필요 없이 종료
				mid = N - 1;
		}
	}

	cout << value[L] << " " << value[M] << " " << value[R] << '\n';

	return 0;
}