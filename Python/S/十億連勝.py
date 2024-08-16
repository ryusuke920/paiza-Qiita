from collections import defaultdict

N, X = map(int, input().split())
A = [int(input()) for _ in range(N)]

dp = defaultdict(tuple)
dp[(0, False)] = 1 # 連勝数, X 連勝したかどうか
for i in range(N):
    new_dp = defaultdict(int)
    for k, v in dp.items():
        win, bool_ = k # 連勝数, X 連勝したかどうか
        if win + A[i] <= X:
            # A[i] 試合全てに勝つ場合
            new_dp[(win + A[i], bool_)] += v
            # A[i] 試合のいずれかで負ける場合
            new_dp[(0, bool_)] += v*A[i]
        elif win + A[i] > X:
            # X 連勝ちょうどで負ける場合
            new_dp[(0, True)] += v

            # X 連勝未満で負ける場合
            new_dp[(0, bool_)] += v*(X - win)
    
    dp = new_dp

ans = 0
modp = 10**9
for k, v in dp.items():
    win, bool_ = k # 連勝数, X 連勝したかどうか
    if bool_ or win == X:
        ans += v
        ans %= modp

print(ans)