# 入力を受け取る
n, m = map(int, input().split())

# 1 枚のファイルに並べられる名刺の個数
card = 2*n

# 前から何枚目のファイルに探したい名刺があるか
num = (card + m - 1) // card

# 2 枚目以降から何枚あるのか + 1枚目のファイルの合計は card + 1
sum_ = (card*2*(num - 1)) + (card + 1)

# 答えを出力する
print(sum_ - m)