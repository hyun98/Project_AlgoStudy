import sys

a = sys.stdin.readline
n = int(a())
_list,_list2 = [],[]
_sum = [0] * (n + 1)
for i in range(n):
    x,y = map(int,input().split())
    _list.append(x)
    _list2.append(y)
z = 0
for i in range(n):
    z = max(z,_sum[i])
    if i + _list[i] > n:
        continue
    _sum[i + _list[i]] = max(z + _list2[i],_sum[i + _list[i]])
print(max(_sum))
