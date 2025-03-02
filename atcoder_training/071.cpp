#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int MOD = 1e9 + 7;
int fast_pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), c(q);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> c[i];
        c[i]--;
    }
    // to_big (i): 0 -> i 비용
    // to_small (i): n - 1 -> i 비용
    vector<int> to_big(n), to_small(n);
    for (int i = 1; i < n; ++i) {
        to_big[i] = to_big[i - 1] + fast_pow(a[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        to_small[i] = to_small[i + 1] + fast_pow(a[i], a[i + 1]);
    }
    int now = 0;
    int ans = 0;
    c.push_back(0);
    for (auto next : c) {
        if (now < next) {
            ans += to_big[next] - to_big[now];
        } else {
            ans += to_small[next] - to_small[now];
        }
        ans = (ans + MOD) % MOD;
        now = next;
    }
    cout << ans << '\n';
}
