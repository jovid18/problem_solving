#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(0);
    v.push_back(d);
    vector<int> order(m);
    for (int i = 0; i < m; i++) cin >> order[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x = order[i];
        if (x == 0 || x == d) continue;
        auto it = lower_bound(v.begin(), v.end(), x);
        ans += min(*it - x, x - *(it - 1));
    }
    cout << ans << endl;
}