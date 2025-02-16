#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int ans = 1LL << 60;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != k) continue;
        int sum = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (cur >= a[i]) {
                    int diff = max(cur + 1 - a[i], 0LL);
                    sum += diff;
                    cur = a[i] + diff;
                }
            }
            cur = max(cur, a[i]);
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}