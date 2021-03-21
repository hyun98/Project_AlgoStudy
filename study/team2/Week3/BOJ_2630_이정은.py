import sys

#https://blog.naver.com/wnstn0154/221795074432
#쿼드트리라는 개별 내부 노드가 네 개의 자식 노드를 갖는 나무 형태 데이터구조

def cut(i,j,n):
    global graph, cntB, cntW

    double_check = True #탈출 조건 설정
    color = graph[i][j] #첫번째 색 지정해서 그 다음 숫자들과 색이 같은지 판별 


    for x in range(i, i+n):
        if not double_check:
            break
        
        for y in range(j, j+n):
            if color != graph[x][y]:
                double_check= False
                
                #색이 같지 않다면 같아질때까지 쪼갬

                cut(i + n//2 , j + n//2, n//2) #1사분면
                cut(i  , j + n//2, n//2) #2사분면
                cut(i , j , n//2) #3사분면
                cut(i + n//2 , j , n//2) #4사분면
                
                break
            
    if double_check:
        if graph[x][y] == 1:
            cntB += 1
            return
        else:
            cntW += 1
            return


graph = []
cntB = 0
cntW = 0

n = int(sys.stdin.readline())
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))


cut(0,0,n)
print(cntW)
print(cntB)
