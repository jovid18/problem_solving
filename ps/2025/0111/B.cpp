#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int N, D;
vector<pii> v;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> D;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 1; i <= D; ++i) {
        int ans = 0;
        for (auto [x, y] : v) {
            ans = max(ans, (y + i) * x);
        }
        cout << ans << " \n";
    }
}