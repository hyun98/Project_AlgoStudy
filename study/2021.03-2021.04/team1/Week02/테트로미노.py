n,m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
tetromino = [
    [[0,0], [0,1], [1,0], [1,1]], # ㅁ
    [[0,0], [0,1], [0,2], [0,3]], # ㅡ
    [[0,0], [1,0], [2,0], [3,0]], # ㅣ
    [[0,0], [0,1], [0,2], [1,0]], 
    [[1,0], [1,1], [1,2], [0,2]],
    [[0,0], [1,0], [1,1], [1,2]], # ㄴ
    [[0,0], [0,1], [0,2], [1,2]], # ㄱ
    [[0,0], [1,0], [2,0], [2,1]],
    [[2,0], [2,1], [1,1], [0,1]],
    [[0,0], [0,1], [1,0], [2,0]], 
    [[0,0], [0,1], [1,1], [2,1]],
    [[0,0], [0,1], [0,2], [1,1]], # ㅜ
    [[1,0], [1,1], [1,2], [0,1]], # ㅗ
    [[0,0], [1,0], [2,0], [1,1]], # ㅏ
    [[1,0], [0,1], [1,1], [2,1]], # ㅓ
    [[1,0], [2,0], [0,1], [1,1]],
    [[0,0], [1,0], [1,1], [2,1]],
    [[1,0], [0,1], [1,1], [0,2]],
    [[0,0], [0,1], [1,1], [1,2]]
]
max_sum = 0
for i in range(n):
    for j in range(m):
        for a in tetromino:
            _sum = 0
            for b in a:
                xx,yy = i + b[0], j + b[1]
                if 0<= xx <n and 0<= yy < m:
                    _sum += board[xx][yy]
                else:
                    break
            max_sum = max(max_sum,_sum)
print(max_sum)
