N, M = map(int, input().split())
s = input()

# dp[i][j] := i 番目までで指の合計が j 本の時の勝つ回数の最大値
dp = [[-1]*(M + 1) for _ in range(N + 1)]
dp[0][0] = 0

win = {'G': 'P', 'C': 'G', 'P': 'C'}
point = {'G': 0, 'C': 2, 'P': 5}
for i in range(N):
    for j in range(M + 1):
        for k in "GCP": # 出す手を全探索
            if k != win[s[i]]: # 負ける手を出した場合の処理
                if j - point[k] >= 0:
                    # 遷移元の組み合わせがあり得ない場合はスキップ
                    if dp[i][j - point[k]] == -1:
                        continue
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - point[k]])
            else: # 勝つ手を出した場合の処理
                if j - point[win[s[i]]] >= 0:
                    # 遷移元の組み合わせがあり得ない場合はスキップ
                    if dp[i][j - point[win[s[i]]]] == -1:
                        continue
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - point[win[s[i]]]] + 1)

# 答えを出力する
print(dp[N][M])