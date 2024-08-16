#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> pos(N);

    // 入力を受け取る
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // pos[i] := 本 i が先頭から何番目にあるか
    for (int i = 0; i < N; ++i) {
        pos[a[i] - 1] = i;
    }

    // 先頭から順に調べていく
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        // 既に本が正しい位置にあればスキップ
        if (pos[i] == i) {
            continue;
        }

        // 正しくない本の番号・位置
        int num1 = a[i] - 1;
        int pos1 = pos[num1];

        // 正しい本の番号・位置
        int num2 = i;
        int pos2 = pos[i];

        // 本自体を入れ替える
        swap(a[pos1], a[pos2]);
        // 本の位置を入れ替える
        swap(pos[num1], pos[i]);

        // 本を入れ替える
        ans += 1;
    }

    cout << ans << endl;

    return 0;
}