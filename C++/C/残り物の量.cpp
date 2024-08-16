#include <iostream>

using namespace std;

int main() {
    // 入力を受け取る
    int m, p, q;
    cin >> m >> p >> q;

    // 売れ残ったお惣菜
    double ans = m * (100 - p) / 100.0;

    // 売れ残った量
    ans = ans * (100 - q) / 100.0;

    // 答えを出力する
    cout << ans << endl;

    return 0;
}