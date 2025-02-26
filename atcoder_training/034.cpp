#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int DP[45];

int fibo(int n) {
    if (DP[n] != -1) {
        return DP[n];
    }
    if (n == 0 || n == 1) {
        return DP[n] = 1;
    }
    return DP[n] = fibo(n - 1) + fibo(n - 2);
}

// https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    memset(DP, -1, sizeof DP);
    cout << fibo(n) << '\n';
}