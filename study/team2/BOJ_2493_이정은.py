n=int(input())
nlist = list(map(int,input().split()))
stack=[]
ans=[]

for i, h in enumerate(nlist,0):
    while True:
        if len(stack) == 0:
            ans.append(0)
            stack.append([h,i])
            break
        else:
            if stack[-1][0] < h:
                stack.pop()
            else:
                ans.append(stack[-1][1] + 1)
                stack.append([h,i])
                break
print(*ans)

