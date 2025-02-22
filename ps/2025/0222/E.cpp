#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int INF = 1LL << 60;

// https://atcoder.jp/contests/abc394/tasks/abc394_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    // out[i][c] = 정점 i에서 레이블 c로 갈 수 있는 j들의 목록
    // in[j][c]  = 정점 j로 레이블 c로 들어올 수 있는 i들의 목록
    vector<vector<vector<int>>> in(n, vector<vector<int>>(26)), out(n, vector<vector<int>>(26));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            g[i][j] = c;
            if (c != '-') {
                in[j][c - 'a'].push_back(i);
                out[i][c - 'a'].push_back(j);
            }
        }
    }
    vector<vector<int>> ans(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        ans[i][i] = min(ans[i][i], 0LL);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != '-') {
                ans[i][j] = min(ans[i][j], 1LL);
            }
        }
    }

    bool isChanged = true;
    while (isChanged) {
        isChanged = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // i -> j
                for (int c = 0; c < 26; ++c) {
                    for (auto u : in[i][c]) {
                        for (auto v : out[j][c]) {
                            // u -> i -> j -> v
                            int before = ans[u][v];
                            int after = ans[i][j] + 2;
                            if (before > after) {
                                ans[u][v] = after;
                                isChanged = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (auto e : ans) {
        for (auto f : e) {
            if (f == INF)
                cout << -1 << ' ';
            else
                cout << f << ' ';
        }
        cout << '\n';
    }
}