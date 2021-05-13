# 뮤탈리스크
from itertools import permutations
from collections import deque

def bfs(count):
    while q:
        size = len(q)
        count += 1
        for _ in range(size):
            x,y,z = q.popleft()
            # 0 두개 일 때
            # 0 한개 일 때
            for a,b,c in sub:
                nx = x + a
                ny = y + b
                nz = z + c
                if nx <= 0:
                    nx = 0
                if ny <= 0:
                    ny = 0
                if nz <= 0:
                    nz = 0
                lst = [nx,ny,nz]
                lst.sort()
                print(lst)
                if lst.count(0) ==3:
                    return count
                if lst not in visited:
                    visited.append(lst)
                    q.append(lst)

N = int(input())
SCV = list(map(int,input().split()))
SCV.sort()
q = deque([SCV])
visited = []
arr = [-9,-3,-1]
sub = permutations(arr)

print(bfs(0))

