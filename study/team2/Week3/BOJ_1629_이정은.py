
import sys
sub = 0
a,b,c = map(int, sys.stdin.readline().split())
#분할정복을 이용해서 거듭제곱
def pow_(a, b, c):  
    if b == 0:
        return 1
    elif b == 1:
        return a%c
 
    elif b%2 == 0: #b가 짝수인경우
        return pow_(a, b//2, c) **2 %c #지수를 반토막내서 나머지 구하기

    else:
        return (pow_(a, b-1, c) * a) % c

print(pow_(a,b,c))

#런타임 에러
#https://blog.naver.com/webserver3315/222011459507
#https://blog.naver.com/jjys9047/222229194698
# a=Qc+r​ 공식 숙지
# a2=Q2c2+2Qcr+r2​
