T = int(input())
arr = [1,2,4]
if T >= 4:
    for i in range(4,T+1):
        arr.append(arr[i-2]+arr[i-3]+arr[i-4])
print(arr[T-1])
