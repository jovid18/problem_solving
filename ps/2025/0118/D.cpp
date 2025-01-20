#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n - 1; ++i) {
        int min_val = min(a[i], a[i + 1]);
        int origai = a[i];
        int origai1 = a[i + 1];
        if (i == 0) {
            a[i] -= min_val;
            a[i + 1] -= min_val;
        } else {
            a[i] -= min_val;
            a[i + 1] -= min_val;
            if (a[i - 1] > a[i] || a[i + 1] > a[i + 2]) {
                a[i] = origai;
                a[i + 1] = origai1;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}