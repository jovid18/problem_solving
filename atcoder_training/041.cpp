#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
struct Clothes {
    int l, r, c;
};
int DP[201][201];

// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // d: day, n: clothes
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    for (int i = 0; i < d; ++i) {
        cin >> t[i];
    }
    vector<Clothes> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].l >> v[i].r >> v[i].c;
    }
    // 전처리
    for (int i = 0; i < n; ++i) {
        if (t[0] < v[i].l || t[0] > v[i].r) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (t[1] < v[j].l || t[1] > v[j].r) {
                continue;
            }
            DP[1][j] = max(DP[1][j], abs(v[j].c - v[i].c));
        }
    }
    for (int i = 2; i < d; ++i) {
        for (int j = 0; j < n; ++j) {
            if (t[i] < v[j].l || t[i] > v[j].r) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (t[i - 1] < v[k].l || t[i - 1] > v[k].r) {
                    continue;
                }
                DP[i][j] = max(DP[i][j], DP[i - 1][k] + abs(v[j].c - v[k].c));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, DP[d - 1][i]);
    }
    cout << ans << '\n';
}