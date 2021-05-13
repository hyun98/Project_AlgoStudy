import sys
#https://blog.naver.com/songchoon10/222208903503 문제접근방법 참고 
n = int(sys.stdin.readline()) # 96ms 에서 88ms로 단축
dp = [0,1,2] + [0] *(n-2)

# 규칙 >  dp[n] = dp[n-2] + dp[n-1]

for i in range(3,n+1):
    dp[i] = dp[i-2] + dp[i-1]

print(dp[n]%10007)
    
