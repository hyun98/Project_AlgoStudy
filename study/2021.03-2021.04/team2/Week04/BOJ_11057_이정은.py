n=int(input())
dp = [0,1,1,1,1,1,1,1,1,1,1]

for i in range(n-1): #0~9
    for j in range(1,11): # 1~ 10 비교 
        dp[j] = dp[j] + dp[j-1]
        
print(sum(dp)%10007)
