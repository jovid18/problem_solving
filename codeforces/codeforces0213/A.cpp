#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int a = 1;
        int b = 1;
        int c = n - a - b;
        if (c > 26) {
            b += c - 26;
            c = 26;
        }
        if (b > 26) {
            a += b - 26;
            b = 26;
        }
        cout << char('a' + a - 1) << char('a' + b - 1) << char('a' + c - 1)
             << '\n';
    }
}