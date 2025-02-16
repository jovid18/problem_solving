#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    string s;
    cin >> n >> s;
    // s는 0으로만
    int ans = 0;
    char now = s[0];
    for (int i = 0; i < n; i++) {
        if (s[i] != now) {
            ans++;
        }
        now = s[i];
    }
    if (s[0] == '1') ans++;
    cout << ans << '\n';
}

// https://codeforces.com/contest/2064/problem/A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}