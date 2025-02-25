#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int diff = 0, ans_l = 0, ans_r = 0;
    for (int l = 0; l < n; ++l) {
        int nowDiff = 0;
        for (int r = l; r < n; ++r) {
            if (v[l] > v[r]) {
                nowDiff++;
            } else if (v[l] < v[r]) {
                nowDiff--;
            }
            if (nowDiff > diff) {
                diff = nowDiff;
                ans_l = l;
                ans_r = r;
            }
        }
    }
    cout << ans_l + 1 << " " << ans_r + 1 << endl;
}

// https://codeforces.com/contest/2072/problem/D
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}