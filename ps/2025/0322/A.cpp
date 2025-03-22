#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc398/tasks/abc398_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += '-';
    }
    if (n % 2 == 0) {
        ans[n / 2] = ans[n / 2 - 1] = '=';
    } else {
        ans[n / 2] = '=';
    }
    cout << ans;
}