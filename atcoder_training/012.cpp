#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc002/tasks/abc002_4
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<pii> c(M);
    for (auto &[a, b] : c) {
        cin >> a >> b;
        a--;
        b--;
        if (a > b) swap(a, b);
    }
    sort(c.begin(), c.end());
    int mask = (1 << N) - 1;
    int ans = 0;
    for (int subset_mask = mask; subset_mask; subset_mask = (subset_mask - 1) & mask) {
        bool is_valid = true;
        for (int i = 0; i < N; ++i) {
            if (!is_valid) break;
            if (subset_mask & (1 << i)) {
                for (int j = i + 1; j < N; ++j) {
                    if (!is_valid) break;
                    if (subset_mask & (1 << j)) {
                        if (!binary_search(c.begin(), c.end(), pii(i, j))) {
                            is_valid = false;
                            break;
                        }
                    }
                }
            }
        }
        if (is_valid) {
            ans = max(ans, (int)__builtin_popcount(subset_mask));
        }
    }
    cout << ans << endl;
}