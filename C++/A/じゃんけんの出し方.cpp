#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;

    // dp[i][j] := i 番目までで指の合計が j 本の時の勝つ回数の最大値
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1));
    dp[0][0] = 0;

    // 勝つための手を表現するマップ
    char win_map[256];
    win_map['G'] = 'P';
    win_map['C'] = 'G';
    win_map['P'] = 'C';

    // 各手の指の本数
    int point_map[256];
    point_map['G'] = 0;
    point_map['C'] = 2;
    point_map['P'] = 5;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            for (char k : {'G', 'C', 'P'}) { // 出す手を全探索
                if (k != win_map[s[i]]) { // 負ける手を出した場合の処理
                    if (j - point_map[k] >= 0) {
                        // 遷移元の組み合わせがあり得ない場合はスキップ
                        if (dp[i][j - point_map[k]] == -1) continue;
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - point_map[k]]);
                    }
                } else { // 勝つ手を出した場合の処理
                    if (j - point_map[win_map[s[i]]] >= 0) {
                        // 遷移元の組み合わせがあり得ない場合はスキップ
                        if (dp[i][j - point_map[win_map[s[i]]]] == -1) continue;
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - point_map[win_map[s[i]]]] + 1);
                    }
                }
            }
        }
    }

    // 答えを出力する
    cout << dp[N][M] << endl;

    return 0;
}