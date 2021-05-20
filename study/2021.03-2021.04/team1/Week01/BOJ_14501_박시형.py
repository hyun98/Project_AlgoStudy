# 14501 퇴사

from random import randint as ri
import time

start = time.time() # 시간 체크

N = ri(1,15) # 근무일
T = [] # 상담시간
P = [] # 수당
money = 0
for i in range(N):
    T.append(ri(1,5)) # 1부터 5 랜덤
    P.append(ri(5,1000)) # 5부터 1000랜덤
print(T)
print(P)
num = P[:] # shallow copy(새로운 id 할당)
num.append(0) # 0을 마지막에 넣어 비교값 생성
print(num)
for j in range(N-1, -1, -1): # 끝에부터 시작
    if T[j]+j > N: # 현재 날짜 + 상담일수가 전체 근무일(N)을 넘으면 이전 최대 값(num) 넣기
        num[j] = num[j+1]
        print(num)
    else:
        money = max(num[j+1], P[j]+num[j+T[j]]) # 이전 최댓값과 현재날짜와 현재날짜부터 지난 날에서의 최댓값을 더한값중 큰 값 저장
        print(money)
        num[j] = money
        print(num)
print(num)
end = time.time()
print(end-start)