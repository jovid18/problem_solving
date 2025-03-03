#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int MOD = 1000000007;

// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> c{0, 0, 0};
    int ans = 1;
    for (auto e : a) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (c[i] == e) cnt++;
        }
        ans = (ans * cnt) % MOD;
        for (int i = 0; i < 3; i++) {
            if (c[i] == e) {
                c[i]++;
                break;
            }
        }
    }
    cout << ans << '\n';
}