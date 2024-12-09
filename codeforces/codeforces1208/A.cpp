#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        v.resize(n);
        for (auto &e : v) cin >> e;
        bool isAWin = false;
        int winNum = 0;
        for (int i = 0; i < n; ++i) {
            int first = v[i];
            int thisTurnAWin = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int second = v[j];
                if (abs(first - second) % k == 0) {
                    thisTurnAWin = false;
                    break;
                }
            }
            if (thisTurnAWin) {
                isAWin = thisTurnAWin;
                winNum = i + 1;
                break;
            }
        }
        cout << (isAWin ? "YES" : "NO") << '\n';
        if (isAWin) cout << winNum << '\n';
    }
}