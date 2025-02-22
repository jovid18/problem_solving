#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> b(n - 2);
    for (int i = 0; i < n - 2; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 4; i++) {
        if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

// https://codeforces.com/contest/2069/problem/A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}