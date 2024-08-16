#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    
    vector<string> d(K);
    vector<string> s(M);
    
    for (int i = 0; i < K; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> s[i];
    }
    
    // word[d[i]] := d[i] を既に使用したかどうか
    unordered_map<string, bool> word;
    for (int i = 0; i < K; ++i) {
        word[d[i]] = false;
    }
    
    // survival[i] := 友達 i が脱落したかどうか
    vector<bool> survival(N, false);

    int now = 0; // 現在のターンが誰なのか
    char last = '\0'; // 前のターンの末尾の文字
    bool last_friend = false; // 前のターンの友達が脱落したかどうか
    
    for (int i = 0; i < M; ++i) {
        // 誰のターンなのかを調べる
        for (int j = 0; j < N; ++j) {
            // 脱落している場合はスキップする
            if (survival[(now + j) % N]) {
                continue;
            }
            // 脱落していない友達を見つけたら for 文を抜ける
            now = (now + j) % N;
            break;
        }
        
        bool check = false; // このターンの友達が脱落するかどうか

        // ルール 1. K 個の単語のいずれかでなければならない
        // ルール 3. 既に発言していた場合は発言禁止
        if (word.find(s[i]) == word.end() || word[s[i]]) {
            check = true;
        }

        // ルール 4. z で終わってはいけない
        if (s[i].back() == 'z') {
            check = true;
        }
        
        // ルール 2. 直前の人の発言の末尾と一致する必要がある
        // 初回のターンは前のプレイヤーがいない
        if (i != 0) {
            // 前のターンに友達が脱落していればルール 2. は適用されない
            if (last != s[i].front() && !last_friend) {
                check = true;
            }
        }
        
        // 末尾の文字
        last = s[i].back();

        // s[i] を使用済みにする
        word[s[i]] = true;

        // このターンに友達が脱落したかどうか（2 ターン目以降のルール 2. で必要）
        if (check) {
            survival[now] = true;
            last_friend = true;
        } else {
            last_friend = false;
        }

        // ターンを進める
        now += 1;
    }

    // 答えを出力する
    int survivors = 0;
    for (int i = 0; i < N; ++i) {
        if (!survival[i]) {
            survivors++;
        }
    }
    cout << survivors << endl;

    for (int i = 0; i < N; ++i) {
        // 脱落している友達は出力しない
        if (!survival[i]) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}