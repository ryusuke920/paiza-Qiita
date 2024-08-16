#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<int> cnt(7, 0);
    // a[i] を 7 で割った余りに置き換え、それぞれの個数を数える
    for (int i = 0; i < N; ++i) {
        cnt[a[i] % 7]++;
    }

    vector<tuple<int, int, int>> mod7;
    // (i + j + k) が 7 の倍数となるような組み合わせを全列挙する （i ≤ j ≤ k）
    for (int i = 0; i < 7; ++i) {
        for (int j = i; j < 7; ++j) {
            for (int k = j; k < 7; ++k) {
                if ((i + j + k) % 7 == 0) {
                    mod7.push_back(make_tuple(i, j, k));
                }
            }
        }
    }

    long long ans = 0;
    for (auto &tuple : mod7) {
        int i = get<0>(tuple);
        int j = get<1>(tuple);
        int k = get<2>(tuple);

        if (i == j && j == k) { // cnt[i]_C_3
            ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        } else if (i == j) { // cnt[i]_C_2 * cnt[k]
            ans += (cnt[i] * (cnt[i] - 1) / 2) * cnt[k];
        } else if (i == k) { // cnt[i]_C_2 * cnt[j]
            ans += (cnt[i] * (cnt[i] - 1) / 2) * cnt[j];
        } else if (j == k) { // cnt[j]_C_2 * cnt[i]
            ans += (cnt[j] * (cnt[j] - 1) / 2) * cnt[i];
        } else { // cnt[i] * cnt[j] * cnt[k]
            ans += cnt[i] * cnt[j] * cnt[k];
        }
    }

    cout << ans << endl;

    return 0;
}