import sys

N = int(input())
arr = list(map(int, sys.stdin.readline().split()))
# max_count = 0
# for i in range(N):
#     count = 0
#     temp = 0
#     for j in range(i,N):
#         if temp < arr[j]:
#             temp = arr[j]
#             count += 1
#     max_count = max(max_count,count)
# print(max_count)
dp = [1 for i in range(N)]
for i in range(N):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j]+1)
print(max(dp))