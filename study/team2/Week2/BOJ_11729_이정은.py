import sys

n = int(sys.stdin.readline())

board = []

#규칙 
#n이 짝수일때 1->2 선
#n이 홀수일때 1->3 선
#이동횟수는 n^2 - 1

def HanoiT(n ,a,b,c):#a,b,c는 원판번호 
    if n == 1:
        board.append([a,c])
    else:
        HanoiT(n-1,a,c,b) # 1단계 n-1개의 원판을 1 -> 2 
        board.append([a,c]) # 2단계 1번의 한개남은 원판을 1 -> 3
        #print(board)
        HanoiT(n-1,b,a,c) # 3단계 2번에 있던 n-1개의 원판을 2 -> 3
        
HanoiT(n,1,2,3)
print(len(board))
print("\n".join([' '.join(str(i) for i in row) for row in board ]))


 
