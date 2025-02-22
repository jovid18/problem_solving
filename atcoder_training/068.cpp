#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<int> prime_factorization(int n) {
    vector<int> prime_factor;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            prime_factor.push_back(i);
            n /= i;
        }
    }
    if (n > 1) prime_factor.push_back(n);
    return prime_factor;
}

// https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> prime_factor = prime_factorization(n);
    cout << n << ":";
    for (auto e : prime_factor) cout << " " << e;
    cout << '\n';
}