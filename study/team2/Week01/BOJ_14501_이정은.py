n = int(input())
T=[0]
P=[0]
d=[0]*(n+2) # 상담기간 Ti , 근무수당  Pi, n+1일에 받는 수익의 최댓값 Di 

result = 0

for i in range(n):
    a,b = map(int, input().split())
    T.append(a)
    P.append(b) 

#https://blog.naver.com/hands731/221975805862 
for i in range(1,n+2): 
    for j in range(1,i):  
        d[i] = max(d[i],d[j])  

        if j+T[j] == i :
            d[i] = max(d[i],d[j]+P[j])

    result = max(result,d[i])
print(result) 
            
