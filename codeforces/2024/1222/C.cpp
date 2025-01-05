#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a, b;
        a.resize(m);
        b.resize(k);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        string ans;
        if (n == k) {
            ans = string(m, '1');
            cout << ans << '\n';
            continue;
        }
        if (n - 1 == k) {
            ans = string(m, '0');
            vector<bool> chk(n + 1, 0);
            for (auto i : b) {
                chk[i] = 1;
            }
            for (int i = 0; i < m; ++i) {
                if (!chk[a[i]]) ans[i] = '1';
            }
            cout << ans << '\n';
            continue;
        }
        ans = string(m, '0');
        cout << ans << '\n';
    }
}