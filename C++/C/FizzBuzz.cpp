#include <iostream>

using namespace std;

int main() {
    // 入力を受け取る
    int N;
    cin >> N;

    // 1 から N を for 文でループさせる
    for (int i = 1; i <= N; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            // 3 でも 5 でも割り切れる場合
            cout << "Fizz Buzz" << endl;
        } else if (i % 3 == 0) {
            // 3 で割り切れる場合
            cout << "Fizz" << endl;
        } else if (i % 5 == 0) {
            // 5 で割り切れる場合
            cout << "Buzz" << endl;
        } else {
            // いずれにも該当しない場合は数字を出力する
            cout << i << endl;
        }
    }

    return 0;
}