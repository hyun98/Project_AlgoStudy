'''
https://www.youtube.com/watch?v=eu9ttD-psU4
&list=PLDV-cCQnUlIYQOb8_n-d-VPhl_X6cECjg&index=1
'''

n = list(input())
stack=[]

for i in range(len(n)):
    if n[i] == ")": #닫는 괄호를 만났을 때 
        sumv = 0
        while stack:
            top = stack.pop() # 맨 위의 괄호와 비교
            if top == "(": #여는 괄호일 경우
                if sumv == 0:
                    stack.append(2) #2를 넣어준다 ()=2 
                else:
                    stack.append(2*sumv)
                break
            elif top == "[":
                print(0)
                exit(0)
            else:
                if sumv == 0 :
                    sumv = int(top)
                else:
                    sumv = sumv + int(top)
                    
    elif n[i] == "]": #다른 닫는 괄호를 만났을 경우
        sumv=0
        while stack:
            top = stack.pop()
            if top == "[":
                if sumv == 0 :
                    stack.append(3)
                else:
                    stack.append(3*sumv)
                break
            elif top == "(": #짝이 안맞는 경우
                print(0)
                exit(0)
            else:
                if sumv == 0 :
                    sumv = int(top)
                else:
                    sumv = sumv + int(top)
    else:
        stack.append(n[i])

result = 0
for i in stack:
    if i == "(" or i == "[":
        print(0)
        exit(0)
    else:
        result += i


print(result)
                    
