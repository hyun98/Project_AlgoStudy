n,m = map(int,input().split())
l = list(map(int,input().split())) 
sum=0 

for i in range(0,len(l)-2): 
    for j in range(i+1,len(l)-1):
        for k in range(j+1,len(l)): 
            if l[i]+l[j]+l[k] > m : 
                continue
            else:
                sum=max(sum,l[i]+l[j]+l[k]) 
                                            

print(sum)

