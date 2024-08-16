def dfs(now_y: int, now_x: int):
    # 今いるマスを探索済みにする
    seen[now_y][now_x] = True

    # 上下左右の 4 方向に対する変化量
    d = ((1, 0), (-1, 0), (0, 1), (0, -1))
    for dy, dx in d:
        next_y = now_y + dy
        next_w = now_x + dx
        
        # 配列外参照なら探索を行わない
        if not (0 <= next_y < H and 0 <= next_w < W):
            continue

        # 島でなければ探索を行わない
        if S[next_y][next_w] == 0:
            continue

        # 既に探索済みの島であれば探索を行わない
        if seen[next_y][next_w]:
            continue

        seen[next_y][next_w] = True
        dfs(next_y, next_w)


W, H = map(int, input().split())
S = [list(map(int, input().split())) for _ in range(H)]

# seen[i][j] := マス (i, j) を既に探索したかどうか
seen = [[False]*W for _ in range(H)]
ans = 0 # 島の数
for i in range(H):
    for j in range(W):
        # 島でなければ探索を行わない
        if S[i][j] == 0:
            continue
        # 既に探索済みの島であれば探索を行わない
        if seen[i][j]:
            continue
        dfs(i, j)
        ans += 1

print(ans)