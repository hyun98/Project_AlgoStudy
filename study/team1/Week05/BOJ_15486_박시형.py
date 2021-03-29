# 오류있음
import sys

N = int(input())
arr_day = []
arr_money = []
dp = [0 for _ in range(N+1)]

for i in range(N):
    a, b = map(int,sys.stdin.readline().split())
    arr_day.append(a)
    arr_money.append(b)
for i in range(N-1,-1,-1):
    if i + arr_day[i] <= N:
        dp[i] = max(dp[i+1],dp[i+arr_day[i]]+arr_money[i])
print(dp[0])


