#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    vector<int> b(q);
    for (auto &x : b) cin >> x;
    set<int> s;
    int mask = (1LL << n) - 1;
    for (int subset_mask = mask; subset_mask; subset_mask = (subset_mask - 1) & mask) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (subset_mask & (1LL << i)) {
                sum += a[i];
            }
        }
        s.insert(sum);
    }
    for (auto x : b) {
        cout << (s.count(x) ? "yes" : "no") << '\n';
    }
}