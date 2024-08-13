N, M, Q = map(int, input().split())

edge = []
for _ in range(M):
    a, b, f = map(int, input().split())
    a -= 1
    b -= 1
    edge.append((f, a, b))

# 友好度が大きい順にソートする
edge.sort(key=lambda x: x[0], reverse=True)

group = [False]*N # group[i] := 村人 i がグループに存在しているかどうか
for _ in range(Q):
    op, q = input().split()
    q = int(q) - 1
    
    if op == "+":
        group[q] = True
    elif op == "-":
        group[q] = False
    
    for f, a, b in edge:
        # 2 人ともグループに所属 or 2 人とも未所属の場合は調べない
        if group[a] == group[b]:
            continue
        print(f)
        break
    else: # グループが 0 人または N 人の場合は人気度が 0
        print(0)