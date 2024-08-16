#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 入力を受け取る
    int b, n;
    cin >> b >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (b == a[i]) { // １等であるかどうか
            cout << "first" << endl;
        } else if ((a[i] + 1 == b) || (a[i] - 1 == b)) { // 前後賞であるかどうか
            cout << "adjacent" << endl;
        } else if (b % 10000 == a[i] % 10000) { // ２等かどうか
            cout << "second" << endl;
        } else if (b % 1000 == a[i] % 1000) { // ３等かどうか
            cout << "third" << endl;
        } else { // ハズレ
            cout << "blank" << endl;
        }
    }

    return 0;
}