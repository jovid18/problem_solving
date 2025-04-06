#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc400/tasks/abc400_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int max_n = 1e6 + 1;
    vector<int> v(max_n);
    for (int i = 2; i < max_n; ++i) {
        if (v[i]) continue;
        for (int j = i; j < max_n; j += i) {
            v[j]++;
        }
    }
    vector<int> s;
    for (int i = 1; i < max_n; ++i) {
        if (v[i] == 2) {
            s.push_back(i * i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << *prev(upper_bound(s.begin(), s.end(), x)) << '\n';
    }
}