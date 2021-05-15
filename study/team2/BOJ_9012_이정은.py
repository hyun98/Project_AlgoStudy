n = int(input())

#캔슬조건
#1. 열어놓고 닫지 않은 경우  
#2. 열지 않았는데 닫은 경우
#3. 홀수

def Check(n_list):
    stack = []
    if (len(n_list)%2) != 0 : #괄호 갯수가 홀수면 VPS가 아니다.
        print("NO")
        return
    #쌍이 맞으면 스택에서 빼고
    #마지막에 스택을 검사해서 스택이 비어있으면 YES
    #스택에 무언가 남아있다면 NO 출력
    for i in n_list:
        if i == '(':
            stack.append(i)
        elif i == ')': #닫는 괄호일때 -> 앞에 여는 괄호없으면 올바르지 않은거
            if len(stack) == 0 : #스택에 아무것도 없는데 닫는 괄호만 있다면?
                print("NO")
                return
            else: #앞에 괄호 있을 경우
                stack.pop() #여는 괄호 빼주기
#계속 반복해주고
    if len(stack) == 0:
        print("YES")
        return
    else:
        print("NO")
        return

#한줄에 하나씩 출력해야함으로 def 함수로 입력,출력 동시에 해주기
for i in range(n):
    n_list = list(input())
    Check(n_list) 
