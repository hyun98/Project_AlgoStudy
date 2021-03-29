n = int(input())
_list = list(map(int, input().split()))
dp = [x for x in _list]

for i in range(n):
    for j in range(i):
        if _list[i] > _list[j]:
            dp[i] = max(dp[i], dp[j] + _list[i])
print(max(dp))
