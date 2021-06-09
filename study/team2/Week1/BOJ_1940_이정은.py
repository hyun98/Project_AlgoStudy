'''n = int(input())
need = int(input())
n_list = list(map(int,input().split()))

cnt = 0
for i in range(len(n_list)):
    for j in range(i,len(n_list)):
        if n_list[i] + n_list[j] == need:
            cnt+=1

print(cnt)'''

#input
n = int(input())
need =int(input())
n_list = list(map(int,input().split()))
#sort
n_list.sort()
#two pointer
#맨앞, 맨뒤에 포인터를 두고 조건에 맞춰 포인터 이동

left=0
right=n-1
count=0
sumv =0
while left < right : # 왼,오 서로 겹치지 않도록 루프
    sumv = n_list[left] + n_list[right]
    if sumv < need : #요구값보다 작다면 왼쪽 포인터를 옮겨 더 큰 값으로 바꿔주기
        left += 1

    elif sumv > need : #요구값보다 크다면 오른쪽을 옮겨 더 작은 값으로 바꿔주기
        right -= 1

    elif sumv == need:
        right -= 1
        left += 1
        count+=1

print(count)
            
