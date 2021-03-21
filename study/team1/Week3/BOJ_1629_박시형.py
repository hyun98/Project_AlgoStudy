def Square(A,B):
    if B == 1:
        return A
    if B % 2 == 0:
        B = B//2
        A = (Square(A,B))**2
        return A
    else:
        B = B//2
        A = (Square(A,B)**2)*A
        return A
A,B,C = map(int, input().split())
print(Square(A,B)%C)


