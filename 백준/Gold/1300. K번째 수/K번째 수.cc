#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, k;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> k;
    int l = 1, r = k, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
            cnt += min(N, m / i);
        if (cnt < k)
            l = m + 1;
        else
            ans = m, r = m - 1;
    }
    cout << ans;
}