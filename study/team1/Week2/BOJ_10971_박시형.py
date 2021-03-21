from itertools import permutations
# import time

N = int(input())
W= []
for i in range(N): # 비용 넣기
    W.append(list(map(int,input().split())))
# print(W)
# start = time.time()

N_arr = [str(i) for i in range(1,N)] # 0 ~ N-1 까지
rep = permutations(N_arr,N-1) # 제일 첫 번째를 제외한 다른 것들 순열

cost = 10000
for city in rep:
    tmp = 0
    # print(city)
    j = 0
    while j <= len(city): # N번 반복해야함
        if j == 0:
            tmp += W[0][int(city[j])] # 첫번째는 1번 도시에서 시작
            # print(tmp)
            j += 1
        elif j == len(city):
            tmp += W[int(city[j-1])][0] # 마지막에 1번 도시로 돌아가기
            # print(tmp)
            j += 1
        else:
            tmp += W[int(city[j-1])][int(city[j])]
            # print(tmp)
            j += 1
    cost = min(cost, tmp)
    # print(cost)
print(cost)
# end = time.time()
# print(end-start)
