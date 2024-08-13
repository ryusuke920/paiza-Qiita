# 入力を受け取る
b = int(input())
n = int(input())
a = [int(input()) for _ in range(n)]

for i in range(n):
    if b == a[i]: # １等であるかどうか
        print("first")
    elif (a[i] + 1 == b) or (a[i] - 1 == b): # 前後賞であるかどうか
        print("adjacent")
    elif b % 10000 == a[i] % 10000: # ２等かどうか
        print("second")
    elif b % 1000 == a[i] % 1000: # ３等かどうか
        print("third")
    else: # ハズレ
        print("blank")