n = int(input())

dp = [0 for _ in range(n + 1)]

for i in range(2, n + 1):
    dp[i] = dp[i - 1] + 1

    if i % 2 == 0 and dp[i] > dp[i // 2] + 1:
        dp[i] = dp[i // 2] + 1

    if i % 3 == 0 and dp[i] > dp[i // 3] + 1:
        dp[i] = dp[i // 3] + 1

print(dp[n])

# N = int(input())
#
# count = 0
# arr = [N]
# while True:
#     if 1 in arr:
#         break
#     count += 1
#     arr_temp = []
#     for num in arr:
#         if num%3 == 0:
#             arr_temp.append(N//3)
#         if num%2 == 0:
#             arr_temp.append(N//2)
#         arr_temp.append(num-1)
#     arr = []
#     for i in arr_temp:
#         arr.append(i)
# print(count)