#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
vector<int> a;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (auto &e : a) {
            cin >> e;
        }
        bool allsame = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] != a[i])
                allsame = false;
        }
        if (allsame) {
            cout << 0 << '\n';
            continue;
        }
        int ans1 = 1;
        int ans2 = 1;
        for (int s = 0; s < n - 1; ++s) {
            if (a[s] == a[s + 1])
                ans1++;
            else {
                break;
            }
        }
        for (int f = n - 1; f >= 1; --f) {
            if (a[f] == a[f - 1])
                ans2++;
            else {
                break;
            }
        }
        // cout << n << " " << ans1 << " " << ans2 << '\n';
        if (a[0] == a[n - 1]) {
            cout << n - ans1 - ans2 << '\n';
        } else {
            cout << min(n - ans1, n - ans2) << '\n';
        }
    }
}