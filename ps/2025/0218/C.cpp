#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int MAXN = 200002;

int p2[MAXN + 1], inv2[MAXN + 1];

int pow(int a, int r) {
    int res = 1;
    while (r) {
        if (r & 1) res = res * a % MOD;
        a = a * a % MOD;
        r >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> c2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        c2[i] = c2[i - 1] + (a[i] == 2 ? 1 : 0);
    }
    vector<int> prefixCount1(n + 1, 0), prefixSumInv(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefixCount1[i] = prefixCount1[i - 1] + (a[i] == 1 ? 1 : 0);
        prefixSumInv[i] = prefixSumInv[i - 1] + ((a[i] == 1) ? inv2[c2[i]] : 0);
        prefixSumInv[i] %= MOD;
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        if (a[j] != 3) continue;
        int alpha = p2[c2[j - 1]];
        int sumInv = prefixSumInv[j - 1];
        int c1 = prefixCount1[j - 1];
        int cur = (alpha % MOD) * (sumInv % MOD) % MOD;
        cur = (cur - c1) % MOD;
        if (cur < 0) cur += MOD;
        ans = (ans + cur) % MOD;
    }
    cout << ans << '\n';
}

// https://codeforces.com/contest/2069/problem/C
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    p2[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
    for (int i = 0; i <= MAXN; i++) {
        inv2[i] = pow(p2[i], MOD - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}