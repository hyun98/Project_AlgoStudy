'''모든 시작점에서 갈 수 있는 모든 나라들을 거쳐 다시 시작점으로
돌아올 수 있는지 모든 경우의수를 다 해 보고 답을 도출해내는 브루트포스 문제'''

#완전 탐색 이용
# 백트래킹 (해를 얻을때까지 노드탐색)
#https://blog.naver.com/sjy263942/222025816429
''' 모든 순열을 구하는 것 '''

import sys

N = int(sys.stdin.readline())
city = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
minv = int(1e9)
visited = [False]*N #방문했는지 여부 판단
result = 0


def dfs(s_node , row):
    global minv , result

    if minv < result : # N <= 10 
        return

    if s_node == row and False not in visited :# 순회 다했고 다 방문했으면 
        minv = min(result,minv) #최소값 저장 

    for j in range(N):# i 행 j 열 -> end_node
        
        if visited[j] == False and city[s_node][j] != 0:
            #0도 아니고 아직 방문안했을때  
            visited[j] = True #방문 표시
            result += city[s_node][j] #그 좌표 값 (비용)  더해줌 

            dfs(j,row) # N만큼 순회할것 
            print(row,",",i,j) # Ex ) N= 4일 경우 row = 0 ~ 3  
            visited[j] = False
            result -= city[s_node][j]
            
    
for i in range(N):
    dfs(i,i)

print(minv)

    
