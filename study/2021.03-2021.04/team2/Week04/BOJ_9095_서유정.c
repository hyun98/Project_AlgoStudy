#include <stdio.h>
int main() {
	int T;
	int N;
	
	int cnt[12], output[12];
	cnt[0] = 1;
	cnt[1] = 1;
	cnt[2] = 2;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		for (int j = 3; j <=N; j++) {
			cnt[j] = cnt[j - 1] + cnt[j - 2] + cnt[j - 3];
		}
		output[i] = cnt[N];
		
	}
	for (int i = 0; i < T; i++) {
		printf("%d\n", output[i]);
	}
}
