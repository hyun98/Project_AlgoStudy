#BOJ_2630 코드참고
#https://codedrive.tistory.com/396 참고
#import sys


qt = []
n = int(input())
for i in range(n):
    #qt.append(list(map(int, sys.stdin.readline()))) #런타임에러남 
     qt.append(list(map(int, list(input()))))
    
def quadtree(x,y,n):
    color = qt[x][y]
    check = False
    

    for i in range(x , x+n):
        for j in range(y, y+n):
            if qt[i][j] != color:
                check = True
    if check: 
        print("(", end="")
        quadtree(x, y, n//2) #왼쪽위
        quadtree(x ,y + n//2, n//2) #오른쪽위
        quadtree(x+ n//2 , y , n//2) #왼쪽 아래
        quadtree(x + n//2, y+n//2, n//2) #오른쪽 아래
        print(")", end="")        
                
    else:
        print(color, end="")

quadtree(0,0,n)

            
