import time
import sys
shape = [[[0, 1], [0, 2], [0, 3]],
         [[1, 0], [2, 0], [3, 0]],
         [[0, 1], [1, 0], [1, 1]],
         [[1, 0], [2, 0], [2, 1]],
         [[1, 0], [2, 0], [2, -1]],
         [[0, 1], [0, 2], [1, 0]],
         [[0, 1], [0, 2], [1, 2]],
         [[0, 1], [1, 1], [2, 1]],
         [[0, 1], [1, 0], [2, 0]],
         [[0, 1], [0, 2], [-1, 2]],
         [[1, 0], [1, 1], [1, 2]],
         [[1, 0], [1, 1], [2, 1]],
         [[1, 0], [1, -1], [2, -1]],
         [[0, 1], [-1, 1], [-1, 2]],
         [[0, 1], [1, 1], [1, 2]],
         [[0, 1], [0, 2], [1, 1]],
         [[1, 0], [1, 1], [2, 0]],
         [[1, 0], [1, -1], [2, 0]],
         [[0, 1], [0, 2], [-1, 1]]]
N,M = map(int, sys.stdin.readline().split()) # readline -> 입력된 값 리스트로 저장
# N,M = map(int,input().split())

arr = [list(map(int,input().split())) for _ in range(N)]
# for i in range(N):
#     check(.append(sys.stdin.readline().split()) # 리스트안의 숫자 : 문자
max_ = 0
for r in range(N):
    for c in range(M):
        for s in shape:
            try:
                sum_ = arr[r][c]
                for i in range(3):
                    sum_ += arr[r+s[i][0]][c+s[i][1]]
                max_ = max(max_, sum_)
            except:
                continue
print(max_)



