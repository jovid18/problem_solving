#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> v(21);
    auto isIn = [&](int x) { return 0 <= x && x <= 20; };
    v[a[0]] = 1;
    for (int i = 1; i < n - 1; ++i) {
        vector<int> u(21);
        for (int j = 0; j <= 20; j++) {
            if (isIn(j + a[i])) u[j + a[i]] += v[j];
            if (isIn(j - a[i])) u[j - a[i]] += v[j];
        }
        v = u;
    }
    cout << v[a[n - 1]] << '\n';
}