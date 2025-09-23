#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;
int dp[51][51][51][2];
string a, b;

int sol(int al, int ar, int bl, bool rev) {
    if (al > ar) return 0;
    int ret = INF - 1;
    int br = ar + bl - al;
    if (br < 0 || br >= a.size()) return INF;
    if (dp[al][ar][bl][rev] != INF) return dp[al][ar][bl][rev];
    if (!rev) {
        if (a[al] == b[bl]) ret = min(ret, sol(al + 1, ar, bl + 1, rev));
        if (a[ar] == b[br]) ret = min(ret, sol(al, ar - 1, bl, rev));
    } else {
        if (a[al] == b[br]) ret = min(ret, sol(al + 1, ar, bl, rev));
        if (a[ar] == b[bl]) ret = min(ret, sol(al, ar - 1, bl + 1, rev));
    }

    if (!rev) {
        if (a[al] == b[br]) ret = min(ret, 1 + sol(al + 1, ar, bl, !rev));
        if (a[ar] == b[bl]) ret = min(ret, 1 + sol(al, ar - 1, bl + 1, !rev));
    } else {
        if (a[al] == b[bl]) ret = min(ret, 1 + sol(al + 1, ar, bl + 1, !rev));
        if (a[ar] == b[br]) ret = min(ret, 1 + sol(al, ar - 1, bl, !rev));
    }

    return dp[al][ar][bl][rev] = ret;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> a >> b;
    int n = a.size();
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '0') cnt++;
            if (b[i] == '0') cnt--;
        }
        if (cnt != 0) {
            cout << -1;
            return 0;
        }
    }
    {
        if (a == b) {
            cout << 0;
            return 0;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    int ans = sol(0, n - 1, 0, false);
    if (ans >= INF / 2)
        cout << -1;
    else
        cout << ans;
}