#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_element(int mask, int element) {
    // Check if element is in mask
    return mask & (1 << element);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool is_allowed = true;
        for (int j = 0; j < 32; ++j) {
            if (is_element(i, j) && !is_element(k, j)) {
                is_allowed = false;
                break;
            }
        }
        if (!is_allowed) {
            break;
        }
        ans.push_back(i);
    }
    int now = 0;
    for (auto x : ans) {
        now |= x;
    }
    if (now != k && ans.size() == n && ans.size() > 0) {
        ans.pop_back();
    }
    while (ans.size() < n) {
        ans.push_back(k);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

// https://codeforces.com/contest/2072/problem/C
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}