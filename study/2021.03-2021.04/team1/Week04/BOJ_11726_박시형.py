n = int(input())
arr = [0,0,2,3]
if n >= 3:
    for i in range(3,n):
        arr.append(arr[i]+arr[i-1])
print(arr[n]%10007)
# 2 2
# 3 3
# 4 5
# 5 8