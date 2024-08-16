#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    string s = "0";
    for (int i = 1; i < N; ++i) {
        string next_s = "";
        for (int j = 0; j < (1 << i); ++j) {  // 2^i を (1 << i) に変換
            // 0,1,0,1 を順に追加する
            next_s += to_string(j % 2);
            // 1 個前の文字列を順番に追加する
            if (j != (1 << i) - 1) {
                next_s += s[j];
            }
        }
        s = next_s;
    }

    cout << s << endl;

    return 0;
}