#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int MAX = 11;
// chk[i][j] = i번째 스위치가 j번째 전구에 연결되어 있는지 여부
bool chk[MAX][MAX];

// https://atcoder.jp/contests/abc128/tasks/abc128_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        int siz;
        cin >> siz;
        while (siz--) {
            int x;
            cin >> x;
            chk[i][x - 1] = 1;
        }
    }
    for (auto &x : p) cin >> x;
    int mask = (1 << n) - 1;
    int ans = 0;
    for (int subset_mask = mask; subset_mask; subset_mask = (subset_mask - 1) & mask) {
        // 켜진 bulb의 개수
        int sum = 0;
        // bulb 순회
        for (int i = 0; i < m; ++i) {
            int count = 0;
            // switch 순회
            for (int j = 0; j < n; ++j) {
                if ((subset_mask & (1 << j)) && chk[j][i]) {
                    ++count;
                }
            }
            if (count % 2 == p[i]) {
                ++sum;
            }
        }
        if (sum == m) ++ans;
    }
    cout << ans;
}