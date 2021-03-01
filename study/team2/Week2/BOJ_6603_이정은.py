'''첫번째 수 K /  K개의 수
    두 번째 수 L / L개의 수 '''
import sys
from itertools import combinations


while True:
    K_list= list(map(int,sys.stdin.readline().split()))
    Zero = int(K_list[0])
    if Zero == 0:
        break

     # 입력받은 K (k>6)개 중 6개를 뽑는 경우의 수 출력

    for case in combinations(K_list[1:],6):
        print(' '.join(map(str, case)))
    print('') # 빈줄 
    
