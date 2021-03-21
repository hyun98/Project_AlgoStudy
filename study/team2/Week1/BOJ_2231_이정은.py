N = int(input())
for i in range(1,N+1):
    A=list(map(int,str(i))) #문자 하나씩 저장  
                            #i가 216이 될때까지 돌림  ex) 216 -> ['2','1','6'] 
    nsum = i + sum(A) #216 = 198+1+9+8
    if nsum == N:#분해합이 N과 같을때 
        print(i) #생성자 i 출력
        break

    if i == N: #생성자가 존재하지 않는 경우 0으로 출력 
        print(0)
        
    
