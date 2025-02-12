#include <bits/stdc++.h>
using namespace std;
#define int long long

bool has7(int n) {
    while (n) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

vector<int> with9 = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999LL};
// https://codeforces.com/contest/2067/problem/C
void solve() {
    int ans = 10;
    int n;
    cin >> n;
    if (has7(n)) {
        cout << 0 << '\n';
        return;
    }
    vector<int> v;
    int ncopy = n;
    while (ncopy) {
        v.push_back(ncopy % 10);
        ncopy /= 10;
    }
    for (auto e : with9) {
        ncopy = n;
        for (int i = 1; i <= 10; ++i) {
            ncopy += e;
            if (has7(ncopy)) {
                ans = min(ans, i);
                break;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}