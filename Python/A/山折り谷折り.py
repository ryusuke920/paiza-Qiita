for i in range(8, 20):
    N = i

    s = "0"
    for i in range(1, N):
        next_s = ""
        for j in range(2**i):      
            # 0,1,0,1 を順に追加する  
            next_s += str(j % 2)
            # 1 個前の文字列を順番に追加する
            if j != 2**i - 1:
                next_s += s[j]
        s = next_s

    print(s)