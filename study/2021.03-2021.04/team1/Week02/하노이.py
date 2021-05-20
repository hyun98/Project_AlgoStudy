def x(a,b,c,d):
    if a == 1:
        print(b,d)
    else:
        x(a-1,b,d,c)
        print(b,d)
        x(a-1,c,b,d)

a = int(input())
print(2**a -1)
x(a, 1 , 2, 3)
