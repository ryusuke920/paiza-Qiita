#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 入力を受け取る
    vector<int> n(5);
    for (int i = 0; i < 5; ++i) {
        cin >> n[i];
    }

    // ans に配列 n の最小値を格納する
    int ans = *min_element(n.begin(), n.end());

    // 答えを出力する
    cout << ans << endl;

    return 0;
}