#include <iostream>
#include <vector>

using namespace std;

int cnt = 0; // 試行回数
int t; // 目標の試行回数
vector<vector<int>> towers; // 各塔の状態

void f(int n, int from_, int to, int other) {
    if (n == 1) {
        // 目的地に出発地の末尾を追加する
        towers[to].push_back(towers[from_].back());
        // 出発地の末尾を削除する
        towers[from_].pop_back();
        cnt += 1;

        // t 回試行が終わったら答えを出力する
        if (cnt == t) {
            for (const auto& tower : towers) {
                if (tower.empty()) {
                    cout << '-' << endl;
                } else {
                    for (size_t i = 0; i < tower.size(); ++i) {
                        if (i > 0) cout << " ";
                        cout << tower[i];
                    }
                    cout << endl;
                }
            }
            exit(0);
        }
    } else {
        // n - 1 段の塔を other に移動させる
        f(n - 1, from_, other, to);
        // 一番下の土台を移動させる
        f(1, from_, to, other);
        // other に移動させた 1 つ低い塔を目的地に移動させる
        f(n - 1, other, to, from_);
    }
}

int main() {
    int n;
    cin >> n >> t;

    // 各塔の初期配置
    towers = {{}, {}, {}};
    for (int i = n; i > 0; --i) {
        towers[0].push_back(i);
    }

    // n 個のブロックを左（0） から右（2）に移動させる
    f(n, 0, 2, 1);

    return 0;
}