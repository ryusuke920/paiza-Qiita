#include <iostream>

using namespace std;

int main() {
    // 初期値を設定する
    int ans = 100;

    for (int i = 0; i < 5; ++i) {
        // 入力を受け取る
        int n;
        cin >> n;
        // 現状の最小値よりも n の方が小さければ ans を更新する
        if (n < ans) {
            ans = n;
        }
    }

    // 答えを出力する
    cout << ans << endl;

    return 0;
}