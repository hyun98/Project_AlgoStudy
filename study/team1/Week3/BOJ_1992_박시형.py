def ZIP(x,y,N):
    num = arr[x][y]
    for i in range(x,x+N):
        for j in range(y,y+N):
            if arr[i][j] != num:
                print("(", end="")
                ZIP(x,y,N//2)
                ZIP(x,y+N//2,N//2)
                ZIP(x+N//2,y,N//2)
                ZIP(x+N//2,y+N//2,N//2)
                print(")",end="")
                return
    if num == 0:
        print(0, end="")
    else:
        print(1, end="")

N = int(input())
arr = []
for _ in range(N):
    temp = input()
    tmp_lst = []
    for i in range(N):
        tmp_lst.append(int(temp[i]))
    arr.append(tmp_lst)

# print(arr)
ZIP(0,0,N)
