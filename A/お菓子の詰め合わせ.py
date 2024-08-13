N, X = map(int, input().split())
x = [int(input()) for _ in range(N)]

ans = [10**10, 0] # 答えとなる（金額, 個数）
for bit in range(1 << N): # 2^N 通りを全探索する
    money = 0 # 購入したお菓子の金額
    cnt = 0 # 購入したお菓子の個数
    for j in range(N): # ビットが立っているかどうかを判定する
        if (bit >> j) & 1:
            # ビットが立っている時にお菓子を購入する
            money += x[j]
            cnt += 1

    # お菓子の総額が X を超えている場合はスキップ
    if money > X:
        continue
    
    if cnt < ans[1]:
        # 購入したお菓子の個数が現状の答えよりも小さい場合はスキップ
        continue 
    elif cnt == ans[1]:
        # 個数が現状の最大値と同じ場合はお釣りを最小化する
        ans[0] = min(ans[0], X - money)
    else:
        # 個数の方が大きい場合は答えを全て更新する
        ans = [X - money, cnt]

print(ans[0])