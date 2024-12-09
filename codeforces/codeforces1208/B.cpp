#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
vector<int> ans(1000001, 0);
int solve(int n) {
    if (ans[n] != 0) {
        return ans[n];
    }
    return ans[n] = solve(n % 2 ? (n / 2) : (n / 2) - 1) + 1;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 2;
    ans[4] = 2;
    while (t--) {
        int n;
        cin >> n;
        if (ans[n] != 0) {
            cout << ans[n] << '\n';
            continue;
        }
        solve(n);
        cout << ans[n] << '\n';
    }
}