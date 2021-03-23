import sys #76ms -> 64ms 
'''
n = int(sys.stdin.readline())
lst = []
for i in range(n):
    lst.append(int(sys.stdin.readline()))

def solve(n):
    dp = [0,1,2,4] + [0]* (n-3)

    for i in range(4,n+1):
        dp[i] = dp[i-3]+dp[i-2]+dp[i-1]

    print(dp[i])


for i in lst:
    solve(i)
''' #런타임 에러

#함수안쓰고 푼거 
n = int(sys.stdin.readline())
result = []
for _ in range(n):
    n = int(sys.stdin.readline()) #n만큼 숫자 입력받기
    dp = [0,1,2,4] + [0]* (n-3)

    if n < 3:
        result.append(n) #n이 1또는 2일때 1, 2 출력 
    else:
        for i in range(4,n+1): #n이 3 이상일때 점화식 계산 결과 출력
            dp[i] = dp[i-3]+dp[i-2]+dp[i-1]
        result.append(dp[n])

for i in result:
    print(i)
