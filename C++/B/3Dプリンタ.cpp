#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 入力を受け取る
    int X, Y, Z;
    cin >> X >> Y >> Z;
    vector<vector<string>> S(Z, vector<string>(X));

    // データを入力する
    for (int k = 0; k < Z; ++k) {
        for (int i = 0; i < X + 1; ++i) {
            string line;
            cin >> line;
            if (i != X) {
                S[k][i] = line;
            }
        }
    }

    // 初期化
    vector<vector<char>> ans(Z, vector<char>(Y, '.'));

    // 判定と更新
    for (int k = 0; k < Z; ++k) {
        for (int j = 0; j < Y; ++j) {
            for (int i = X - 1; i >= 0; --i) {
                if (S[k][i][j] == '#') {
                    ans[k][j] = '#';
                    break;
                }
            }
        }
    }

    // 答えを出力する
    for (int i = Z - 1; i >= 0; --i) {
        for (int j = 0; j < Y; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}