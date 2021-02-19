# 2798 블랙잭
from itertools import combinations as cb
from random import randint as ri

N = int(input("카드의 개수 : "))
M = ri(3,100000) # 랜덤 수
print(M)
cardnum = [] # 카드의 값

# 카드의 값이 중복되지 않게 하려면 ? -> while사용

for i in range(N):
    if i not in cardnum:
        cardnum.append(ri(3,100000)) # N개의 카드 생성
print(cardnum)

close = 0 # 가장 가까운 값 저장하는 변수
sum_ = 0 # 카드 더한 값 저장하는 변수

# 카드가 중복되지 않게 뽑을 경우

card3 = cb(cardnum,3) # 라이브러리 사용
for card in card3:
    sum_ = sum(card)
    if M - sum_ >= 0 and sum_ > close:
        close = sum_
print(close)

# for t, i in enumerate(cardnum[0:-2]):
#     for z, j in enumerate(cardnum[t + 1:-1]):
#         for k in cardnum[t+z+2:]:
#             # print(i,j,k)
#             sum_ = i+j+k
#             if M - sum_ >= 0 and sum_ > close:
#                 close = sum_
#                 # print(close)
# print(close)



