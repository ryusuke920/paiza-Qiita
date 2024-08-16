#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 入力を受け取る
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }

    // is_ok[i] := 座席番号 i に人がいるかどうか
    vector<bool> is_ok(n, false);

    int ans = 0; // 座れる合計人数
    for (int i = 0; i < m; ++i) {
        bool check = true; // i 番目のグループが座れるかどうか
        for (int j = 0; j < a[i]; ++j) {
            // 既に人がいる場合は i 番目のグループは座れない
            if (is_ok[(b[i] + j - 1) % n]) {
                check = false;
                break;
            }
        }

        // 座れる場合
        if (check) {
            // a[i] 人の席を True にする
            for (int j = 0; j < a[i]; ++j) {
                is_ok[(b[i] + j - 1) % n] = true;
            }

            // 答えに a[i] を加える
            ans += a[i];
        }
    }

    // 答えを出力する
    cout << ans << endl;

    return 0;
}