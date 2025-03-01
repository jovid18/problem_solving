#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N;
    cin >> N;
    if (N % 3 != 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

// https://codeforces.com/contest/2071/problem/A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}