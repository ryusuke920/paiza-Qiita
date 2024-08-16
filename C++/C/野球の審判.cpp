#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 入力を受け取る
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    int ball = 0; // ボールカウント
    int strike = 0; // ストライクカウント

    for (int i = 0; i < N; i++) {
        // ボール・ストライクカウント判定
        if (s[i] == "ball") {
            ball += 1;
        }
        if (s[i] == "strike") {
            strike += 1;
        }

        if (ball == 4) { // フォアボール
            cout << "fourball!" << endl;
            break; // フォアボールでゲームが終了するのでループを終了
        } else if (strike == 3) { // アウト
            cout << "out!" << endl;
            break; // アウトでゲームが終了するのでループを終了
        } else if (s[i] == "strike") { // ストライク
            cout << "strike!" << endl;
        } else { // ボール
            cout << "ball!" << endl;
        }
    }

    return 0;
}