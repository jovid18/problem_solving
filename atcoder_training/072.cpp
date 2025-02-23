#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int MOD = 1e9 + 7;

// 고속 거듭제곱
int fast_pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

// 역원 구하기 a^-1 mod p = a^(p-2) mod p
int inverse(int a) { return fast_pow(a, MOD - 2); }

// nCk
int comb(int n, int k) {
    int num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * (n - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    return num * inverse(den) % MOD;
}

// https://atcoder.jp/contests/abc034/tasks/abc034_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h;
    cin >> w >> h;
    w--;
    h--;
    cout << comb(w + h, w);
}