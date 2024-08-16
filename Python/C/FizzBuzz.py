# 入力を受け取る
N = int(input())

# 1 から N を for 文でループさせる
for i in range(1, N + 1):
    if i % 3 == 0 and i % 5 == 0:
        # 3 でも 5 でも割り切れる場合
        print("Fizz Buzz")
    elif i % 3 == 0:
        # 3 で割り切れる場合
        print("Fizz")
    elif i % 5 == 0:
        # 5 で割り切れる場合
        print("Buzz")
    else:
        # いずれにも該当しない場合は数字を出力する
        print(i)