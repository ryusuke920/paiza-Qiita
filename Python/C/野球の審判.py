# 入力を受け取る
N = int(input())
s = [input() for _ in range(N)]

ball = 0 # ボールカウント
strike = 0 # ストライクカウント
for i in range(N):
    # ボール・ストライクカウント判定
    if s[i] == "ball":
        ball += 1
    if s[i] == "strike":
        strike += 1
    
    if ball == 4: # フォアボール
        print("fourball!")
    elif strike == 3: # アウト
        print("out!")
    elif s[i] == "strike": # ストライク
        print("strike!")
    else: # ボール
        print("ball!")