import sys

def cut(x,y,N):
    global blue
    global white
    num = arr[x][y]
    for i in range(x,x+N):
        for j in range(y,y+N):
            if arr[i][j] != num:
                cut(x,y,N//2)
                cut(x,y+N//2,N//2)
                cut(x+N//2,y,N//2)
                cut(x+N//2,y+N//2, N//2)
                return
    if num == 0:
        white += 1
        return
    else:
        blue += 1
        return

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int,sys.stdin.readline().split())))
# 1     0
blue, white = 0, 0
cut(0,0 ,N)

print(white)
print(blue)
