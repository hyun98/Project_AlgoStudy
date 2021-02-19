def blackjack(N,M):
   card_list = list(map(int, input().split()))
   near_M = 0
   for i in card_list[:N-2]:
      for j in card_list[card_list.index(i)+1:]:
         for k in card_list[card_list.index(j)+1:]:
            if (i+j+k)>near_M and (i+j+k)<=M:
               near_M = i+j+k
   print(near_M)

N, M = map(int, input().split())
blackjack(N,M)