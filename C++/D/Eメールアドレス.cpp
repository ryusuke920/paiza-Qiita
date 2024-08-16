#include <iostream>
#include <string>

using namespace std;

int main() {
    // 入力を受け取る
    string s, t;
    cin >> s >> t;

    // ローカル・@・ドメインの順に繋げる
    string ans = s + "@" + t;

    // 答えを出力する
    cout << ans << endl;

    return 0;
}