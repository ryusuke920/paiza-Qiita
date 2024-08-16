#include <iostream>

using namespace std;

int main() {
    // 入力を受け取る
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int w;
        cin >> w;

        // w 以下の最大の N の倍数
        int d1 = (w / N) * N;

        // w より大きい最小の N の倍数
        int d2 = d1 + N;

        if (abs(w - d1) < abs(w - d2) && d1 > 0) {
            cout << d1 << endl;
        } else {
            cout << d2 << endl;
        }
    }

    return 0;
}