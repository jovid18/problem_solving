#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        int n, x;
        cin >> n >> x;
        if (n == 0 && x == 0) break;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    if (i + j + k == x) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}