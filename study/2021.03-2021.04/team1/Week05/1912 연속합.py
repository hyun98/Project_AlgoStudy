n = int(input())
a = list(map(int, input().split()))
_sum = [a[0]]

for i in range(len(a) - 1):
    _sum.append(max(_sum[i] + a[i + 1], a[i + 1]))
print(max(_sum))
