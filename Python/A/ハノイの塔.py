def f(n: int, from_: int, to: int, other: int):
    global cnt

    if n == 1:
        # 目的地に出発地の末尾を追加する
        towers[to].append(towers[from_][-1])
        # 出発地の末尾を削除する
        towers[from_].pop()
        cnt += 1

        # t 回試行が終わったら答えを出力する
        if cnt == t:
            for i in towers:
                if len(i) == 0:
                    print('-')
                else:
                    print(" ".join(map(str, i)))
            exit()
    else:
        # n - 1 段の塔を other に移動させる
        f(n - 1, from_, other, to)
        # 一番下の土台を移動させる
        f(1, from_, to, other)
        # other に移動させた 1 つ低い塔を目的地に移動させる
        f(n - 1, other, to, from_)


n, t = map(int, input().split())
cnt = 0 # 試行回数
# 各塔の初期配置
towers = [[n - i for i in range(n)], [], []]
# n 個のブロックを左（0） から右（2）に移動させる
f(n, 0, 2, 1)