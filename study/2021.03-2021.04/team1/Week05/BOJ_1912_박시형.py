import sys
n = int(input())
arr = list(map(int,sys.stdin.readline().split()))
dp = [arr[0]] + [0 for _ in range(n-1)]
for i in range(1,n):
    dp[i] = max(arr[i], dp[i-1]+arr[i])
print(max(dp))
