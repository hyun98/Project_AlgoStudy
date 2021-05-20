#https://blog.naver.com/rlagpwlsq789/222237268429
import sys
input = sys.stdin.readline
n = int(input())
hist=[]

for i in range(n):
    hist.append(int(input()))
hist.append(0)
#큰 데이터 써서 구하자

    
#stack을 통한 스위핑알고리즘 사용

result = 0
stack = [[0, hist[0]]]

for i in range(1,n+1): #stack 에서 1번째 자리 = hist[x]
    x = i


#다음 막대가 큰지 안큰지 확인 
    while stack and stack[-1][1] > hist[i]: 
        # 이전 막대가 그 다음막대보다 큰 경우
        # 다음막대가 더 작을 경우 
        # stack == true
        
        x , h = stack.pop() #그 스택팝해서 x,h에 할당
        #stack의 첫번째 원소는 x, 두 번째 원소는 h로 이동 

        result = max(result, (i - x) * h)
        # 인덱스 번호 - 스택쌓인만큼 번호 * 그다음의 (작은 기둥) 높이
        # 현재 막대 제외하고 넓이 최대비교
         #why? 다음 막대가 


#크기가 계속 높아지면       
    stack.append([x, hist[i]])
    #print(stack)


print(result)
    


