#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAX = 1e5 + 1;
vector<bool> isPrime(MAX, 1);
void setPrimes() {
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int pow(int n, int x) {
    int ans = 1;
    for (int i = 0; i < x; ++i) {
        ans = (ans * n) % MOD;
    }
    return ans % MOD;
}

void solve() {
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= k; ++i) {
        if (i == 1) {
            cout << n << ' ';
            continue;
        } else if (isPrime[i]) {
            int n2 = pow(n, 2);
            int n1 = pow(n, 1);
            cout << ((n2 + n1) / 2) % MOD << ' ';
            continue;
        } else {
            cout << " - ";
        }
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    setPrimes();
    while (t--) {
        solve();
    }
}