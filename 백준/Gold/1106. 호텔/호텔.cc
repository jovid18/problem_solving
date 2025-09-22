#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int INF = 1LL << 32;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int c, n;
    cin >> c >> n;
    vector<pii> v(n);
    for (auto &e : v) {
        cin >> e.first >> e.second;
    }
    vector<int> costs(c + 101, INF);
    costs[0] = 0;
    for (int i = 1; i <= c + 100; ++i) {
        for (auto [cost, customer] : v) {
            if (i - customer >= 0) {
            }
            costs[i] = min(costs[i], costs[i - customer] + cost);
        }
    }
    int ans = INF;
    for (int i = c; i <= c + 100; ++i) {
        ans = min(ans, costs[i]);
    }
    cout << ans;
}