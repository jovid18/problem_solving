#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    bool ok = 0;
    if (a1 * a2 == a3) {
        ok = 1;
    }
    if (a1 == a2 * a3) {
        ok = 1;
    }
    if (a1 * a3 == a2) {
        ok = 1;
    }
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
}