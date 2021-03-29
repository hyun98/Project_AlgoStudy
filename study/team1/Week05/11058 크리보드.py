n = int(input())
_sum = [i for i in range(0,101)]

for i in range(6,101):
    _sum[i] = max(_sum[i - 3] * 2, _sum[i - 4] * 3, _sum[i - 5]*4)
print(_sum[n])
