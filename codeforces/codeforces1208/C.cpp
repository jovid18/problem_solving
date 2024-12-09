#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int MAX = 2000000000000;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == 1) {
            if (k == 1)
                cout << 1 << '\n';
            else
                cout << -1 << '\n';
            continue;
        }
        int chk = 1;
        bool isOk = false;
        for (int i = 1; i <= n - 1; ++i) {
            chk *= 2;
            if (chk >= k) {
                isOk = true;
                break;
            }
        }
        if (!isOk) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(n, 0);
        int l = 0, r = n - 1;
        for (int i = 1; i < n; ++i) {
            if (n - i - 1 >= 40) {
                ans[l++] = i;
                continue;
            }
            if ((1LL << (n - i - 1)) >= k) {
                ans[l++] = i;
            } else {
                ans[r--] = i;
                k -= (1LL << (n - i - 1));
            }
        }
        for (auto &e : ans) {
            if (e == 0) e = n;
        }
        for (auto e : ans) cout << e << ' ';
        cout << '\n';
    }
}