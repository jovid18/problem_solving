#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int cnt = 0, val = a[0];
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            if (val != a[i]) {
                vec.push_back({cnt, val});
                cnt = 0;
                val = a[i];
            }
            cnt++;
        }
        if (cnt) vec.push_back({cnt, val});
        sort(vec.begin(), vec.end());
        int ans = vec.size();
        for (auto [cnt, val] : vec) {
            if (k >= cnt) {
                k -= cnt;
                ans--;
            } else {
                break;
            }
        }
        if (ans == 0) ans++;
        cout << ans << '\n';
    }
}