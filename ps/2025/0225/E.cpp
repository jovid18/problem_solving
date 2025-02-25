#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<int> comb;

void solve() {
    int k;
    cin >> k;
    if (k == 0) {
        cout << 0 << endl;
        return;
    }
    int ans = 0, x = 0, y = 0;
    bool flag = false;
    bool isFirst = true;
    vector<pii> res;
    while (k) {
        int idx = upper_bound(comb.begin(), comb.end(), k) - comb.begin() - 1;
        k -= comb[idx];
        if (isFirst) {
            idx++;
            isFirst = false;
        }
        for (int i = 0; i < idx; ++i) {
            flag ? y++ : x++;
            res.push_back({x, y});
        }
        flag = !flag;
    }
    cout << res.size() << endl;
    for (auto [x, y] : res) {
        cout << x << " " << y << endl;
    }
}

// https://codeforces.com/contest/2072/problem/E
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0;; ++i) {
        comb.push_back(i * (i + 1) / 2);
        if (i * (i + 1) / 2 > 2e5) break;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}