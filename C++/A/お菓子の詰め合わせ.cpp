#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    pair<int, int> ans = {numeric_limits<int>::max(), 0}; // 答えとなる（金額, 個数）

    for (int bit = 0; bit < (1 << N); ++bit) { // 2^N 通りを全探索する
        int money = 0; // 購入したお菓子の金額
        int cnt = 0; // 購入したお菓子の個数
        for (int j = 0; j < N; ++j) { // ビットが立っているかどうかを判定する
            if (bit & (1 << j)) {
                // ビットが立っている時にお菓子を購入する
                money += x[j];
                cnt += 1;
            }
        }

        // お菓子の総額が X を超えている場合はスキップ
        if (money > X) {
            continue;
        }

        if (cnt < ans.second) {
            // 購入したお菓子の個数が現状の答えよりも小さい場合はスキップ
            continue;
        } else if (cnt == ans.second) {
            // 個数が現状の最大値と同じ場合はお釣りを最小化する
            ans.first = min(ans.first, X - money);
        } else {
            // 個数の方が大きい場合は答えを全て更新する
            ans = {X - money, cnt};
        }
    }

    cout << ans.first << endl;

    return 0;
}