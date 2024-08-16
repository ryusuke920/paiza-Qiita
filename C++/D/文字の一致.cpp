#include <iostream>
#include <string>

using namespace std;

int main() {
    // 入力を受け取る
    string a, b;
    cin >> a >> b;

    // a と b が同じかどうかを判定する
    if (a == b) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }

    return 0;
}