# 入力を受け取る
N, M = map(int, input().split())

for _ in range(M):
    w = int(input())
    # w 以下の最大の N の倍数
    d1 = (w // N * N)
    # w より大きい最小の N の倍数
    d2 = d1 + N

    if abs(w - d1) < abs(w - d2) and d1 > 0:
        print(d1)
    else:
        print(d2)