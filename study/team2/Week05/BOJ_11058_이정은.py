import sys
n = int(sys.stdin.readline())
dp = [0,1,2,3,4,5,6] + [0]*94

#4번부터는 복사 붙여넣기가 가능하지만 최대 A개수는 하나씩 입력하는 방법
#7번 이상부터는 단순히 추가하는것이 아닌 복붙해주는게 더 많이 출력 가능
#dp[i-3] * 2 이렇게 되면 좋을 듯 

for i in range(6,101):
    dp[i] = max(dp[i-3]*2,max(dp[i-4]*3, dp[i-5]*4))
        #ctrlA, ctrlC는 항상 연속 따라서 두번의 기회 빼줘야한다.

print(dp[n])

