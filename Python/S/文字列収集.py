from collections import defaultdict

N, M = map(int, input().split())

# 辞書型の変数を用意する
d = defaultdict(int)
for _  in range(N):
    S, P = input().split()
    P = int(P)

    s = ""
    for i in range(min(100, len(S))):
        s += S[i] # 1 文字ずつ増やす
        d[s] += P # S の先頭から i 文字目までの部分文字列の価値を +P にする

for _ in range(M):
    Q = input()
    print(d[Q])