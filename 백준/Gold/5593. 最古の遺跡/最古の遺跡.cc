#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define xx first
#define yy second
const int MAX = 5005;
int dist(pii a, pii b) { return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); }
bool chk[MAX][MAX];
bool is_in(pii p) { return 0 <= p.xx && p.xx < MAX && 0 <= p.yy && p.yy < MAX && chk[p.xx][p.yy]; }

// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &i : v) {
        cin >> i.first >> i.second;
        chk[i.first][i.second] = 1;
    }
    if (n <= 3) {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        pii p1 = v[i];
        for (int j = i + 1; j < n; ++j) {
            pii p2 = v[j];
            int dx = p2.first - p1.first;
            int dy = p1.second - p2.second;
            pii p3 = {p1.first + dy, p1.second + dx};
            pii p4 = {p2.first + dy, p2.second + dx};
            if (is_in(p3) && is_in(p4)) {
                ans = max(ans, dist(p1, p2));
            }
            p3 = {p1.first - dy, p1.second - dx};
            p4 = {p2.first - dy, p2.second - dx};
            if (is_in(p3) && is_in(p4)) {
                ans = max(ans, dist(p1, p2));
            }
        }
    }
    cout << ans << endl;
}