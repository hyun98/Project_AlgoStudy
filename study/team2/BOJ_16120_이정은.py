lst = list(map(str,input()))
stack=[]

for i in lst:
    stack.append(i)
    while True:
        if len(stack)>=4:
            if stack[-1] =="P" and stack[-2]=="A" and stack[-3]=="P" and stack[-4] =="P":
                for i in range(4):
                    stack.pop()
                stack.append("P")    
            else:
                break
        else:
            break


if len(stack) == 1 and stack[0] == "P":
    print("PPAP")
else:
    print("NP")
