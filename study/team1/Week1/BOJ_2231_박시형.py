#2231 분해합

N = int(input("1~999 : "))
for i in range(N-27,N): # 999가 최댓값이므로 각자리수의 합인 27을 뺀 수부터 시작
    sum_N = i
    num = str(i) # 문자열로 변환
    for j in num: # 문자열에서 각자리수를 하나씩 뺀다
        sum_N += int(j) # 분해합 구하기
        if sum_N == N:
            print(i)
            exit() # 프로그램 종료
            # break
    # if sum_N == N:
    #     break # 이중반복문 빠져나오기
