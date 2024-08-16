N = int(input())
a = list(map(int, input().split()))

# pos[i] := 本 i が先頭から何番目にあるか
pos = [0]*N

# 本の初期配置を求める
for i in range(N):
    pos[a[i] - 1] = i

# 先頭から順に調べていく
ans = 0

for i in range(N):
    # 既に本が正しい位置にあればスキップ
    if pos[i] == i:
        continue
    
    # 正しくない本の番号・位置
    num1 = a[i] - 1
    pos1 = pos[num1]

    # 正しい本の番号・位置
    num2 = i
    pos2 = pos[i]

    # 本自体を入れ替える
    a[pos1], a[pos2] = a[pos2], a[pos1]
    # 本の位置を入れ替える
    pos[num1], pos[i] = pos[i], pos[num1]

    # 本を入れ替える
    ans += 1

print(ans)