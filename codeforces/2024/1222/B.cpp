#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int ans = 0;
        int sum = a + b + c;
        ans += n / sum;
        int total = ans * sum;
        ans *= 3;
        if (total < n) {
            ans++;
            total += a;
        }
        if (total < n) {
            ans++;
            total += b;
        }
        if (total < n) {
            ans++;
            total += c;
        }
        cout << ans << '\n';
    }
}