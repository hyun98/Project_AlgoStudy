#하노이의 탑
# h1 : 출발
# h2 : 보조
# h3 : 도착
def move(n,h1,h2,h3):
    if n == 1:
        print(h1,"->", h3)
        return
    else:
        move(n-1,h1,h3,h2)
        print(h1,"->",h3) # 큰 원판 옮기기
        move(n-1,h2,h1,h3)

N = int(input("1~20"))

count = 0
for i in range(N):
    count = 2*count + 1
print(count)
move(N,1,2,3)
