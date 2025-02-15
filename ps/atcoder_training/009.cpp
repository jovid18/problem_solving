#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n;
    cin >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto init = a[0];
    cin >> n;
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        int dx = b[i].first - init.first;
        int dy = b[i].second - init.second;
        for (int j = 0; j < m; ++j) {
            if (find(b.begin(), b.end(), make_pair(a[j].first + dx, a[j].second + dy)) == b.end()) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << dx << " " << dy << endl;
            return 0;
        }
    }
}