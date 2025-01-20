#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (auto &i : x) cin >> i;
    sort(x.begin(), x.end());
    int cnt = 0;
    int j = n - 1;
    for (int i = 0; i < n; ++i) {
        while (j > i && x[j] > k - x[i]) --j;
        if (j <= i) break;
        if (x[j] + x[i] == k) {
            cnt++;
            j--;
        }
    }
    cout << cnt << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}