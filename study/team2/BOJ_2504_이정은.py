n = list(input())
stack = []
result = []
ans=0

for i in n:
    if i == "(":
        stack.append(i)
        result.append("+2(")
    elif i == "[":
        stack.append(i)
        result.append("+3(")
            
    elif i == ")":
        if stack and stack[-1] == "(":
            stack.pop()
            result.append(")")
        else:
            result=[]
            break
        
    elif i == "]":
        if stack and stack[-1] == "[":
            stack.pop()
            result.append(")")

        else:
            result=[]
            break
    else:
        result=[]
        break

if not stack:
    if result:
        result = "".join(result)
        result=result.replace("()", "")
        result=result.replace("(+","*(")
        print(eval(result))
    else:
        print(0)
else:
    print(0)
        
