#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int cnt(int a, int b, int x, int y) {
    if (a == 0) {
        if (b >= x && b <= y) return -1;
        return 0;
    }
    int minI = ceil((double)(x - b) / a);
    int maxI = floor((double)(y - b) / a);
    if (minI > maxI) return 0;
    return maxI - minI + 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x /= 2;
    }
    int LCM = 1;
    for (int x : a) LCM = lcm(LCM, x);
    for (int x : a) {
        if ((LCM / x) % 2 == 0) {
            cout << 0;
            return 0;
        }
    }
    cout << cnt(2 * LCM, LCM, 1, m);
}