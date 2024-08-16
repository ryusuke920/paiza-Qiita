from collections import defaultdict

# 入力を受け取る
N, K, M = map(int, input().split())
d = [input() for _ in range(K)]
s = [input() for _ in range(M)]

# word[d[i]] := d[i] を既に使用したかどうか
word = defaultdict(lambda : True)
for i in range(K):
    word[d[i]] = False

# survival[i] := 友達 i が脱落したかどうか
survival = [False]*N

now = 0 # 現在のターンが誰なのか
for i in range(M):
    # 誰のターンなのかを調べる
    for j in range(N):
        # 脱落している場合はスキップする
        if survival[(now + j) % N]:
            continue
        # 脱落していない友達を見つけたら for 文を抜ける
        now = (now + j) % N
        break
    
    check = False # このターンの友達が脱落するかどうか

    # ルール 1. K 個の単語のいずれかでなければならない
    # ルール 3. 既に発言していた場合は発言禁止
    if word[s[i]]:
        check = True

    # ルール 4. z で終わってはいけない
    if s[i][-1] == 'z':
        check = True
    
    # ルール 2. 直前の人の発言の末尾と一致する必要がある
    # 初回のターンは前のプレイヤーがいない
    if i != 0:
        # 前のターンに友達が脱落していればルール 2. は適用されない
        if last != s[i][0] and not last_friend:
            check = True
    
    # 末尾の文字
    last = s[i][-1]

    # s_i を使用済みにする
    word[s[i]] = True

    # このターンに友達が脱落したかどうか（2 ターン目以降のルール 2. で必要）
    if check:
        survival[now] = True
        last_friend = True
    else:
        last_friend = False

    # ターンを進める
    now += 1

# 答えを出力する
print(survival.count(False))

for i in range(N):
    # 脱落している友達は出力しない
    if survival[i]:
        continue
    print(i + 1)