# n % 3 == 0
# n % 2 == 0
# n - 1

#3가지 방법으로 최소가 되는 카운트 구하기

#재귀
n = int(input())
minv = 1e9


def solve(n,d):
    global minv
    
    if n == 1:
        minv = min(minv,d)

    else:
        if d < minv:
            if n % 3 == 0:
                solve(n//3, d+1)
            if n % 2 == 0:
                solve(n//2, d+1)
            solve(n-1, d+1)
            

solve(n,0)
print(minv)

'''
#DP? 틀렸다고 함 ㅠㅠ 
n = int(input())
dp = [0] * (n+1)

for i in range(2,n+1):
    if i % 3 == 0 : # 공배수는 최소비교
        dp[i] = min(dp[i-1] + 1, dp[i//3] + 1 ) 
    elif i % 2 == 0 :
        dp[i] = min(dp[i-1] + 1 , dp[i//2] + 1 )
    else:
        dp[i] = dp[i-1] + 1


print(dp[n])
'''  
