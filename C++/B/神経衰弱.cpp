#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 入力を受け取る
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> t(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> t[i][j];
        }
    }

    int turn = 0; // どのプレイヤーの手番か
    vector<int> point(N, 0); // point[i] := プレイヤー i の点数
    int L;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        int a, b, A, B;
        cin >> a >> b >> A >> B;

        // 0-indexed に変換する
        a--; b--; A--; B--;

        // 同じ数字カードか判別する
        if (t[a][b] != t[A][B]) {
            // 違う場合は手番が次に回る
            turn = (turn + 1) % N;
        } else {
            // 同じ場合は 2 点入る
            point[turn] += 2;
        }
    }

    // 答えを出力する
    for (int i = 0; i < N; ++i) {
        cout << point[i] << endl;
    }

    return 0;
}