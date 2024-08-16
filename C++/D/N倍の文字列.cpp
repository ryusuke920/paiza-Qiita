#include <iostream>
#include <string>

using namespace std;

int main() {
    // 入力を受け取る
    int N;
    cin >> N;

    // ansという変数に*をN個繋げた文字列を格納する
    string ans(N, '*');

    // 答えを出力する
    cout << ans << endl;

    return 0;
}