import sys
# 카드 구매하기

N = int(input()) # 카드 갯수
arr = [0]+list(map(int,sys.stdin.readline().split())) # 가격
dp = [0]*(N+1) # 최댓값 저장

for i in range(1,N+1):
    for j in range(i+1):
        if dp[i] < dp[j] + arr[i-j]:
            dp[i] = dp[j] + arr[i-j]
print(dp[N])


