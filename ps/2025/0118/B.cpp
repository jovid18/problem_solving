#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    v.resize(n);
    for (auto &e : v) {
        e.resize(m);
        for (auto &f : e) {
            cin >> f;
        }
        sort(e.begin(), e.end(), greater<int>());
    }
    auto cop = v;
    vector<int> ans;
    for (int x = 0; x < n; ++x) {
        for (int i = 0; i < n; ++i) {
            if (v[i].back() == x) {
                ans.push_back(i + 1);
                v[i].pop_back();
                break;
            }
        }
    }
    for (auto e : cop) {
        int x = e[0] % n;
        for (auto f : e) {
            if (f % n != x) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (auto &e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}