#include <iostream>

using namespace std;

int main() {
    // 入力を受け取る
    int n, m;
    cin >> n >> m;

    // 1 枚のファイルに並べられる名刺の個数
    int card = 2 * n;

    // 前から何枚目のファイルに探したい名刺があるか
    int num = (card + m - 1) / card;

    // 2 枚目以降から何枚あるのか + 1枚目のファイルの合計は card + 1
    int sum_ = (card * 2 * (num - 1)) + (card + 1);

    // 答えを出力する
    cout << sum_ - m << endl;

    return 0;
}