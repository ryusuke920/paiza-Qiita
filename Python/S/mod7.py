N = int(input())
a = [int(input()) for _ in range(N)]

cnt = [0]*7
# a[i] を 7 で割った余りに置き換えそれぞれの個数を数える
for i in range(N):
    cnt[a[i] % 7] += 1

mod7 = []
# (i + j + k) が 7 の倍数となるような組み合わせを全列挙する （i ≤ j ≤ k）
for i in range(7):
    for j in range(i, 7):
        for k in range(j, 7):
            if (i + j + k) % 7 == 0:
                mod7.append((i, j, k))

print(mod7)
ans = 0
for i, j, k in mod7:
    if i == j == k: # cnt[i]_C_3
        ans += cnt[i]*(cnt[i] - 1)*(cnt[i] - 2) // 6
    elif i == j: # cnt[i]_C_2 * cnt[k]
        ans += (cnt[i]*(cnt[i] - 1) // 2) * (cnt[k])
    elif i == k: # cnt[j]_C_2 * cnt[j]
        ans += (cnt[j]*(cnt[j] - 1) // 2) * (cnt[j])
    elif j == k: # cnt[k]_C_2 * cnt[i]
        ans += (cnt[k]*(cnt[k] - 1) // 2) * (cnt[i])
    else: # cnt[i] * cnt[j] * cnt[k]
        ans += cnt[i]*cnt[j]*cnt[k]

print(ans)