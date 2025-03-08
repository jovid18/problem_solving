#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc396/tasks/abc396_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> b(n), w(m);
    for (auto &i : b) cin >> i;
    for (auto &i : w) cin >> i;
    int b_more_than_0 = 0, w_more_than_0 = 0;
    int b_sum = 0, w_sum = 0;
    for (auto i : b) {
        if (i >= 0) {
            b_sum += i;
            b_more_than_0++;
        }
    }
    for (auto i : w) {
        if (i >= 0) {
            w_sum += i;
            w_more_than_0++;
        }
    }
    if (b_more_than_0 >= w_more_than_0) {
        cout << b_sum + w_sum;
        return 0;
    }
    sort(b.begin(), b.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());
    int ans = 0;
    b_sum = 0, w_sum = 0;
    for (int i = 0; i < min(n, m); i++) {
        b_sum += b[i];
        w_sum += w[i];
        ans = max(ans, b_sum + w_sum);
    }
    cout << ans;
}