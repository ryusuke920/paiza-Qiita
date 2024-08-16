#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // 辞書型の変数を用意する
    unordered_map<string, int> d;

    for (int i = 0; i < N; ++i) {
        string S;
        int P;
        cin >> S >> P;

        string s = "";
        for (int j = 0; j < min(100, (int)S.length()); ++j) {
            s += S[j];  // 1 文字ずつ増やす
            d[s] += P;  // S の先頭から i 文字目までの部分文字列の価値を +P にする
        }
    }

    for (int i = 0; i < M; ++i) {
        string Q;
        cin >> Q;
        cout << d[Q] << endl;
    }

    return 0;
}