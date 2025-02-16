#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n;
    vector<int> s(n);
    for (auto &x : s) cin >> x;
    cin >> q;
    vector<int> t(q);
    for (auto &x : t) cin >> x;
    sort(s.begin(), s.end());
    int ans = 0;
    for (auto x : t) {
        if (binary_search(s.begin(), s.end(), x)) ans++;
    }
    cout << ans << endl;
}