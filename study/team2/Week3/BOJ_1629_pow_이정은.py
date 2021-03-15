
import sys

a,b,c = map(int, sys.stdin.readline().split())

#print(pow(a,b)%c)
#시간초과

print(pow(a,b,c))
