import sys


N,M = map(int,sys.stdin.readline().split()) # 가로 세로 입력
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
max_result = 0


#https://blog.naver.com/lizziechung/221846239573
#DFS를 응용한 문제로 테트로미노 모양을 방향 값으로 모두 저장한 후 탐색
#[출처] [Algorithm/Python] 백준 14500번 테트로미노|작성자 IT쩡뉴

#방향 값으로 저장한 테트로미노 
shapes = [
    [[(0, 1), (0, 1), (0, 1)], [(1, 0), (1, 0), (1, 0)]], # 긴 막대 모양 ,tetros 2개 

    [[(0, 1), (1, 0), (0, -1)]], # 정사각 모양 #tetros 1개 

    [[(1, 0), (0, 1), (1, 0)], [(1, 0), (0, -1), (1, 0)], [(0, 1), (1, 0), (0, 1)], [(0, -1), (1, 0), (0, -1)]], # 계단모양
    #tetros 4개
    [[(0, 1), (0, 1), (-1, -1)], [(1, 0), (0, 1), (1, -1)], [(1, 0), (0, -1), (1, 1)], [(0, 1), (1, 0), (-1, 1)]], # ㅗ 모양
    #tetros 4개 
    [[(1, 0), (1, 0), (0, 1)], [(1, 0), (1, 0), (0, -1)], [(0, 1), (1, 0), (1, 0)], [(0, -1), (1, 0), (1, 0)],
     [(0, 1), (0, 1), (-1, 0)], [(0, 1), (0, 1), (1, 0)], [(-1, 0), (0, 1), (0, 1)], [(1, 0), (0, 1), (0, 1)]] # ㄴ모양
    #tetros 8개
    #총 19개의 경우
]

#board를 넘지 않는지 여부 판단

def Is_Board(i,j):
    return 0 <= i < N and 0 <= j < M #세로 0이상 N이하 가로 0이상 M이하 


#깊이우선탐색 
def DFS(i,j):
    global max_result

    si, sj = i, j

    for tetros in shapes:
        for tetro in tetros: #shape안에 저장된 테트로를 불러옴
            result = board[si][sj] #초깃값
            
            for di, dj in tetro: # 각 테트로의 [i][j]값 불러옴 
                si += di
                sj += dj #대입 
                if not Is_Board(si,sj):
                    break #필드 내에 없으면 break
                result+= board[si][sj] #해당 값을 합계에 저장
                max_result = max(result, max_result)
                #최대값인지 비교후 최대값 저장 
            si, sj = i , j #[i,j초기화]

#solve

for i in range(N):
    for j in range(M):
        DFS(i,j)


print(max_result)

    
