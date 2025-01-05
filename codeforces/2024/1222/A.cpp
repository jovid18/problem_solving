#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a, b;
        a.resize(n);
        b.resize(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > b[i + 1]) {
                ans += a[i] - b[i + 1];
            }
        }
        ans += a[n - 1];
        cout << ans << '\n';
    }
}