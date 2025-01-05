#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;

int t;
int n, x, y;
vector<int> a;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        map<pii, int> m;
        cin >> n >> x >> y;
        a.resize(n);
        int cnt = 0;
        for (auto &e : a) {
            cin >> e;
        }
        for (auto e : a) {
            pii key = {e % x, e % y};
            // cout << key.first << " " << key.second << '\n';
            cnt += m[{(x - e % x) % x, e % y}];

            if (m.find(key) != m.end()) {
                // cout << "1번케이스" << '\n';
                m[key]++;
            } else {
                // cout << "2번케이스" << '\n';
                m[key] = 1;
            }
        }
        cout << cnt << '\n';
    }
}
