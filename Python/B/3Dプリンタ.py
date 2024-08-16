# 入力を受け取る
X, Y, Z = map(int, input().split())
S = []
for _ in range(Z):
    s = []
    for i in range(X + 1):
        if i != X:
            s.append(input())
        else:
            input()
    S.append(s)

ans = [['.']*Y for _ in range(Z)]
for k in range(Z):
    for j in range(Y):
        # X が大きい順に見ていく
        for i in reversed(range(X)):
            if S[k][i][j] == '#':
                ans[k][j] = '#'

# 答えを出力する
for i in reversed(range(Z)):
    print(*ans[i], sep="")