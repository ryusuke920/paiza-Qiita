# 入力を受け取る
H, W, N = map(int, input().split())
t = [list(map(int, input().split())) for _ in range(H)]

turn = 0 # どのプレイヤーの手番か
# point[i] := プレイヤー i の点数
point = [0]*N
L = int(input())
for _ in range(L):
    # 入力を受け取り、同時に 0-indexed に変換する
    a, b, A, B = map(lambda x: int(x) - 1, input().split())

    # 同じ数字カードか判別する
    if t[a][b] != t[A][B]:
        # 違う場合は手番が次に回る
        turn += 1
        turn %= N
    else:
        # 同じ場合は 2 点入る
        point[turn] += 2

# 答えを出力する
for i in range(N):
    print(point[i])