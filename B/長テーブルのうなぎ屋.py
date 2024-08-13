# 入力を受け取る
n, m = map(int, input().split())
a, b = [0]*n, [0]*n
for i in range(m):
    a[i], b[i] = map(int, input().split())

# is_ok[i] := 座席番号 i に人がいるかどうか
is_ok = [False]*n

ans = 0 # 座れる合計人数
for i in range(m):
    check = True # i 番目のグループが座れるかどうか
    for j in range(a[i]):
        # 既に人がいる場合は i 番目のグループは座れない
        if is_ok[(b[i] + j - 1) % n]:
            check = False
    
    # 座れる場合
    if check:
        # a[i] 人の席を True にする
        for j in range(a[i]):
            is_ok[(b[i] + j - 1) % n] = True

        # 答えに a[i] を加える
        ans += a[i]

# 答えを出力する
print(ans)