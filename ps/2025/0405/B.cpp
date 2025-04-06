#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int INF = 1e9;

// https://atcoder.jp/contests/abc400/tasks/abc400_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int cur = 1, sum = 0;
    for (int i = 0; i <= m; ++i) {
        sum += cur;
        if (sum > INF) {
            cout << "inf";
            return 0;
        }
        cur *= n;
    }
    cout << sum;
}