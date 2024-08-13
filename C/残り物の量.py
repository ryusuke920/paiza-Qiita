# 入力を受け取る
m, p, q = map(int, input().split())

# 売れ残ったお惣菜
ans = m * (100 - p) / 100

# 売れ残った量
ans = ans * (100 - q) / 100

# 答えを出力する
print(ans)