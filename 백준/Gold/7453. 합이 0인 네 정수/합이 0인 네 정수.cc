#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    vector<int> a, b, c, d, ab, cd;
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(-c[i] - d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int ans = 0;
    for (auto e : ab) {
        ans += upper_bound(cd.begin(), cd.end(), e) - lower_bound(cd.begin(), cd.end(), e);
    }
    cout << ans;
}
