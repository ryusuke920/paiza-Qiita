# 入力を受け取る
ans = 100

for _ in range(5):
    # 入力を受け取る
    n  = int(input())
    # 現状の最小値よりも n の方が小さければ ans を更新する
    if n < ans:
        ans = n

# 答えを出力する
print(ans)