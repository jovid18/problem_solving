#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int MAXN = 2e5 + 5;
vector<bool> prime_number(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = 2; j * i <= n; j++) is_prime[i * j] = false;
        }
    }
    return is_prime;
}
vector<int> v;

int countGreaterThan(int x) { return v.end() - upper_bound(v.begin(), v.end(), x); }

int countGreaterEqual(int x) { return v.end() - lower_bound(v.begin(), v.end(), x); }

// https://atcoder.jp/contests/abc084/tasks/abc084_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    auto is_prime = prime_number(MAXN);
    for (int i = 1; i <= MAXN; i++) {
        if (i % 2 == 0) continue;
        if (is_prime[i] && is_prime[(i + 1) / 2]) v.push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = countGreaterEqual(l) - countGreaterThan(r);
        cout << ans << '\n';
    }
}