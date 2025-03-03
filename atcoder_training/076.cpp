#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    for (int k = 1; k <= n; ++k) {
        int ans = 0;
        for (int i = 0; i + k <= n; ++i) {
            ans = max(ans, pref[i + k] - pref[i]);
        }
        cout << ans << '\n';
    }
}