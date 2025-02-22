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

// https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    cout << fast_pow(n, m) << '\n';
}