#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

vector<int> get_divisor(int n) {
    vector<int> divisor;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            if (i * i != n) divisor.push_back(n / i);
        }
    }
    return divisor;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}