#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<bool> b(n + 1);
    cout << n - m << '\n';
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!b[i]) cout << i << ' ';
    }
}