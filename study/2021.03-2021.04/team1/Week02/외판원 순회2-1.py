import sys

def x(start,_next,_sum,visit):
    global _min

    if len(visit) == n:
        if travel[_next][start] !=0:
            _min = min(_min, _sum + travel[_next][start])
        return

    for i in range(n):
        if travel[_next][i] !=0 and i !=start and i not in visit:
            visit.append(i)
            x(start, i, _sum + travel[_next][i],visit)
            visit.pop()



n  = int(input())
travel = [list(map(int, input().split())) for _ in range(n)]

_min = sys.maxsize

for i in range(n):
    x(i,i,0,[i])
    
print(_min)
