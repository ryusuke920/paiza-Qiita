#include <iostream>
#include <vector>

using namespace std;

// 幅と高さ
int W, H;
vector<vector<int>> S;
vector<vector<bool>> seen;

// 深さ優先探索(DFS)関数
void dfs(int now_y, int now_x) {
    // 今いるマスを探索済みにする
    seen[now_y][now_x] = true;

    // 上下左右の4方向に対する変化量
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; ++i) {
        int dy = d[i][0], dx = d[i][1];
        int next_y = now_y + dy;
        int next_x = now_x + dx;

        // 配列外参照なら探索を行わない
        if (!(0 <= next_y && next_y < H && 0 <= next_x && next_x < W)) {
            continue;
        }

        // 島でなければ探索を行わない
        if (S[next_y][next_x] == 0) {
            continue;
        }

        // 既に探索済みの島であれば探索を行わない
        if (seen[next_y][next_x]) {
            continue;
        }

        // 再帰的に探索を続ける
        dfs(next_y, next_x);
    }
}

int main() {
    cin >> W >> H;
    S.assign(H, vector<int>(W));
    seen.assign(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> S[i][j];
        }
    }

    int ans = 0; // 島の数
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            // 島でなければ探索を行わない
            if (S[i][j] == 0) {
                continue;
            }
            // 既に探索済みの島であれば探索を行わない
            if (seen[i][j]) {
                continue;
            }
            dfs(i, j);
            ans += 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}