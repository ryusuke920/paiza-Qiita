#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<tuple<int, int, int>> edge(M);  // (f, a, b) を保持するタプルのベクトル
    for (int i = 0; i < M; ++i) {
        int a, b, f;
        cin >> a >> b >> f;
        a -= 1;
        b -= 1;
        edge[i] = make_tuple(f, a, b);
    }

    // 友好度が大きい順にソートする
    sort(edge.begin(), edge.end(), [](const tuple<int, int, int>& x, const tuple<int, int, int>& y) {
        return get<0>(x) > get<0>(y);
    });

    vector<bool> group(N, false); // group[i] := 村人 i がグループに存在しているかどうか
    for (int i = 0; i < Q; ++i) {
        char op;
        int q;
        cin >> op >> q;
        q -= 1;

        if (op == '+') {
            group[q] = true;
        } else if (op == '-') {
            group[q] = false;
        }

        bool found = false;
        for (const auto& e : edge) {
            int f, a, b;
            tie(f, a, b) = e;
            // 2 人ともグループに所属 or 2 人とも未所属の場合は調べない
            if (group[a] == group[b]) {
                continue;
            }
            cout << f << endl;
            found = true;
            break;
        }

        if (!found) {
            // グループが 0 人または N 人の場合は人気度が 0
            cout << 0 << endl;
        }
    }

    return 0;
}